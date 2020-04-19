#ifndef SPARSECSR_HPP_
#define SPARSECSR_HPP_

#include <cstdio>
#include <cstdlib>
#include <ctime>

#ifndef REAL
#define REAL double
#endif

typedef struct row_elt{
  int col, next_row, next_idx;
  REAL val;
} row_elt;

typedef struct SPROW{
  int len, maxlen, diag;
  row_elt* elt;
} SPROW;

typedef struct SPMAT{
  int m ,n, max_m, max_n;
  char flag_col, flag_diag;
  SPROW* row;
  int* start_row;
  int* start_idx;
} SPMAT;

/*******************************
 * Scanning a row example:
 * len = A->row[i].len;
 * for (j_idx=0; j_idx<len; j_idx++)
 * {
 *    printf("%d %d %g", i, A->row[i].elt[j_idx].col, A->row[i].elt[j_idx].val);
 * } 
 */


#endif
