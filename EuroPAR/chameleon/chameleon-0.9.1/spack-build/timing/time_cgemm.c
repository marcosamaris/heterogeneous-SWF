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
 * @generated c Tue Sep 26 20:43:23 2017
 *
 **/
#define _TYPE  MORSE_Complex32_t
#define _PREC  float
#define _LAMCH LAPACKE_slamch_work

#define _NAME  "MORSE_cgemm"
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
    PASTE_CODE_ALLOCATE_MATRIX( A,      1, MORSE_Complex32_t, LDA, K   );
    PASTE_CODE_ALLOCATE_MATRIX( B,      1, MORSE_Complex32_t, LDB, N   );
    PASTE_CODE_ALLOCATE_MATRIX( C,      1, MORSE_Complex32_t, LDC, N   );
    PASTE_CODE_ALLOCATE_MATRIX( C2, check, MORSE_Complex32_t, LDC, N   );

    MORSE_cplrnt( M, K, A, LDA,  453 );
    MORSE_cplrnt( K, N, B, LDB, 5673 );
    MORSE_cplrnt( M, N, C, LDC,  740 );

    LAPACKE_clarnv_work(1, ISEED, 1, &alpha);
    LAPACKE_clarnv_work(1, ISEED, 1, &beta );

    if (check)
    {
        memcpy(C2, C, LDC*N*sizeof(MORSE_Complex32_t));
    }

    START_TIMING();
    MORSE_cgemm( MorseNoTrans, MorseNoTrans, M, N, K, alpha, A, LDA, B, LDB, beta, C, LDC );
    STOP_TIMING();

    /* Check the solution */
    if (check)
    {
        dparam[IPARAM_RES] = 0.0;
        dparam[IPARAM_RES] = c_check_gemm( MorseNoTrans, MorseNoTrans, M, N, K,
                                           alpha, A, LDA, B, LDB, beta, C, C2, LDC,
                                           &(dparam[IPARAM_ANORM]),
                                           &(dparam[IPARAM_BNORM]),
                                           &(dparam[IPARAM_XNORM]));

        free(C2);
    }

    free( A );
    free( B );
    free( C );

    return 0;
}
