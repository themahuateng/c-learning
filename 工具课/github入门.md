# 工具课 02：GitHub 与远程仓库

> 前置：本地仓库已经提交过至少一次（即工具课 01 的第 8 节已完成）

## 1. GitHub 是什么

Git = 本地存档工具；GitHub = 把这些存档放到网上的网站。

放上去之后：换电脑能拉下来、能当作品集给别人看、能多人协作。

## 2. 建一个远程仓库

1. 打开 github.com 并登录
2. 右上角 `+` → **New repository**
3. 填仓库名（建议 `c-learning`）
4. 选 Public（公开）或 Private（私有）
5. **不要勾** Add a README / .gitignore / license（本地已经有了，勾了会冲突）
6. 点 **Create repository**

建完会显示一段网址，形如：

```
https://github.com/你的用户名/c-learning.git
```

## 3. 把本地仓库连过去

GitHub 的默认分支叫 `main`，本机 Git 默认建的是 `master`，先统一：

```powershell
cd D:\C-Learning
git branch -M main
git remote add origin https://github.com/你的用户名/c-learning.git
git remote -v          # 检查是否关联成功
```

## 4. 第一次推送

```powershell
git push -u origin main
```

第一次会弹出一个登录窗口（Git Credential Manager 自动弹），选"用浏览器登录 GitHub"，授权即可。以后就不用再登录了。

推送成功后，刷新 GitHub 页面，你就能看到所有文件。

## 5. 日常循环（升级版）

```
改代码 → git status → git add -A → git commit -m "说明" → git push
```

## 6. 常用命令

| 命令 | 干什么 |
|---|---|
| `git remote -v` | 看关联了哪个远程仓库 |
| `git push` | 把本地新存档推上去 |
| `git pull` | 把远程的新内容拉下来 |
| `git clone 网址` | 把别人的仓库整个下载到本地 |
| `git remote set-url origin 新网址` | 换远程地址 |

## 7. 常见问题

**认证失败 / 一直让输密码**
→ Windows 设置里搜索"凭据管理器" → Windows 凭据 → 删掉 github 相关条目，再 push 一次重新登录

**推送被拒绝（远程有本地没有的东西）**
→ 通常是建仓库时勾了 README。先拉再推：

```powershell
git pull --rebase origin main
git push
```

**网络很慢或连不上**
→ 换个时间段试；或给 git 配代理（这个后面用到再说）

## 8. 任务清单

- [ ] 注册 / 登录 GitHub
- [ ] 建一个空仓库（不勾任何初始化文件）
- [ ] `git branch -M main`
- [ ] `git remote add origin ...`
- [ ] `git push -u origin main`
- [ ] 刷新网页确认文件都在
- [ ] 在仓库页把 README 显示效果看一眼（README.md 会自动显示在首页）

## 9. 下一课预告

工具课 03：Linux 环境（WSL2 + Ubuntu）—— 见同目录 `wsl安装.md`
