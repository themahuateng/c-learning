# 编译并运行当前 C 文件（VS Code 一键任务调用）
param(
    [Parameter(Mandatory = $true)]
    [string]$File
)

# 把终端代码页切到 UTF-8，避免中文输出乱码
chcp 65001 | Out-Null

# 把 MSYS2 的 bin 加进 PATH，确保 cc1.exe 能找到它的 DLL
$env:Path = 'D:\msys64\ucrt64\bin;' + $env:Path

# === 把 exe 输出名 ASCII 化 ===
# 源文件名保留中文完全不受影响；gcc -o 用 ASCII 名，绕过 PS+msys 中文路径 codepage 错位
$dir = [System.IO.Path]::GetDirectoryName($File)
$base = [System.IO.Path]::GetFileNameWithoutExtension($File)
$asciiBase = -join ($base.ToCharArray() | ForEach-Object { if ([int]$_ -lt 128) { [string]$_ } else { '_' } })
$exe = Join-Path $dir "$asciiBase.exe"

# 1. 用 gcc 编译
& 'D:\msys64\ucrt64\bin\gcc.exe' -std=c17 -Wall -Wextra -g $File -o $exe

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
