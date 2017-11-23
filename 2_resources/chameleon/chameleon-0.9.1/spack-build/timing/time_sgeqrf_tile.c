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

#define _NAME  "MORSE_sgeqrf_Tile"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_GEQRF( M, N )
#define _FADDS FADDS_GEQRF( M, N )

#include "./timing.c"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_)
{
    MORSE_desc_t *descT;
    PASTE_CODE_IPARAM_LOCALS( iparam );

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA,  1, float, MorseRealFloat, LDA, M, N );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descX,  ( check && M == N ), float, MorseRealFloat, LDB, M, NRHS );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descAC, ( check && M == N ), float, MorseRealFloat, LDA, M, N    );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descB,  ( check && M == N ), float, MorseRealFloat, LDB, M, NRHS );

    MORSE_splrnt_Tile( descA, 5373 );

    /* Save A for check */
    if (check == 1 && M == N){
        MORSE_slacpy_Tile(MorseUpperLower, descA, descAC);
    }

    /* Allocate Workspace */
    MORSE_Alloc_Workspace_sgels_Tile(M, N, &descT);
    memset(descT->mat, 0, (descT->llm*descT->lln)*sizeof(MorseRealFloat));

    /* Do the computations */
    START_TIMING();
    MORSE_sgeqrf_Tile( descA, descT );
    STOP_TIMING();

    /* Check the solution */
    if ( check && M == N )
    {
        /* Initialize and save B */
        MORSE_splrnt_Tile( descX, 2264 );
        MORSE_slacpy_Tile(MorseUpperLower, descX, descB);

        /* Compute the solution */
        MORSE_sgeqrs_Tile( descA, descT, descX );

        dparam[IPARAM_ANORM] = MORSE_slange_Tile(MorseInfNorm, descAC);
        dparam[IPARAM_BNORM] = MORSE_slange_Tile(MorseInfNorm, descB);
        dparam[IPARAM_XNORM] = MORSE_slange_Tile(MorseInfNorm, descX);
        MORSE_sgemm_Tile( MorseNoTrans, MorseNoTrans, 1.0, descAC, descX, -1.0, descB );
        dparam[IPARAM_RES] = MORSE_slange_Tile(MorseInfNorm, descB);
        PASTE_CODE_FREE_MATRIX( descX  );
        PASTE_CODE_FREE_MATRIX( descAC );
        PASTE_CODE_FREE_MATRIX( descB  )
    }

    /* Free data */
    MORSE_Dealloc_Workspace(&descT);
    PASTE_CODE_FREE_MATRIX( descA );

    return 0;
}
