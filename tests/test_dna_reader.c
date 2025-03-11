#include "../include/allocator.h"
#include "../include/dna_reader.h"
#include "../include/dna_types.h"
#include "../include/error_handling.h"
#include "../include/result.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Set path for dna_reader test files and keep track of how many tests are
 * passed.
 */
static char *test_data = "test_data/dna_reader/";
static const int all_tests = 10;
static int passed_tests = 0;

char *join_strings(char *s1, char *s2) {
  char *fullpath;
  size_t s1_len = strlen(s1);
  size_t s2_len = strlen(s2);

  Result r;
  fullpath = _allocate_memory_(s1_len + s2_len + 1, &r);
  get_result((Result){r.result_code, __LINE__, __FILE__,
                      "Memory for concatenation not allocated."});
  strcpy(fullpath, s1);
  strcpy(fullpath, s2);

  return fullpath;
}

void __test_read_valid_sequence() {
  const char *filename =
      join_strings(test_data, "test_read_valid_sequence.txt");
  Sequence sequence;

  Result result = read_dna_sequence(filename, &sequence);

  assert(result.result_code == RESULT_SUCCESS);
  assert(strcmp(sequence.raw, "ACATCT") == 0); // 0 for equal, 1 for different
  assert(sequence.length == 6);

  free(sequence.raw);
  remove(filename);

  printf("'test_read_valid_sequence' passed\n");
  passed_tests++;
}

void test_read_valid_sequence() {
  Sequence sequence_info = {0};
  const char *filename =
      strcat(test_data, "test_read_valid_sequence.txt"); // Create this file

  printf("%s\n", filename);

  Result result = read_dna_sequence(filename, &sequence_info);

  assert(result.result_code == RESULT_SUCCESS);
  printf("%s :: %s\n", sequence_info.raw, "ATCGATCG");
  assert(strcmp(sequence_info.raw, "ATCGATCG") == 0);
  assert(sequence_info.length == 8);

  free(sequence_info.raw);
  remove(filename); // Cleanup test file
  printf("test_read_valid_sequence passed\n");
}

int main() {
  test_read_valid_sequence();

  printf("All %d/%d tests passed!\n", passed_tests, all_tests);
  return 0;
}
