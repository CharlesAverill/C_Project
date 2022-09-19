rm CMakeLists.txt
rm include/cmake_info.h*
rm setup_cmake.sh
sed -i 's/PROJECT_NAME_AND_VERS/PROJECT_STRING/' src/arguments.c
sed -i 's/cmake_compile.sh/autotools_compile.sh/' run.sh
mv include/info_autotools.h.in info.h.in
