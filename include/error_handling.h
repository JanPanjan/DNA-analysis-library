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
 * Array of ResultInfo messages is defined in error_handling.c, here we only
 * tell the compiler it exists
 */
extern const ResultInfo result_messages[];

/*
 * Displays all results in result_messages.
 */
void display_all_results();

/*
 * Displays error code (Result), coresponding error message and exits the
 * program
 */
void get_result(Result result);

#endif // !ERROR_HANDLING_H
