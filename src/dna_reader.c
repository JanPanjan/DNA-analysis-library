#include "../include/dna_reader.h"
#include "../include/allocator.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int MAX_SEQUENCE_LENGTH = 1000;

/*
 * Tries to open the file given by filename, from which it will want to read.
 * Before reading it allocates memory for the sequence in the SequenceInfo
 * struct. If any of these operations fail, it return the corresponding error
 * code.
 */
Result read_dna_sequence(const char *filename, Sequence *sequence_info) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return (Result){READER_FAIL, __LINE__, __FILE__,
                    "Can't read file, because is it null. Maybe filename is "
                    "spelled wrong?"};
  }

  // Allocate memory for sequence
  Result seq_allocation_result;
  sequence_info->raw =
      _allocate_memory_(MAX_SEQUENCE_LENGTH, &seq_allocation_result);

  if (seq_allocation_result.result_code != RESULT_SUCCESS) {
    return (Result){seq_allocation_result.result_code, __LINE__, __FILE__,
                    "Memory for sequence not allocated"};
  }

  // Copy sequence from file to SequenceInfo->sequence
  int i = 0;
  char c;
  while ((c = fgetc(file)) != EOF && c != '\n' &&
         i < MAX_SEQUENCE_LENGTH - 1) { // need 1 for null-terminating character

    // check for whitespaces in input
    if (strcmp(&c, " ")) {
      continue;
    }

    // add check to see if only A, T, C or G are in the sequence
    if (c != 'A' && c != 'T' && c != 'C' && c != 'G') {
      return (Result){
          DNA_ANALYSIS_INVALID_CHARACTER, __LINE__, __FILE__,
          "Check input for invalid characters. Only A, T, C and G allowed."};
    }

    sequence_info->raw[i] = toupper(c);
    sequence_info->length++;
    i++;
  }

  // add null-terminating character to last element of string
  sequence_info->raw[i] = '\0';

  fclose(file);
  return (Result){RESULT_SUCCESS, __LINE__, __FILE__,
                  "Successfully read the DNA sequence"};
}
