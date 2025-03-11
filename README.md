# DNA processing library in C

DNA processing library written in C programming language.

---

The goals for this project were:
- to get more comfortable using C for programming
- to learn how to structure C projects and how to use tools for C programming, like CMake
- Make and to familiarize myself more with bioinformatics tools.

## Project structure

`include` contains header files, `src` contains source files, `build` contains
binary files, `data` contains some DNA (and other) data files, `tests` contains
unit tests and `examples` contains simple examples of using these tools.

## Build and run project

To build this project first run `cmake -S . -B build` from root. Once you run this,
it won't be necessary to run it again, unless you modify the `CMakeLists.txt` file.
To compile and run source files, first cd into `build` and then run `make && ./dna-processing-lib`.
