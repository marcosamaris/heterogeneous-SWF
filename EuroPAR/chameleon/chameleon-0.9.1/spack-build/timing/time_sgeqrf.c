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

#define _NAME  "MORSE_sgeqrf"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_GEQRF(M, N)
#define _FADDS FADDS_GEQRF(M, N)

#include "./timing.c"
#include "timing_sauxiliary.h"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_) 
{
    MORSE_desc_t *T;
    PASTE_CODE_IPARAM_LOCALS( iparam );

    if ( M != N && check ) {
        fprintf(stderr, "Check cannot be perfomed with M != N\n");
        check = 0;
    }

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX( A, 1, float, LDA, N );

    /* Initialize Data */
    MORSE_splrnt(M, N, A, LDA, 3456);

    /* Allocate Workspace */
    MORSE_Alloc_Workspace_sgels(M, N, &T);
    memset(T->mat, 0, (T->llm*T->lln)*sizeof(MorseRealFloat));

    /* Save AT in lapack layout for check */
    PASTE_CODE_ALLOCATE_COPY( Acpy, check, float, A, LDA, N );

    START_TIMING();
    MORSE_sgeqrf( M, N, A, LDA, T );
    STOP_TIMING();

    /* Check the solution */
    if ( check )
    {
        PASTE_CODE_ALLOCATE_MATRIX( X, 1, float, LDB, NRHS );
        MORSE_splrnt( N, NRHS, X, LDB, 5673 );
        PASTE_CODE_ALLOCATE_COPY( B, 1, float, X, LDB, NRHS );

        MORSE_sgeqrs(M, N, NRHS, A, LDA, T, X, LDB);

        dparam[IPARAM_RES] = s_check_solution(M, N, NRHS, Acpy, LDA, B, X, LDB,
                                              &(dparam[IPARAM_ANORM]), 
                                              &(dparam[IPARAM_BNORM]), 
                                              &(dparam[IPARAM_XNORM]));

        free( Acpy ); 
        free( B ); 
        free( X );
      }

    /* Free Workspace */
    MORSE_Dealloc_Workspace( &T );
    free( A );

    return 0;
}
