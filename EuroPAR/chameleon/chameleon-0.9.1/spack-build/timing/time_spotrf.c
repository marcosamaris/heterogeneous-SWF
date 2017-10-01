/**
 *
 * @copyright (c) 2009-2014 The University of Tennessee and The University
 *                          of Tennessee Research Foundation.
 *                          All rights reserved.
 * @copyright (c) 2012-2014 Inria. All rights reserved.
 * @copyright (c) 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria, Univ. Bordeaux. All rights reserved.
 *
 **/

/**
 *
 * @generated s Tue Sep 26 20:43:22 2017
 *
 **/
#define _TYPE  float
#define _PREC  float
#define _LAMCH LAPACKE_slamch_work

#define _NAME  "MORSE_spotrf"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_POTRF( N )
#define _FADDS FADDS_POTRF( N )

#include "./timing.c"
#include "timing_sauxiliary.h"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_) 
{
    PASTE_CODE_IPARAM_LOCALS( iparam );
    int uplo = MorseLower;

    LDA = max(LDA, N);

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX( A, 1, float, LDA, N );

    /* Initialiaze Data */
    MORSE_splgsy( (float)N, N, A, LDA, 51 );

    /* Save A and b  */
    PASTE_CODE_ALLOCATE_COPY( A2, check, float, A, LDA, N    );

    /* MORSE SPOSV */
    START_TIMING();
    MORSE_spotrf(uplo, N, A, LDA);
    STOP_TIMING();

    /* Check the solution */
    if (check)
      {
        PASTE_CODE_ALLOCATE_MATRIX( B, check, float, LDB, NRHS );
        MORSE_splrnt( N, NRHS, B, LDB, 5673 );
        PASTE_CODE_ALLOCATE_COPY( X,  check, float, B, LDB, NRHS );

        MORSE_spotrs(uplo, N, NRHS, A, LDA, X, LDB);

        dparam[IPARAM_RES] = s_check_solution(N, N, NRHS, A2, LDA, B, X, LDB,
                                              &(dparam[IPARAM_ANORM]), 
                                              &(dparam[IPARAM_BNORM]),
                                              &(dparam[IPARAM_XNORM]));

        free(A2); free(B); free(X);
      }

    free(A);

    return 0;
}
