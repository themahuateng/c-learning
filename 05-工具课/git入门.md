# 工具课 01：Git 入门

## 1. Git 是什么

版本控制 = 给代码**存档**。

每存一次档（commit），就留下一个点。以后改坏了，随时能回到任何一个存档。

为什么需要它：

- 改坏了能回退（不用手动复制"版本1/版本2/最终版/真的最终版"）
- 能看到自己每天做了什么（学习记录自动就有）
- 多人合作的基础（GitHub 上就是靠它）

## 2. 三个区域（核心概念，先记住这张图）

```
工作区            暂存区           版本库
你正在改的文件  →  挑出来要存的  →  存档本身
（VS Code 里）     （add）          （commit）
```

一次完整操作就是：**改文件 → add → commit**

## 3. 第一次配置（只做一次）

```powershell
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"
```

这两行的作用：告诉 Git"以后每次存档，作者写谁"。
没有它，Git 拒绝给你存档。

> 邮箱建议用你 GitHub 账号绑定的那个。

## 4. 五个最常用的命令

| 命令 | 干什么 |
|---|---|
| `git status` | 看现在什么状态（**最常用**，新手一天敲 50 次）|
| `git add 文件名` | 把改动放进暂存区（`git add -A` 是全部）|
| `git commit -m "说明"` | 存档，说明写清楚改了什么 |
| `git log --oneline` | 看存档历史 |
| `git diff` | 看具体改了什么内容 |

## 5. 日常循环（以后天天这么用）

```
改代码 → git status → git add -A → git commit -m "改了什么"
```

## 6. GitHub 和 Git 的关系

| | 是什么 |
|---|---|
| **Git** | 本地的存档工具（离线也能用）|
| **GitHub** | 网上的仓库托管网站 |
| `git push` | 把本地存档上传到 GitHub |
| `git pull` | 把 GitHub 上的更新拉回本地 |

先把本地用熟，再上 GitHub——顺序别反。

## 7. 常见坑

- 忘了 `add` 就 `commit` → 结果是空的，什么也没存进去
- commit 说明写"更新"、"改了一下" → 半年后自己都看不懂
- 把 `.exe` 这类编译产物提交上去 → 用 `.gitignore` 排除（本仓库已配好）
- 中文文件名在 git 里显示成 `\351\207\221` → 执行 `git config core.quotepath false`（本仓库已设）

## 8. 你现在的任务（第一次提交）

```powershell
# 1. 配身份（把引号里换成你自己的）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"

# 2. 进到学习目录
cd D:\C-Learning

# 3. 看状态（会列出 60 多个文件在等着）
git status

# 4. 存档
git commit -m "第一次提交：C 语言第 1~7 课 + 学习方案"

# 5. 查看存档历史
git log --oneline
```

做完第 5 步，你会看到自己人生的第一条 Git 记录。

## 9. 下一课预告

工具课 02：GitHub 与远程仓库（建仓库、push、pull、README 展示）
