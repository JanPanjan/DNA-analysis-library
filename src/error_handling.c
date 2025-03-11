/*
 * Common error handling functions and data structures used throughout the
 * project.
 */
#include "../include/error_handling.h"

#include <stdio.h>
#include <stdlib.h> // for exit

const ResultInfo result_messages[] = {
    {RESULT_SUCCESS, "RESULT_SUCCESS:"},

    {ERROR_INVALID_USAGE,
     "ERROR_INVALID_USAGE: Correct usage is 'dna-processing-lib <dna_file>'."},

    {READER_FAIL, "READER_FAIL: Error reading the file."},

    {DNA_ANALYSIS_INVALID_CHARACTER,
     "DNA_ANALYSIS_INVALID_CHARACTER: Invalid character in DNA sequence."},

    {DNA_ANALYSIS_NULL_SEQUENCE,
     "DNA_ANALYSIS_NULL_SEQUENCE: Invalid DNA sequence."},

    {MEMORY_ALLOCATION_FAIL,
     "MEMORY_ALLOCATION_FAIL: Error allocating memory."},

    {MEMORY_FREE_FAIL, "MEMORY_FREE_FAIL: Error freeing memory."},

    {MEMORY_FREE_NULL_PTR, "MEMORY_FREE_NULL_PTR: Freeing NULL memory."},
    // add more if needed
};

/*
 * Iterates over all result_messages and displays each message.
 */
void display_all_results() {
  int n = (int)(sizeof(result_messages) / sizeof(result_messages[0]));

  for (int i = 0; i < n; i++) {
    printf("%s\n", result_messages[i].result_message);
  }
}

/*
 * Iterates over result_messages until it finds the appropriate result code.
 * If error code is not defined in result_messages, it throws a custom message
 * and exits the program.
 */
void get_result(const Result result) {
  if (result.result_code == (int)RESULT_SUCCESS) {
    const char *success_msg = result_messages[0].result_message;
    printf("%s %s\n", success_msg, result.context);
    return;
  }

  int n = (int)(sizeof(result_messages) / sizeof(result_messages[0]));

  for (int i = 1; i < n; i++) {
    const int rc = result_messages[i].result_code;
    const char *rm = result_messages[i].result_message;

    if ((int)result.result_code == rc) {
      fprintf(stderr, "Error %d occured in %s at line %d:\n  %s %s\n", rc,
              result.file, result.linenr, rm, result.context);
      exit(rc);
    }
  }

  fprintf(stderr, "Error '%s' %d in %s at line %d\n", "Unknown error code",
          result.result_code, result.file, result.linenr);
  exit(result.result_code);
}
