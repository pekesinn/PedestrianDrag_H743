#!/usr/bin/env bash
set -euo pipefail

TARGET="${1:-.}"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"

mkdir -p "${TARGET}/stm32"
cp -R "${REPO_ROOT}/stm32/Application" "${TARGET}/stm32/"
cp -R "${REPO_ROOT}/stm32/Board" "${TARGET}/stm32/"

echo "Scaffold copied to: ${TARGET}/stm32"
echo "Next: add include paths and add sources in Keil uVision."
