#!/bin/sh
#
# Simple build script.
mkdir -p build

for file in *.c; do
    gcc -Wall -Wextra "$file" -o "build/${file%%.c}" 2>/dev/null || \
    gcc -Wall -Wextra -lX11 -lXrandr "$file" -o "build/${file%%.c}"
done

printf "%s\\n" "Binaries are in ./build/"
