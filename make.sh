#!/bin/sh
#
# Simple build script.
mkdir -p build

for file in src/*.c; do
    file2="${file##*/}"
    gcc -Wall -Wextra "$file" -o "build/${file2%%.c}" 2>/dev/null || \
    gcc -Wall -Wextra -lX11 -lXrandr "$file" -o "build/${file2%%.c}"
done

printf '%s\n' 'Binaries are in ./build/'
