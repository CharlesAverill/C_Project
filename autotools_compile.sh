clang-format -i $(find src include -name '*.c' -o -name '*.h')

# Erase build directory
if [ "$1" = "clean" ]; then
	./clean
fi

autoreconf --install
autoconf

./configure
make
