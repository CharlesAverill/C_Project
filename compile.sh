clang-format -i $(find src include -name '*.c' -o -name '*.h')

# Erase build directory
if [ "$1" = "clean" ]; then
	rm -r build bin
fi

cmake -B build

cmake --build build
