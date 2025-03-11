cmake_minimum_required(VERSION 3.10)
project(dna-processing-lib)

set(CMAKE_C_STANDARD 11)

add_executable(dna-processing-lib src/main.c src/dna_utils.c src/error_handling.c src/dna_reader.c src/dna_analysis.c src/dna_types.c src/allocator.c)

target_include_directories(dna-processing-lib PUBLIC include)

target_compile_options(dna-processing-lib PRIVATE -Wall -Wextra -Werror)
