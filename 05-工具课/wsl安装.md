# 工具课 03：Linux 环境（WSL2 + Ubuntu）

## 1. 为什么需要 Linux

- AI 的代码、框架、服务器基本都跑在 Linux 上
- 命令行是程序员的基本功（比鼠标快得多，也是远程操作服务器的唯一方式）
- 后面学 PyTorch、Docker 都离不开它

> 好消息：不用装双系统。Windows 自带 WSL2，能在窗口里直接跑一个完整的 Ubuntu。

## 2. 本机现状（已检查过）

| 项 | 状态 |
|---|---|
| 操作系统 | Windows 11 家庭版 ✅ 支持 WSL2 |
| CPU 虚拟化 | 已在 BIOS 开启 ✅ |
| WSL 命令 | 存在，但**还没装 Linux 发行版** |

## 3. 安装步骤

**第一步**：以管理员身份打开终端

- 右键"开始"按钮 → 选"终端（管理员）"或"Windows PowerShell（管理员）"
- 弹出询问点"是"

**第二步**：一条命令

```powershell
wsl --install
```

它会自动：开启需要的 Windows 功能 → 下载 Ubuntu → 装好

**第三步**：重启电脑（必须）

**第四步**：重启后 Ubuntu 会自动弹出一个窗口，要求你设置：

- 用户名（英文小写，例如 `kai`）
- 密码（输入时不显示，正常现象）

## 4. 验证

在 PowerShell 里：

```powershell
wsl -l -v
```

应该看到类似：

```
  NAME      STATE      VERSION
* Ubuntu    Running    2
```

看到 `VERSION 2` 就成功了。

## 5. 基本使用

| 做什么 | 命令 |
|---|---|
| 进入 Linux | 在终端敲 `wsl` |
| 退出 | `exit` |
| 看当前目录 | `pwd` |
| 列出文件 | `ls` |
| 访问 D 盘 | `cd /mnt/d` |
| 装软件 | `sudo apt update` 然后 `sudo apt install 包名` |

> Windows 的盘在 Linux 里挂在 `/mnt/` 下面：C 盘是 `/mnt/c`，D 盘是 `/mnt/d`。

## 6. 常见问题

**提示虚拟化未启用**
→ 进 BIOS 开 VT-x / AMD-V（本机已开，应该不会遇到）

**下载很慢或失败**
→ 换个时间重试；也可以指定发行版：`wsl --install -d Ubuntu`

**想更新 WSL 本身**
→ `wsl --update`

**忘了 Linux 密码**
→ 用 `wsl -u root` 进去改（以后遇到再说）

## 7. 任务清单

- [ ] 管理员终端执行 `wsl --install`
- [ ] 重启电脑
- [ ] 设置 Ubuntu 用户名和密码
- [ ] `wsl -l -v` 确认 VERSION 2
- [ ] 进入 Ubuntu，用 `cd /mnt/d/C-Learning && ls` 看一眼自己的学习目录
- [ ] 试着装一个小软件：`sudo apt update && sudo apt install tree`，然后 `tree -L 1`
