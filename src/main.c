#include "../include/dna_analysis.h"
#include "../include/dna_reader.h"
#include "../include/allocator.h"
#include "../include/error_handling.h"

#include <stdio.h>

/*
 * Builds a sequence struct by reading the input file for data, storing its raw content, it's length and ints
 * nucleotide occurrences.
 */
void build_sequence(Sequence *sequence_struct, const char *filename);

/*
 * Same as `build_sequence`, but it returns a Sequence struct pointer instead of taking a Sequence struct as
 * input parameter.
 */
Sequence *build_sequence_struct(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        get_result((Result) {
                ERROR_INVALID_USAGE,
                __LINE__,
                __FILE__,
                "too few arguments"
        });
    }

    // Create a SequenceInfo instance to save the sequence information in it
    Sequence simple_sequence;
    build_sequence(&simple_sequence, argv[1]);

    printf("DNA sequence: %s\n", simple_sequence.raw);
    printf("Sequence length: %li\n", simple_sequence.length);
    printf("Nucleotide contents: A: %d, T: %d, C: %d, G: %d\n",
           simple_sequence.counts.a_count, simple_sequence.counts.t_count,
           simple_sequence.counts.c_count, simple_sequence.counts.g_count);

    return 0;
}

void build_sequence(Sequence *sequence_struct, const char *filename) {
    const Result seq_reading_result = read_dna_sequence(filename, sequence_struct);
    get_result((Result) {
            seq_reading_result.result_code,
            __LINE__,
            __FILE__,
            seq_reading_result.context
    });

    const Result nucleotide_counting_result = count_nucleotide_occurrences(sequence_struct);
    get_result((Result) {
            nucleotide_counting_result.result_code,
            __LINE__,
            __FILE__,
            nucleotide_counting_result.context
    });

    get_result((Result) {
            .result_code = RESULT_SUCCESS,
            .linenr = __LINE__,
            .file = __FILE__,
            .context = "Successfully built Sequence struct."
    });
}
Sequence *build_sequence_struct(const char *filename) {
    Result seq_struct_allocation;
    Sequence *seq_struct = allocate_memory(sizeof(Sequence), &seq_struct_allocation);

    const Result seq_reading_result = read_dna_sequence(filename, seq_struct);
    get_result((Result) {
            seq_reading_result.result_code,
            __LINE__,
            __FILE__,
            seq_reading_result.context
    });

    const Result nucleotide_counting_result = count_nucleotide_occurrences(seq_struct);
    get_result((Result) {
            nucleotide_counting_result.result_code,
            __LINE__,
            __FILE__,
            nucleotide_counting_result.context
    });

    get_result((Result) {
            .result_code = RESULT_SUCCESS,
            .linenr = __LINE__,
            .file = __FILE__,
            .context = "Successfully built Sequence struct."
    });
    return seq_struct;
}
