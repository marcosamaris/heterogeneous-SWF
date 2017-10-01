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
 * @generated d Tue Sep 26 20:43:23 2017
 *
 **/
#define _TYPE  double
#define _PREC  double
#define _LAMCH LAPACKE_dlamch_work

#define _NAME  "MORSE_dtrsm"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_TRSM( MorseLeft, N, NRHS )
#define _FADDS FADDS_TRSM( MorseLeft, N, NRHS )

#include "./timing.c"
#include "timing_dauxiliary.h"

static int
RunTest(int *iparam, double *dparam, morse_time_t *t_)
{
    double alpha;
    PASTE_CODE_IPARAM_LOCALS( iparam );
    
    LDA = max( LDA, N );

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX( A,      1, double, LDA, N   );
    PASTE_CODE_ALLOCATE_MATRIX( B,      1, double, LDB, NRHS);
    PASTE_CODE_ALLOCATE_MATRIX( B2, check, double, LDB, NRHS);

     /* Initialiaze Data */
    MORSE_dplgsy( (double)N, N, A, LDA, 453 );
    MORSE_dplrnt( N, NRHS, B, LDB, 5673 );
    LAPACKE_dlarnv_work(1, ISEED, 1, &alpha);
    alpha = 10.; /*alpha * N  /  2.;*/

    if (check)
    {
        memcpy(B2, B, LDB*NRHS*sizeof(double));
    }

    START_TIMING();
    MORSE_dtrsm( MorseLeft, MorseUpper, MorseNoTrans, MorseUnit,
                  N, NRHS, alpha, A, LDA, B, LDB );
    STOP_TIMING();

    /* Check the solution */
    if (check)
    {
        dparam[IPARAM_RES] = d_check_trsm( MorseLeft, MorseUpper, MorseNoTrans, MorseUnit, 
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
