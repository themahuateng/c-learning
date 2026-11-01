# 编译并运行 C 程序（VS Code 一键任务调用）
#
# 支持两种模式：
#   1. 普通练习目录       -> 只编译当前 .c 文件
#   2. 多文件项目目录     -> 如果当前文件是 main.c，
#                            并且同目录还有别的 .c，就一起编译
#
# 这样 lesson 目录里放多个独立练习时，不会把多个 main 一起编译。

param(
    [Parameter(Mandatory = $true)]
    [string]$File
)

# 把终端代码页切到 UTF-8，避免中文输出乱码
chcp 65001 | Out-Null

# 把 MSYS2 的 bin 加进 PATH，确保 cc1.exe 能找到它的 DLL
$env:Path = 'D:\msys64\ucrt64\bin;' + $env:Path

$dir = [System.IO.Path]::GetDirectoryName($File)

# === 找出同目录下所有 .c 文件 ===
$allC = @(Get-ChildItem -LiteralPath $dir -Filter '*.c' -File | Sort-Object Name)
$currentName = [System.IO.Path]::GetFileName($File)
$hasMain = Test-Path -LiteralPath (Join-Path $dir 'main.c')

if ($allC.Count -gt 1 -and $hasMain -and $currentName -ieq 'main.c') {
    # 多文件项目：从 main.c 启动时，全部一起编译
    $sources = $allC.FullName
    Write-Host "多文件项目：共 $($allC.Count) 个 .c 文件" -ForegroundColor Cyan
    foreach ($f in $allC) { Write-Host "  - $($f.Name)" -ForegroundColor DarkGray }
} else {
    # 普通练习：只编当前文件，避免多个独立 main 冲突
    $sources = @($File)
}

# === 把 exe 输出名 ASCII 化 ===
# 源文件名保留中文；gcc -o 用 ASCII 名，绕过 PS+msys 中文路径 codepage 错位
# exe 输出到系统临时目录，避免中文目录名传给 gcc 时乱码
$base = [System.IO.Path]::GetFileNameWithoutExtension($File)
$asciiBase = -join ($base.ToCharArray() | ForEach-Object { if ([int]$_ -lt 128) { [string]$_ } else { '_' } })
$exe = Join-Path $env:TEMP "$asciiBase.exe"

# 1. 用 gcc 编译
& 'D:\msys64\ucrt64\bin\gcc.exe' -std=c17 -Wall -Wextra -g $sources -o $exe

# 2. 编译成功则运行
if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "================ 运行结果 ================"
    & $exe
    Write-Host "=========================================="
} else {
    Write-Host ""
    Write-Host "编译失败！请根据上面的红色错误信息修改代码。"
}
