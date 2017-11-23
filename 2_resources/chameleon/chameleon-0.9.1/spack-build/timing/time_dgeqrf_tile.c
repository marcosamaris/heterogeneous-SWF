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
 * @generated d Tue Sep 26 20:43:20 2017
 *
 **/
#define _TYPE  double
#define _PREC  double
#define _LAMCH LAPACKE_dlamch_work

#define _NAME  "MORSE_dgeqrf_Tile"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_GEQRF( M, N )
#define _FADDS FADDS_GEQRF( M, N )

#include "./timing.c"

static int
RunTest(int *iparam, double *dparam, morse_time_t *t_)
{
    MORSE_desc_t *descT;
    PASTE_CODE_IPARAM_LOCALS( iparam );

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA,  1, double, MorseRealDouble, LDA, M, N );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descX,  ( check && M == N ), double, MorseRealDouble, LDB, M, NRHS );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descAC, ( check && M == N ), double, MorseRealDouble, LDA, M, N    );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descB,  ( check && M == N ), double, MorseRealDouble, LDB, M, NRHS );

    MORSE_dplrnt_Tile( descA, 5373 );

    /* Save A for check */
    if (check == 1 && M == N){
        MORSE_dlacpy_Tile(MorseUpperLower, descA, descAC);
    }

    /* Allocate Workspace */
    MORSE_Alloc_Workspace_dgels_Tile(M, N, &descT);
    memset(descT->mat, 0, (descT->llm*descT->lln)*sizeof(MorseRealDouble));

    /* Do the computations */
    START_TIMING();
    MORSE_dgeqrf_Tile( descA, descT );
    STOP_TIMING();

    /* Check the solution */
    if ( check && M == N )
    {
        /* Initialize and save B */
        MORSE_dplrnt_Tile( descX, 2264 );
        MORSE_dlacpy_Tile(MorseUpperLower, descX, descB);

        /* Compute the solution */
        MORSE_dgeqrs_Tile( descA, descT, descX );

        dparam[IPARAM_ANORM] = MORSE_dlange_Tile(MorseInfNorm, descAC);
        dparam[IPARAM_BNORM] = MORSE_dlange_Tile(MorseInfNorm, descB);
        dparam[IPARAM_XNORM] = MORSE_dlange_Tile(MorseInfNorm, descX);
        MORSE_dgemm_Tile( MorseNoTrans, MorseNoTrans, 1.0, descAC, descX, -1.0, descB );
        dparam[IPARAM_RES] = MORSE_dlange_Tile(MorseInfNorm, descB);
        PASTE_CODE_FREE_MATRIX( descX  );
        PASTE_CODE_FREE_MATRIX( descAC );
        PASTE_CODE_FREE_MATRIX( descB  )
    }

    /* Free data */
    MORSE_Dealloc_Workspace(&descT);
    PASTE_CODE_FREE_MATRIX( descA );

    return 0;
}
