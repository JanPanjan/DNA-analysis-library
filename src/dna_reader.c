#include "../include/dna_reader.h"
#include "../include/allocator.h"
#include <ctype.h>
#include <stdio.h>

const int MAX_SEQUENCE_LENGTH = 1000;

/*
 * Tries to open the file given by filename, from which it will want to read.
 * Before reading it allocates memory for the sequence in the SequenceInfo
 * struct. If any of these operations fail, it return the corresponding error
 * code.
 */
Result read_dna_sequence(const char *filename, SequenceInfo *sequence_info) {

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return (Result){READER_FAIL, __LINE__, __FILE__};
  }

  // Allocate memory for sequence
  Result seq_allocating_result;

  sequence_info->sequence =
      _allocate_memory_(MAX_SEQUENCE_LENGTH, &seq_allocating_result);

  if (seq_allocating_result.result_code != RESULT_SUCCESS) {
    return (Result){seq_allocating_result.result_code, __LINE__, __FILE__};
  }

  // Copy sequence from file to SequenceInfo->sequence
  int i = 0;
  char c;
  while ((c = fgetc(file)) != EOF && c != '\n' &&
         i < MAX_SEQUENCE_LENGTH - 1) { // need 1 for null-terminating character
    // add check to see if only A, T, C or G are in the sequence
    if (c != 'A' && c != 'T' && c != 'C' && c != 'G') {
      return (Result){DNA_ANALYSIS_INVALID_CHARACTER, __LINE__, __FILE__};
    }
    sequence_info->sequence[i] = toupper(c);
    sequence_info->length++;
    i++;
  }

  // add null-terminating character to last element of string
  sequence_info->sequence[i] = '\0';

  fclose(file);
  return (Result){RESULT_SUCCESS, __LINE__, __FILE__};
}
