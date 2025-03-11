# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(dna_processing_lib)

set(CMAKE_C_STANDARD 11)

# Source files
set(SOURCE_FILES
    src/main.c
    src/dna_reader.c
    src/dna_analysis.c
    src/allocator.c
    src/error_handling.c
    src/dna_types.c
    src/result.c
)

# Add executable
add_executable(your_program ${SOURCE_FILES})

# Add test executable
add_executable(test_dna_reader
    tests/test_dna_reader.c
    src/dna_reader.c
    src/dna_analysis.c
    src/allocator.c
    src/error_handling.c
    src/dna_types.c
    src/result.c
)

# Enable CTest
enable_testing()

# Add test to CTest
add_test(NAME dna_reader_tests COMMAND test_dna_reader)

# Add include directories
target_include_directories(your_program PRIVATE include)
target_include_directories(test_dna_reader PRIVATE include)
