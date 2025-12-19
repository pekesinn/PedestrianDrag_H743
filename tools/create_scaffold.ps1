\
Param(
  [Parameter(Mandatory=$false)][string]$Target = "."
)

$ErrorActionPreference = "Stop"

$srcRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = Resolve-Path (Join-Path $srcRoot "..")
$from = Join-Path $repoRoot "stm32"

# Copy folders into target CubeMX project (non-destructive)
$dst = Join-Path (Resolve-Path $Target) "stm32"
New-Item -ItemType Directory -Force -Path $dst | Out-Null

Copy-Item -Recurse -Force (Join-Path $from "Application") $dst
Copy-Item -Recurse -Force (Join-Path $from "Board") $dst

Write-Host "Scaffold copied to: $dst"
Write-Host "Next: add include paths and add sources in Keil uVision."
