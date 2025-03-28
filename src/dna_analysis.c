#include "../include/dna_analysis.h"

#include <ctype.h>

/*
 * Initializes all nucleotide counts to 0 and starts iterating through the
 * sequence. Once it hits a match, it increments the corresponding nucleotide
 * counter. If a mismatch occurs (invalid characters, all other than A, T, C or
 * G), it returns error.
 */
Result count_nucleotide_occurrences(Sequence *sequence_info) {
    sequence_info->counts.a_count = 0;
    sequence_info->counts.t_count = 0;
    sequence_info->counts.c_count = 0;
    sequence_info->counts.g_count = 0;

    for (int i = 0; sequence_info->raw[i] != '\0'; i++) {
        char nucleotide = toupper(sequence_info->raw[i]);

        switch (nucleotide) {
            case 'A':
                (sequence_info->counts.a_count)++;
                break;
            case 'T':
                (sequence_info->counts.t_count)++;
                break;
            case 'C':
                (sequence_info->counts.c_count)++;
                break;
            case 'G':
                (sequence_info->counts.g_count)++;
                break;
            default:
                return (Result) {
                        DNA_ANALYSIS_INVALID_CHARACTER,
                        __LINE__,
                        __FILE__,
                        "Check input for invalid characters. Only A, T, C and G allowed."
                };
        }
    }

    return (Result) {
            RESULT_SUCCESS,
            __LINE__,
            __FILE__,
            "Successfully counted nucleotide occurences."
    };
}
