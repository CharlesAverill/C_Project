if [ "$1" = "cmake" ]; then 
	rm src/Makefile.am Makefile.am
	rm include/info_autotools.h.in
	rm AUTHORS COPYING ChangeLog INSTALL NEWS
	rm configure.ac
	rm autotools_compile.sh
elif [ "$1" = "autotools" ]; then
	rm CMakeLists.txt
	rm include/cmake_info.h*
	rm cmake_compile.sh
	sed -i 's/PROJECT_NAME_AND_VERS/PACKAGE_STRING/' src/arguments.c
	sed -i 's|EXECUTABLE_PATH="$SCRIPT_DIR/bin/helloworld"|EXECUTABLE_PATH="$SCRIPT_DIR/src/helloworld"|' run.sh
	sed -i 's|! -d "$SCRIPT_DIR/bin"|! -d "$SCRIPT_DIR/src"|' run.sh
	sed -i 's/cmake_compile.sh/autotools_compile.sh/' run.sh
	mv include/info_autotools.h.in info.h.in
fi
git checkout -b gh-pages
git push origin gh-pages
git checkout main
