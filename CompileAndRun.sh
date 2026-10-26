#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <source.cpp>"
    exit 1
fi

SOURCE="$1"

if [[ ! -f "$SOURCE" || "$SOURCE" != *.cpp ]]; then
    echo "Error: '$SOURCE' is not a valid .cpp file."
    exit 1
fi

mkdir -p bin

NAME="$(basename "${SOURCE%.cpp}")"
OUTPUT="bin/$NAME"

# Collect all C++ source files in the engine.
mapfile -t ENGINE_SOURCES < <(find src/engine -type f -name '*.cpp' | sort)

g++ -std=c++20 -Wall -Wextra -Wpedantic -g \
    "$SOURCE" \
    "${ENGINE_SOURCES[@]}" \
    -o "$OUTPUT"

"$OUTPUT"
