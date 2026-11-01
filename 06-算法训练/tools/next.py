#!/usr/bin/env python3
"""根据当前阶段和进度，推荐下一道题，并记录练习结果。"""
from __future__ import annotations

import argparse
import json
import sys
from datetime import date, timedelta
from pathlib import Path

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8")
    sys.stderr.reconfigure(encoding="utf-8")

ROOT = Path(__file__).resolve().parents[1]
CURRICULUM_PATH = ROOT / "curriculum.json"
PROGRESS_PATH = ROOT / "progress.json"
STATEMENTS = ROOT / "bank" / "statements" / "luogu"


def load_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def save_progress(progress: dict) -> None:
    PROGRESS_PATH.write_text(
        json.dumps(progress, ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8",
        newline="\n",
    )


def get_stage(curriculum: dict) -> dict:
    for stage in curriculum.get("stages", []):
        if stage.get("id") == curriculum.get("current_stage"):
            return stage
    raise RuntimeError(f"找不到当前阶段：{curriculum.get('current_stage')}")


def problem_key(raw: str) -> str:
    return raw if ":" in raw else f"luogu:{raw.upper()}"


def problem_id(raw: str) -> str:
    return raw.split(":", 1)[1]


def cached(raw: str) -> Path:
    return STATEMENTS / f"{problem_id(raw).upper()}.md"


def progress_entry(progress: dict, key: str) -> dict:
    return progress.setdefault("problems", {}).setdefault(key, {
        "status": "todo",
        "attempts": 0,
        "independent": False,
        "last_attempt": None,
        "review_due": None,
        "error": "",
        "edge_cases": "",
        "complexity": "",
    })


def command_next(_: argparse.Namespace) -> int:
    curriculum = load_json(CURRICULUM_PATH)
    progress = load_json(PROGRESS_PATH)
    stage = get_stage(curriculum)
    problems = stage.get("problem_ids", [])

    print(f"当前阶段：{stage.get('title')} [{stage.get('id')}]")

    # 主线的“知识门槛”没有过，不推荐 OJ 题。算法练习不能反过来抢主线。
    if stage.get("mainline_gate") and not stage.get("gate_completed", False):
        gate = stage.get("gate", {})
        print("当前先过主线门槛，不安排新题。")
        print(gate.get("task", "完成本阶段的知识与代码验收。"))
        if gate.get("file"):
            print(f"文件：{gate['file']}")
        for item in gate.get("criteria", []):
            print(f"  - {item}")
        return 0

    if not problems:
        print("本阶段没有 OJ 题。下一步是阶段项目：")
        print(stage.get("project_gate", "完成本阶段项目。"))
        return 0

    today = date.today()

    # 到期的题优先重做；没到期则继续当前阶段的新题。
    due_reviews = []
    for raw in problems:
        key = problem_key(raw)
        entry = progress_entry(progress, key)
        review_due = entry.get("review_due")
        if entry.get("status") == "passed" and review_due:
            try:
                due_date = date.fromisoformat(review_due)
            except ValueError:
                due_date = today
            if due_date <= today:
                due_reviews.append((due_date, key))

    if due_reviews:
        _, key = min(due_reviews)
        print(f"今天先重做：{key}")
        print(f"题面：{cached(key)}")
        print("要求：从空文件重写，不看上一次代码。")
        print("重做成功后：")
        print(f"python tools\next.py record {problem_id(key)} --status mastered --independent")
        return 0

    for raw in problems:
        key = problem_key(raw)
        entry = progress_entry(progress, key)
        if entry.get("status") not in {"passed", "mastered"}:
            print(f"下一题：{key}")
            statement = cached(key)
            if statement.exists():
                print(f"题面：{statement}")
            else:
                print(f"题面还没缓存，先运行：python tools\\luogu.py fetch {problem_id(key)}")
            print("做完并测试后记录：")
            print(f"python tools\\next.py record {problem_id(key)} --status passed --independent")
            return 0

    print("这一阶段的题已经全部通过。")
    print("下一步不是换新题，而是完成阶段项目：")
    print(stage.get("project_gate", "完成本阶段项目。"))
    return 0


def command_record(args: argparse.Namespace) -> int:
    key = problem_key(args.pid)
    curriculum = load_json(CURRICULUM_PATH)
    stage = get_stage(curriculum)
    allowed = {problem_key(item) for item in stage.get("problem_ids", [])}
    if key not in allowed:
        raise RuntimeError(f"{key} 不在当前阶段 {stage.get('id')} 的题目列表中")

    progress = load_json(PROGRESS_PATH)
    entry = progress_entry(progress, key)
    entry["status"] = args.status
    entry["attempts"] = int(entry.get("attempts", 0)) + 1
    entry["independent"] = bool(args.independent)
    entry["last_attempt"] = date.today().isoformat()
    entry["error"] = args.error or ""
    entry["edge_cases"] = args.edge_cases or ""
    entry["complexity"] = args.complexity or ""

    if args.status == "passed":
        policy = curriculum.get("scheduling_policy", {})
        interval = int(policy.get("review_interval_days", 2))
        entry["review_due"] = (date.today() + timedelta(days=interval)).isoformat()
    elif args.status == "mastered":
        entry["review_due"] = None
    elif args.status == "review_due":
        entry["review_due"] = date.today().isoformat()

    progress["updated_at"] = date.today().isoformat()
    save_progress(progress)
    print(f"已记录 {key}：{args.status}")
    if args.status == "passed":
        print(f"两天后重做：{entry['review_due']}")
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="算法训练调度器")
    subparsers = parser.add_subparsers(dest="command", required=True)

    nxt = subparsers.add_parser("next", help="推荐当前阶段下一道题")
    nxt.set_defaults(func=command_next)

    record = subparsers.add_parser("record", help="记录一次练习结果")
    record.add_argument("pid", help="题号，例如 B2125")
    record.add_argument("--status", required=True, choices=["attempted", "passed", "mastered", "review_due"])
    record.add_argument("--independent", action="store_true", help="是否独立完成")
    record.add_argument("--error", default="", help="主要错误或卡点")
    record.add_argument("--edge-cases", dest="edge_cases", default="", help="漏掉/补上的边界")
    record.add_argument("--complexity", default="", help="时间和空间复杂度")
    record.set_defaults(func=command_record)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    try:
        return args.func(args)
    except Exception as exc:
        print(f"错误：{exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
