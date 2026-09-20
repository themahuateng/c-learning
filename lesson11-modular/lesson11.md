# 第 11 课：函数进阶与多文件编程

## 1. 函数的嵌套调用

函数里可以调别的函数，层层往下：

    int square(int x) { return x * x; }
    int sum_of_squares(int a, int b) { return square(a) + square(b); }

`main` 调 `sum_of_squares`，它再调 `square` —— 这就是"嵌套调用"。

## 2. 全局变量 vs 局部变量

    int total = 0;              /* 全局：所有函数都能用，程序运行期间一直存在 */

    void add_to_total(int x) {
        int temp = x;           /* 局部：只有这个函数里能用，函数结束就消失 */
        total += temp;
    }

| | 局部变量 | 全局变量 |
|---|---|---|
| 谁能用 | 只有定义它的函数 | 所有函数 |
| 活多久 | 函数一结束就没了 | 整个程序 |
| 建议 | **优先用** | 尽量少用（容易互相干扰，难调试）|

## 3. static：局部变量的"长期记忆"

    void count_calls(void) {
        static int n = 0;       /* 只初始化一次, 函数结束后值还留着 */
        n++;
        printf("调用第 %d 次\n", n);
    }

每次调用都打印 1、2、3……而普通的局部变量每次都会重新变回 0。

**用途**：计数器、只初始化一次的东西。

## 4. 多文件编程（本课重点）

程序变大之后，把所有代码塞一个文件会失控。拆开：

```
项目/
├── tools.h       函数声明（"目录"）
├── tools.c       函数实现（"正文"）
└── main.c        主程序（调用）
```

**tools.h**

    #ifndef TOOLS_H
    #define TOOLS_H

    int add(int a, int b);      /* 只有声明, 没有函数体 */

    #endif

> `#ifndef / #define / #endif` 是"防重复包含"的固定套路，照写就行。

**tools.c**

    #include "tools.h"          /* 用双引号：找自己项目里的头文件 */
    int add(int a, int b) { return a + b; }

**main.c**

    #include <stdio.h>
    #include "tools.h"
    int main(void) { printf("%d\n", add(3, 4)); return 0; }

**编译**（两个 .c 一起编译）：

    gcc main.c tools.c -o app.exe

> `<stdio.h>` 用尖括号（系统的），`"tools.h"` 用双引号（自己的）——这个区别要记住。

## 5. 关于 make

文件多了之后，每次手敲 `gcc a.c b.c c.c -o app` 很烦，`make` + `Makefile` 可以自动化。

本机还没装 make。以后要学的时候，在 MSYS2 终端里执行：

    pacman -S make

现在先用 gcc 直接编译，够用。

## 6. 常见坑

- 头文件里**只放声明**，不要放函数实现（否则多文件一起编译会重复定义）
- 忘了把 `tools.c` 加进编译命令 → 报"未定义引用 undefined reference"
- 头文件忘了防重复包含 → 编译报"重复定义"
- `#include "x.h"` 写成 `<x.h>` → 找不到自己项目里的头文件
- **同一个表达式里多次调用"有副作用"的函数，结果顺序不确定**
  （实测 gcc 从右往左算：`printf("%d %d %d", f(), f(), f())` 会打印 `3 2 1`）
  → 想按顺序调用，就分开写成单独语句，再打印变量

## 7. 练习

写一个函数，每次调用返回一个递增的编号（1、2、3……），体会 `static` 的作用。
