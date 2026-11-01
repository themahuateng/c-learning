# 算法训练系统

这是 C 主线的**练习层**，不是第二条学习线。

主线以 `D:\C-Learning\04-学习文档\主线.md` 为准。算法题只服务当前正在学的 C 知识，不能反过来抢主线位置。

## 一条主线

```text
结构体验收
    ↓
链表
    ↓
栈与队列
    ↓
文件读写 + 综合项目
    ↓
C++ / 数据结构 / 系统与硬件
```

结构体验收已经通过：

```text
D:\C-Learning\03-C练习\lesson13-structs\student-array-review.c
```

`gcc -std=c17 -Wall -Wextra` 通过，`n=1`、降序、升序、全相同四组测试均通过。

当前进入链表第一关：

```text
D:\C-Learning\03-C练习\lesson14-linked-list\01-node-basics.c
```

先完成两个节点的连接、遍历和释放；不先刷链表题。

## 算法练习怎么插进去

每学完一个 C 知识点，只做：

```text
基础实现 → 1 道小型应用题 → 边界测试 → 两天后重做
```

不是每学一个语法就开一个新的算法阶段。

例如：

- 结构体验收后：最多做 1 道结构体应用题，然后进链表。
- 链表基础完成后：先写三节点建链、遍历、插入、删除，再做链表题。
- 栈和队列完成后：先写数组版和链表版，再做应用题。
- 二分、双指针、递归：作为 20～30 分钟小练习穿插，不单独卡住链表主线。

## 每次练习流程

1. 先读当前 C 主线任务，不先看题号。
2. 完成最小可运行版本。
3. 通过 `gcc -std=c17 -Wall -Wextra`。
4. 自己构造至少 3 组测试：最小规模、极端值、重复或逆序。
5. 能说清时间复杂度和关键边界。
6. 两天后从空文件重做，而不是只看旧代码。

## 目录

```text
curriculum.json      主线阶段和练习层配置
progress.json        每题完成情况、错因和复习日期
bank/statements/     按需缓存公开题面，不提交 Git
solutions/           自己写的代码
records/             测试和复盘记录
tools/luogu.py       抓取公开题面，不抓题解
tools/next.py        先检查主线门槛，再过关后推荐练习
```

## 命令

```powershell
cd D:\C-Learning\06-算法训练

# 看当前该做什么；如果主线门槛没过，它不会给你推新题
python tools\next.py next

# 按需抓题面
python tools\luogu.py fetch B2125

# 练习通过后记录
python tools\next.py record B2125 --status passed --independent
```

## 不只洛谷，也不只 C

当前阶段使用 C + 洛谷，因为要练完整输入输出、结构体、指针和手动内存管理。

后面的切换有明确条件：

- 链表、栈、队列基础完成后：LeetCode 练 C++/Python 的函数级算法；
- C 综合项目完成后：系统学习 C++、STL、RAII；
- 进入 AI 与数据处理后：Python + 测试、numpy/pandas；
- 进入系统与硬件后：嵌入式 C、汇编、RTOS、Verilog；
- 基础和复杂度稳定后：Codeforces / AtCoder 做限时训练。

不是所有题重复刷三种语言，只选 3～5 道代表题跨语言对照。题面只作个人离线缓存，不抓题解，不复制他人代码。
