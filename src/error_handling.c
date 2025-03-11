/*
 * Common error handling functions and data structures used throughout the
 * project.
 */
#include "../include/error_handling.h"
#include <stdio.h>
#include <stdlib.h> // for exit

const ResultInfo error_messages[] = {
    {RESULT_SUCCESS, "RESULT_SUCCESS: operation successful"},

    {ERROR_INVALID_USAGE,
     "ERROR_INVALID_USAGE: correct usage is 'dna-processing-lib <dna_file>'"},

    {READER_FAIL, "READER_FAIL: error reading the file"},

    {DNA_ANALYSIS_INVALID_CHARACTER,
     "DNA_ANALYSIS_INVALID_CHARACTER: invalid character in DNA sequence"},

    {DNA_ANALYSIS_NULL_SEQUENCE,
     "DNA_ANALYSIS_NULL_SEQUENCE: invalid DNA sequence"},

    {MEMORY_ALLOCATION_FAIL, "MEMORY_ALLOCATION_FAIL: error allocating memory"},

    {MEMORY_FREE_FAIL, "MEMORY_FREE_FAIL: error freeing memory"},

    {MEMORY_FREE_NULL_PTR, "MEMORY_FREE_NULL_PTR: freeing NULL memory"},
    // add more if needed
};

/*
 * Iterates over error_messages until it finds the appropriate result code.
 * If error code is not defined in error_messages, it throws a custom message
 * and exits the program.
 */
void throw_error(const Result result) {
  for (int i = 0; i < (int)(sizeof(error_messages) / sizeof(error_messages[0]));
       i++) {
    const int rc = error_messages[i].result_code;
    const char *rm = error_messages[i].result_message;

    if ((int)result.result_code == rc) {
      fprintf(stderr, "Error %d occured in %s at line %d:\n  %s\n", rc,
              result.file, result.linenr, rm);
      exit(rc);
    }
  }

  fprintf(stderr, "Error %s %d in %s at line %d\n", "Unknown error code",
          result.result_code, result.file, result.linenr);
  exit(result.result_code);
}
