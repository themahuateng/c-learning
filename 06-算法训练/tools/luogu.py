#!/usr/bin/env python3
"""按需抓取洛谷公开题面，供个人离线学习使用。

只抓题面、样例和限制，不抓题解，不抓他人代码。
"""
from __future__ import annotations

import argparse
import http.cookiejar
import json
import re
import sys
import time
import urllib.error
import urllib.request
from html import unescape
from html.parser import HTMLParser
from pathlib import Path

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8")
    sys.stderr.reconfigure(encoding="utf-8")

ROOT = Path(__file__).resolve().parents[1]
CURRICULUM_PATH = ROOT / "curriculum.json"
CACHE_DIR = ROOT / "bank" / "statements" / "luogu"
BASE_URL = "https://www.luogu.com.cn/problem/"
LAST_REQUEST_AT = 0.0

DIFFICULTY = {
    0: "暂无评定",
    1: "入门",
    2: "普及−",
    3: "普及/提高−",
    4: "普及+/提高",
    5: "提高+/省选−",
    6: "省选/NOI−",
    7: "NOI/NOI+/CTSC",
}

TAGS = {
    2: "字符串",
    45: "二分",
    54: "递归",
    113: "排序",
    287: "栈",
    288: "队列",
    345: "双指针",
    356: "数组",
    357: "模拟",
    358: "结构体",
    359: "函数与递归",
    360: "链表",
}


class ProblemParseError(RuntimeError):
    pass


class MarkdownHTMLParser(HTMLParser):
    """把洛谷题面中的常见 HTML 转成可读的纯文本 Markdown。"""

    BLOCK_TAGS = {
        "p", "div", "section", "article", "blockquote", "pre",
        "h1", "h2", "h3", "h4", "h5", "h6", "table", "tr",
    }

    def __init__(self) -> None:
        super().__init__(convert_charrefs=True)
        self.parts: list[str] = []
        self.in_pre = False
        self.in_code = False

    def handle_starttag(self, tag: str, attrs: list[tuple[str, str | None]]) -> None:
        tag = tag.lower()
        if tag == "br":
            self.parts.append("\n")
        elif tag == "li":
            self.parts.append("\n- ")
        elif tag in self.BLOCK_TAGS:
            self.parts.append("\n")
        elif tag == "pre":
            self.in_pre = True
            self.parts.append("\n```\n")
        elif tag == "code":
            self.in_code = True
            if not self.in_pre:
                self.parts.append("`")

    def handle_endtag(self, tag: str) -> None:
        tag = tag.lower()
        if tag in self.BLOCK_TAGS:
            self.parts.append("\n")
        elif tag == "pre":
            self.parts.append("\n```\n")
            self.in_pre = False
        elif tag == "code":
            if not self.in_pre:
                self.parts.append("`")
            self.in_code = False
        elif tag == "li":
            self.parts.append("\n")

    def handle_data(self, data: str) -> None:
        self.parts.append(data)

    def markdown(self) -> str:
        text = "".join(self.parts).replace("\r\n", "\n").replace("\r", "\n")
        text = re.sub(r"[ \t]+\n", "\n", text)
        text = re.sub(r"\n{3,}", "\n\n", text)
        return text.strip()


def html_to_markdown(value: str | None) -> str:
    if not value:
        return ""
    parser = MarkdownHTMLParser()
    parser.feed(unescape(value))
    parser.close()
    return parser.markdown()


def _request(url: str) -> str:
    global LAST_REQUEST_AT
    wait = 1.0 - (time.monotonic() - LAST_REQUEST_AT)
    if wait > 0:
        time.sleep(wait)

    cookie_jar = http.cookiejar.CookieJar()
    opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie_jar))
    request = urllib.request.Request(
        url,
        headers={
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                          "AppleWebKit/537.36 (KHTML, like Gecko) "
                          "Chrome/120.0 Safari/537.36",
            "Accept-Language": "zh-CN,zh;q=0.9",
            "Accept": "text/html,application/xhtml+xml",
        },
    )

    last_error: Exception | None = None
    for attempt in range(3):
        try:
            with opener.open(request, timeout=25) as response:
                charset = response.headers.get_content_charset() or "utf-8"
                text = response.read().decode(charset, "replace")
                LAST_REQUEST_AT = time.monotonic()
                return text
        except (urllib.error.URLError, TimeoutError, OSError) as exc:
            last_error = exc
            if attempt < 2:
                time.sleep(2 * (attempt + 1))
    raise RuntimeError(f"请求失败：{url}\n最后错误：{last_error}")


def extract_problem(pid: str) -> dict:
    pid = pid.strip().upper()
    if not re.fullmatch(r"[A-Z]+\d+", pid):
        raise ValueError("题号格式应类似 B2125、P1001")

    html = _request(BASE_URL + pid)
    match = re.search(
        r'<script[^>]+id=["\']lentille-context["\'][^>]*>(.*?)</script>',
        html,
        flags=re.IGNORECASE | re.DOTALL,
    )
    if not match:
        raise ProblemParseError("页面中没有找到 lentille-context，可能被登录/风控页替换")

    try:
        context = json.loads(match.group(1))
        problem = context["data"]["problem"]
    except (json.JSONDecodeError, KeyError, TypeError) as exc:
        raise ProblemParseError(f"题面 JSON 解析失败：{exc}") from exc

    if not problem.get("content") and not problem.get("contenu"):
        raise ProblemParseError("页面没有返回题目正文")

    content = problem.get("contenu") or problem.get("content") or {}
    problem = dict(problem)
    problem["content"] = content
    return problem


def markdown_for(problem: dict) -> str:
    pid = str(problem.get("pid", "")).strip()
    content = problem.get("content", {}) or {}
    title = content.get("name") or problem.get("name") or pid
    difficulty = DIFFICULTY.get(problem.get("difficulty"), "未知")
    tags = "、".join(TAGS.get(tag, f"标签{tag}") for tag in problem.get("tags", [])) or "无"
    limits = problem.get("limits", {}) or {}
    time_limits = limits.get("time") or []
    memory_limits = limits.get("memory") or []

    lines = [
        f"# {pid} {title}",
        "",
        f"- 来源：{BASE_URL}{pid}",
        f"- 难度：{difficulty}",
        f"- 标签：{tags}",
    ]
    if time_limits:
        lines.append(f"- 时间限制：{time_limits[0]} ms")
    if memory_limits:
        lines.append(f"- 内存限制：{memory_limits[0]} KB")

    sections = [
        ("题目背景", "background"),
        ("题目描述", "description"),
        ("输入格式", "formatI"),
        ("输出格式", "formatO"),
        ("提示", "hint"),
    ]
    for heading, key in sections:
        body = html_to_markdown(content.get(key))
        if body:
            lines.extend(["", f"## {heading}", "", body])

    samples = problem.get("samples") or []
    if samples:
        lines.extend(["", "## 样例", ""])
        for index, sample in enumerate(samples, 1):
            if not isinstance(sample, (list, tuple)) or len(sample) < 2:
                continue
            lines.extend([f"### 样例 {index}", "", "输入：", "```text", str(sample[0]), "```", "", "输出：", "```text", str(sample[1]), "```"])

    lines.extend(["", "---", "", "本文件仅缓存公开题面，供个人离线学习；不包含题解或他人代码。", ""])
    return "\n".join(lines)


def load_curriculum() -> dict:
    return json.loads(CURRICULUM_PATH.read_text(encoding="utf-8"))


def current_stage(curriculum: dict) -> dict:
    stage_id = curriculum.get("current_stage")
    for stage in curriculum.get("stages", []):
        if stage.get("id") == stage_id:
            return stage
    raise RuntimeError(f"找不到当前阶段：{stage_id}")


def cached_path(pid: str) -> Path:
    return CACHE_DIR / f"{pid.upper()}.md"


def fetch_one(pid: str, force: bool) -> Path:
    pid = pid.strip().upper()
    output = cached_path(pid)
    if output.exists() and not force:
        print(f"已缓存：{output}")
        return output
    print(f"正在抓取 {pid} ...")
    problem = extract_problem(pid)
    CACHE_DIR.mkdir(parents=True, exist_ok=True)
    output.write_text(markdown_for(problem), encoding="utf-8", newline="\n")
    print(f"已保存：{output}")
    return output


def parse_problem_ids(stage: dict) -> list[str]:
    result = []
    for item in stage.get("problem_ids", []):
        if str(item).startswith("luogu:"):
            result.append(str(item).split(":", 1)[1])
    return result


def command_fetch(args: argparse.Namespace) -> int:
    fetch_one(args.pid, args.force)
    return 0


def command_list(args: argparse.Namespace) -> int:
    curriculum = load_curriculum()
    if args.stage:
        stage = next((s for s in curriculum.get("stages", []) if s.get("id") == args.stage), None)
        if stage is None:
            raise RuntimeError(f"未知阶段：{args.stage}")
    else:
        stage = current_stage(curriculum)

    ids = parse_problem_ids(stage)
    print(f"阶段：{stage.get('title')} [{stage.get('id')}]")
    if not ids:
        print("这个阶段没有配置洛谷题，必须完成阶段项目。")
        return 0
    for pid in ids:
        state = "已缓存" if cached_path(pid).exists() else "未缓存"
        print(f"  {pid}  {state}")
    print("\n抓取一题：python tools\\luogu.py fetch B2125")
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="按需缓存洛谷公开题面")
    subparsers = parser.add_subparsers(dest="command", required=True)

    fetch = subparsers.add_parser("fetch", help="抓取一个题面")
    fetch.add_argument("pid", help="洛谷题号，例如 B2125 或 P1001")
    fetch.add_argument("--force", action="store_true", help="覆盖已有缓存")
    fetch.set_defaults(func=command_fetch)

    listing = subparsers.add_parser("list", help="列出当前阶段或指定阶段的题")
    listing.add_argument("--stage", help="阶段 id，不填则使用 curriculum.json 的 current_stage")
    listing.set_defaults(func=command_list)
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()
    try:
        return args.func(args)
    except Exception as exc:
        print(f"错误：{exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
