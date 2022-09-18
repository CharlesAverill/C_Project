# C_Project

A template for C Projects using CMake and Doxygen for building and documentation generation, respectively. 

## Features

- Includes automatically look inside of the `include` directory
- By including `info.h`, variables defined in `CMakeLists.txt` are exposed to the program, such as the project's name and version information
- Argument parsing
- Scripts to format, compile, and run the program, script to build documentation with Doxygen
	- Doxygen formatting can be modified in `Doxyfile`
	- Project code formatting can be modified in `.clang-format`
- Github Action to auto-generate documentation with Doxygen and publish to Github Pages

## Requirements

- `cmake==3.13.0^`
- `doxygen==1.9.1^`
- `clang-format==14.0.0^`
- A C compiler
