#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include "result.h"

/*
 * Generic error struct holding error code and its message
 */
typedef struct {
  ResultCode result_code;
  const char *result_message;
} ResultInfo;

/*
 * Array of ErrorInfo messages is defined in error_handling.c, here we only tell
 * the compiler it exists
 */
extern const ResultInfo error_messages[];

/*
 * Displays error code (Result), coresponding error message and exits the
 * program
 */
void throw_error(Result result);

#endif // !ERROR_HANDLING_H
