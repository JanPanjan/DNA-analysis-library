#ifndef DNA_ANALYSIS_H
#define DNA_ANALYSIS_H

#include "dna_types.h"
#include "result.h"

/*
 * Counts length of the given DNA sequence.
 */
Result count_sequence_length(Sequence *sequence);

/*
 * Counts occurences of all nucleotides in the given sequence and updates
 * corresponding NucleotideCounts value.
 */
Result count_nucleotide_occurences(Sequence *sequence_info);

#endif
