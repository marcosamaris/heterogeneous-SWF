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

#define _NAME  "MORSE_cgels"
/* See Lawn 41 page 120 */
#define _FMULS (FMULS_GEQRF( M, N ) + FMULS_GEQRS( M, N, NRHS ))
#define _FADDS (FADDS_GEQRF( M, N ) + FADDS_GEQRS( M, N, NRHS ))

#include "./timing.c"
#include "timing_cauxiliary.h"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_) 
{
    MORSE_desc_t *T;
    PASTE_CODE_IPARAM_LOCALS( iparam );

    if ( M != N ) {
        fprintf(stderr, "This timing works only with M == N\n");
        return -1;
    }

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX( A,    1,     MORSE_Complex32_t, LDA, N   );
    PASTE_CODE_ALLOCATE_MATRIX( x,    1,     MORSE_Complex32_t, LDB, NRHS);
    PASTE_CODE_ALLOCATE_MATRIX( Acpy, check, MORSE_Complex32_t, LDA, N   );
    PASTE_CODE_ALLOCATE_MATRIX( b,    check, MORSE_Complex32_t, LDB, NRHS);

     /* Initialiaze Data */
    MORSE_cplrnt( M, N,    A, LDA,  453 );
    MORSE_cplrnt( M, NRHS, x, LDB, 5673 );

    MORSE_Alloc_Workspace_cgels(M, N, &T);
    memset(T->mat, 0, (T->llm*T->lln)*sizeof(MorseComplexFloat));

    /* Save A and b  */
    if (check) {
        LAPACKE_clacpy_work(LAPACK_COL_MAJOR, 'A', M, N,    A, LDA, Acpy, LDA);
        LAPACKE_clacpy_work(LAPACK_COL_MAJOR, 'A', M, NRHS, x, LDB, b,    LDB);
    }

    START_TIMING();
    MORSE_cgels( MorseNoTrans, M, N, NRHS, A, LDA, T, x, LDB );
    STOP_TIMING();
    
    /* Check the solution */
    if (check)
    {
        dparam[IPARAM_RES] = c_check_solution(M, N, NRHS, Acpy, LDA, b, x, LDB,
                                              &(dparam[IPARAM_ANORM]), 
                                              &(dparam[IPARAM_BNORM]), 
                                              &(dparam[IPARAM_XNORM]));
        free(Acpy); free(b);
    }

    MORSE_Dealloc_Workspace( &T );
    free( A );
    free( x );

    return 0;
}
