#ifndef RESULT_H
#define RESULT_H

/*
 * Operation result codes
 */
typedef enum {
  // General success result
  RESULT_SUCCESS,

  // Invalid tool usage
  ERROR_INVALID_USAGE,

  // Reader errors
  READER_FAIL,

  // DNA analysis errors
  DNA_ANALYSIS_INVALID_CHARACTER,
  DNA_ANALYSIS_NULL_SEQUENCE,

  // Memory errors
  MEMORY_ALLOCATION_FAIL,
  MEMORY_FREE_NULL_PTR,
  MEMORY_FREE_FAIL,
} ResultCode;

/*
 * Wrap result codes into a Result struct with line number and file where result
 * occured
 */
typedef struct {
  ResultCode result_code;
  int linenr;
  char *file;
  char *context;
} Result;

#endif // !RESULT_H
