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

#define _NAME  "MORSE_cgesv_incpiv"
/* See Lawn 41 page 120 */
#define _FMULS (FMULS_GETRF( N, N ) + FMULS_GETRS( N, NRHS ))
#define _FADDS (FADDS_GETRF( N, N ) + FADDS_GETRS( N, NRHS ))

#include "./timing.c"
#include "timing_cauxiliary.h"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_) 
{
    MORSE_desc_t *L;
    int *piv;
    PASTE_CODE_IPARAM_LOCALS( iparam );
    
    if ( M != N ) {
        fprintf(stderr, "This timing works only with M == N\n");
        return -1;
    }
    
    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX( A, 1, MORSE_Complex32_t, LDA, N    );
    PASTE_CODE_ALLOCATE_MATRIX( X, 1, MORSE_Complex32_t, LDB, NRHS );
    
    /* Initialiaze Data */
    MORSE_cplrnt( N, N,    A, LDA,   51 );
    MORSE_cplrnt( N, NRHS, X, LDB, 5673 );

    MORSE_Alloc_Workspace_cgesv_incpiv(N, &L, &piv);

    /* Save A and b  */
    PASTE_CODE_ALLOCATE_COPY( Acpy, check, MORSE_Complex32_t, A, LDA, N    );
    PASTE_CODE_ALLOCATE_COPY( B,    check, MORSE_Complex32_t, X, LDB, NRHS );

    START_TIMING();
    MORSE_cgesv_incpiv( N, NRHS, A, N, L, piv, X, LDB );
    STOP_TIMING();
    
    /* Check the solution */
    if (check)
    {
        dparam[IPARAM_RES] = c_check_solution(N, N, NRHS, Acpy, LDA, B, X, LDB,
                                              &(dparam[IPARAM_ANORM]), 
                                              &(dparam[IPARAM_BNORM]), 
                                              &(dparam[IPARAM_XNORM]));
        free(Acpy); free(B);
    }

    MORSE_Dealloc_Workspace( &L );
    free( piv );
    free( X );
    free( A );


    return 0;
}
