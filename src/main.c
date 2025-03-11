#include "../include/dna_analysis.h"
#include "../include/dna_reader.h"
#include "../include/dna_types.h"
#include "../include/error_handling.h"
#include <stdio.h>

extern const int MAX_SEQUENCE_LENGTH;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    throw_error((Result){ERROR_INVALID_USAGE, __LINE__, __FILE__});
  }

  // Create a SequenceInfo instance to save the sequence information in it
  SequenceInfo simple_sequence;

  const Result seq_reading_result =
      read_dna_sequence(argv[1], &simple_sequence);

  if (seq_reading_result.result_code != RESULT_SUCCESS) {
    throw_error((Result){seq_reading_result.result_code, __LINE__, __FILE__});
  }

  const Result nucleotide_counting_result =
      count_nucleotide_occurences(&simple_sequence);

  if (nucleotide_counting_result.result_code != RESULT_SUCCESS) {
    throw_error(
        (Result){nucleotide_counting_result.result_code, __LINE__, __FILE__});
  }

  printf("DNA sequence: %s\n", simple_sequence.sequence);
  printf("Sequence length: %li\n", simple_sequence.length);
  printf("Nucleotide contents: A: %d, T: %d, C: %d, G: %d\n",
         simple_sequence.counts.a_count, simple_sequence.counts.t_count,
         simple_sequence.counts.c_count, simple_sequence.counts.g_count);

  return 0;
}
