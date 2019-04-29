/*  Final Project - SCML Winter 2018
*   g++ -I./ mmio.cpp spmv_solvers -o spmv_solvers
*   Solvers: Jacobi, Gauss-Seidel, Southwell, and SOR
*   Accelerators: None and OpenMP
*   Performance Evaluation: Time, Iterations, Convergence Rate, GFLOPS
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

#include "mmio.h"

static bool compare_first(const std::pair< int, double >& a, const std::pair< int, double >& b )
{
    return (a.first < b.first);
}

int main(int argc, char *argv[]) {
    /**************************************************************************/
    /* We first read in the matrix from a .mtx file.                          */
    /**************************************************************************/
    int ret_code;
    MM_typecode matcode;
    FILE *f;
    int M, N, nz;
    int i, *I, *J, *row, *col;
    double *val, *valt;
    std::vector< std::pair< int, double > > rowval;

    if(argc<2) {
      std::cerr << "SpMV Routine. Usage: " << argv[0] << " [matrix-market-filename]" << std::endl;
      // fprintf(stderr, "SpMV routine. Usage: %s [martix-market-filename]\n", argv[0]);
	    exit(1);
    } else {
      if ((f = fopen(argv[1], "r")) == NULL)
        exit(1);
    }

    if(mm_read_banner(f, &matcode) != 0) {
      std::cout << "Could not process Matrix Market banner." << std::endl;
      exit(1);
    }

    /*  This is how one can screen matrix types if their application */
    /*  only supports a subset of the Matrix Market data types.      */

    if (mm_is_complex(matcode) && mm_is_matrix(matcode) && mm_is_sparse(matcode) )
    {
        printf("Sorry, this application does not support ");
        printf("Market Market type: [%s]\n", mm_typecode_to_str(matcode));
        exit(1);
    }

    /* find out size of sparse matrix .... */

    ret_code = mm_read_mtx_crd_size(f, &M, &N, &nz);
    if (ret_code !=0)
        exit(1);

    /* reseve memory for matrices */
    I = (int*)malloc(nz*sizeof(int));
    J = (int*)malloc(nz*sizeof(int));
    valt = (double*)malloc(nz*sizeof(double));

    for (i=0; i<nz; i++)
    {
        fscanf(f, "%d %d %lg\n", &I[i], &J[i], &valt[i]);
        I[i]--;  /* adjust from 1-based to 0-based */
        J[i]--;
    }

    if (f !=stdin) fclose(f);

    /* convert the COO matrix to CSR */
    row = (int*)malloc((M+1)*sizeof(int));
    col = (int*)malloc(nz*sizeof(int));
    val = (double*)malloc(nz*sizeof(double));
    // original code from  Nathan Bell and Michael Garland
    for ( i = 0; i < M; i++ )
        (row)[i] = 0;

    for (i=0;i<nz;i++)
        (row)[I[i]]++;

    // cumulative sum the nnz per row to get row[]
    int cumsum;
    cumsum = 0;
    for( i = 0; i < M; i++ ) {
        int temp = row[i];
        (row)[i] = cumsum;
        cumsum += temp;
    }
    (row)[M] = nz;

    // write Aj,Ax into Bj,Bx
    for( i = 0; i < nz; i++ ) {
        int row_  = I[i];
        int dest = row[row_];
        col[dest] = J[i];
        val[dest] = valt[i];
        row[row_]++;
    }

    int last;
    last = 0;
    for( i = 0; i <= M; i++ ) {
        int temp  = (row)[i];
        (row)[i] = last;
        last      = temp;
    }

    (row)[M] = nz;

    // sort column indices within each row
    // copy into vector of pairs (column index, value), sort by column index
    for ( int k=0; k < M; ++k ) {
        int kk  = (row)[k];
        int len = (row)[k+1] - row[k];
        rowval.resize( len );
        for( i=0; i < len; ++i ) {
            rowval[i] = std::make_pair( col[kk+i], val[kk+i] );
        }
        std::sort( rowval.begin(), rowval.end(), compare_first );
        for( i=0; i < len; ++i ) {
            col[kk+i] = rowval[i].first;
            val[kk+i] = rowval[i].second;
        }
    }

    /**************************************************************************/
    /* Now we have the matrix in CPU main memory in CSR format.               */
    /* The matrix A is stored as triplet A = [ row col val ].                 */
    /* We can now start with GPU allocation.                                  */
    /**************************************************************************/

    /* reserve memory for vectors x and y */
    int vecSize = N*sizeof(double);
    double *x, *y, *Ax, *b;

    b = (double*)malloc(vecSize);
    x = (double*)malloc(vecSize);
    y = (double*)malloc(vecSize);
    Ax = (double*)malloc(vecSize);

    /* initialize vectors and send vectors and matrix to the GPU */
    for (i=0; i<N; i++){
        x[i] = 0.0; // Our Initial Guess
        y[i] = 0.0;
        b[i] = 1.0; // Solve this with MKL sparse library
    }

    printf("NNZ: %d, M: %d, N: %d \n", nz, M, N);
//    for(i=0;i<nz;i++) printf("%.3f \n", valt[i]);

    free(b); free(x); free(y); free(Ax); free(val); free(col); free(row);
    free(valt); free(I); free(J);
    return 0;
}
