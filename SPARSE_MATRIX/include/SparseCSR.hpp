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

/* Scanning a row example:
 * len = A->row[i].len;
 * for (j_idx=0; j_idx<len; j_idx++)
 * {printf("%d %d %g", i, A->row[i].elt[j_idx].col, A->row[i].elt[j_idx].val);} 
 */

/* SPMV COO format */

// for (int i=0; i<n; ++i) y[i] = 0.0;
// for (int i=0; i<nnz; ++i) y[ row[i] ] += val[i] * x[ col[i] ];

/* SPMV CSR format pseudo code
 * row_off = row offset matrix (int) (N+1)
 * col = column array          (int) (nnz)
 * val = non-zero elements     (REAL)(nnz) */

// #pragma omp parallel for
// for (int i=0; i<n; ++i){
//  y[i] = 0.0;
//  for (int j=row_off[i]; j<row_off[i+1]; ++j){
//    y[i] += val[j] * x[ col[j] ];
//  } // END-FOR j
// } // END-FOR i

#endif
