/*
 * Interface for DNA reading functionality
 */
#ifndef DNA_READER_H
#define DNA_READER_H

#include "dna_types.h"
#include "result.h"

/*
 * Max allowed sequence length, not set by machine specs currently, might be in
 * the future.
 */
extern const int MAX_SEQUENCE_LENGTH;

/*
 * Reads DNA sequence from a file and stores it into a character array. By
 * making the filename pointer a constant, we make sure that the contents of the
 * file will not be changed, they will only be read from.
 */
Result read_dna_sequence(const char *filename, Sequence *sequence_info);

#endif
