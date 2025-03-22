/*
 * Common structs for DNA type data. Defined here, so they are accessible to
 * multiple headers to prevent circular dependency.
 */
#ifndef DNA_TYPES_H
#define DNA_TYPES_H

/*
 * Nucleotide occurrences in a sequence
 */
typedef struct {
  int a_count;
  int t_count;
  int c_count;
  int g_count;
} NucleotideCounts;

/*
 * Information about a specific sequence
 */
typedef struct {
  char *raw;
  long length;
  NucleotideCounts counts;
  // float GC_content;
} Sequence;

#endif // !DNA_TYPES_H
