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
 * @generated c Tue Sep 26 20:43:22 2017
 *
 **/
#define _TYPE  MORSE_Complex32_t
#define _PREC  float
#define _LAMCH LAPACKE_slamch_work

#define _NAME  "MORSE_cgemm_Tile"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_GEMM(M, N, K)
#define _FADDS FADDS_GEMM(M, N, K)

#include "./timing.c"
#include "timing_cauxiliary.h"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_) 
{
    MORSE_Complex32_t alpha, beta;
    PASTE_CODE_IPARAM_LOCALS( iparam );


    LDB = max(K, iparam[IPARAM_LDB]);
    LDC = max(M, iparam[IPARAM_LDC]);

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA, 1, MORSE_Complex32_t, MorseComplexFloat, LDA, M, K );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descB, 1, MORSE_Complex32_t, MorseComplexFloat, LDB, K, N );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descC, 1, MORSE_Complex32_t, MorseComplexFloat, LDC, M, N );

    /* Initialiaze Data */
    MORSE_cplrnt_Tile( descA, 5373 );
    MORSE_cplrnt_Tile( descB, 7672 );
    MORSE_cplrnt_Tile( descC, 6387 );

    LAPACKE_clarnv_work(1, ISEED, 1, &alpha);
    LAPACKE_clarnv_work(1, ISEED, 1, &beta);

    /* Save C for check */
    PASTE_TILE_TO_LAPACK( descC, C2, check, MORSE_Complex32_t, LDC, N );

    START_TIMING();
    MORSE_cgemm_Tile( MorseNoTrans, MorseNoTrans, alpha, descA, descB, beta, descC );
    STOP_TIMING();

    /* Check the solution */
    if (check)
    {
        PASTE_TILE_TO_LAPACK( descA, A, check, MORSE_Complex32_t, LDA, K );
        PASTE_TILE_TO_LAPACK( descB, B, check, MORSE_Complex32_t, LDB, N );
        PASTE_TILE_TO_LAPACK( descC, C, check, MORSE_Complex32_t, LDC, N );

        dparam[IPARAM_RES] = c_check_gemm( MorseNoTrans, MorseNoTrans, M, N, K,
                                           alpha, A, LDA, B, LDB, beta, C, C2, LDC,
                                           &(dparam[IPARAM_ANORM]),
                                           &(dparam[IPARAM_BNORM]),
                                           &(dparam[IPARAM_XNORM]));

        free(A); free(B); free(C); free(C2);
    }

    PASTE_CODE_FREE_MATRIX( descA );
    PASTE_CODE_FREE_MATRIX( descB );
    PASTE_CODE_FREE_MATRIX( descC );
    return 0;
}
