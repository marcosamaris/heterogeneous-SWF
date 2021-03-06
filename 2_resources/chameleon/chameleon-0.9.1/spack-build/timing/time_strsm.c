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

#define _NAME  "MORSE_strsm"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_TRSM( MorseLeft, N, NRHS )
#define _FADDS FADDS_TRSM( MorseLeft, N, NRHS )

#include "./timing.c"
#include "timing_sauxiliary.h"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_)
{
    float alpha;
    PASTE_CODE_IPARAM_LOCALS( iparam );
    
    LDA = max( LDA, N );

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX( A,      1, float, LDA, N   );
    PASTE_CODE_ALLOCATE_MATRIX( B,      1, float, LDB, NRHS);
    PASTE_CODE_ALLOCATE_MATRIX( B2, check, float, LDB, NRHS);

     /* Initialiaze Data */
    MORSE_splgsy( (float)N, N, A, LDA, 453 );
    MORSE_splrnt( N, NRHS, B, LDB, 5673 );
    LAPACKE_slarnv_work(1, ISEED, 1, &alpha);
    alpha = 10.; /*alpha * N  /  2.;*/

    if (check)
    {
        memcpy(B2, B, LDB*NRHS*sizeof(float));
    }

    START_TIMING();
    MORSE_strsm( MorseLeft, MorseUpper, MorseNoTrans, MorseUnit,
                  N, NRHS, alpha, A, LDA, B, LDB );
    STOP_TIMING();

    /* Check the solution */
    if (check)
    {
        dparam[IPARAM_RES] = s_check_trsm( MorseLeft, MorseUpper, MorseNoTrans, MorseUnit, 
                                           N, NRHS,
                                           alpha, A, LDA, B, B2, LDB,
                                           &(dparam[IPARAM_ANORM]), 
                                           &(dparam[IPARAM_BNORM]),
                                           &(dparam[IPARAM_XNORM]));
        free(B2);
    }

    free( A );
    free( B );

    return 0;
}
