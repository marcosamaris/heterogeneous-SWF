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
 * @generated c Tue Sep 26 20:43:25 2017
 *
 **/
#define _TYPE  MORSE_Complex32_t
#define _PREC  float
#define _LAMCH LAPACKE_slamch_work

#define _NAME  "MORSE_cgesv_incpiv_Tile"
/* See Lawn 41 page 120 */
#define _FMULS (FMULS_GETRF( N, N ) + FMULS_GETRS( N, NRHS ))
#define _FADDS (FADDS_GETRF( N, N ) + FADDS_GETRS( N, NRHS ))

#include "./timing.c"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_) 
{
    MORSE_desc_t *descL;
    int *piv;
    PASTE_CODE_IPARAM_LOCALS( iparam );
    
    if ( M != N ) {
        fprintf(stderr, "This timing works only with M == N\n");
        return -1;
    }
    
    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA, 1, MORSE_Complex32_t, MorseComplexFloat, LDA, N, N    );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descX, 1,      MORSE_Complex32_t, MorseComplexFloat, LDB, N, NRHS );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descAC, check, MORSE_Complex32_t, MorseComplexFloat, LDA, N, N );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descB,  check, MORSE_Complex32_t, MorseComplexFloat, LDB, N, NRHS );;

    /* Initialize A and b */
    MORSE_cplrnt_Tile( descA, 8796 );
    MORSE_cplrnt_Tile( descX, 7732 );

    /* Save AT and bT in lapack layout for check */
    /* Save AT and bT for check */
    if (check == 1){
        MORSE_clacpy_Tile(MorseUpperLower, descA, descAC);
        MORSE_clacpy_Tile(MorseUpperLower, descX, descB);
    }

    /* Allocate Workspace */
    MORSE_Alloc_Workspace_cgesv_incpiv_Tile(N, &descL, &piv);

    START_TIMING();
    MORSE_cgesv_incpiv_Tile( descA, descL, piv, descX );
    STOP_TIMING();
    
    /* Allocate Workspace */
    MORSE_Dealloc_Workspace(&descL);

    /* Check the solution */
    if ( check )
    {
        dparam[IPARAM_ANORM] = MORSE_clange_Tile(MorseInfNorm, descAC);
        dparam[IPARAM_BNORM] = MORSE_clange_Tile(MorseInfNorm, descB);
        dparam[IPARAM_XNORM] = MORSE_clange_Tile(MorseInfNorm, descX);
        MORSE_cgemm_Tile( MorseNoTrans, MorseNoTrans, 1.0, descAC, descX, -1.0, descB );
        dparam[IPARAM_RES] = MORSE_clange_Tile(MorseInfNorm, descB);
        PASTE_CODE_FREE_MATRIX( descAC );
        PASTE_CODE_FREE_MATRIX( descB  );
    }

    PASTE_CODE_FREE_MATRIX( descA );
    PASTE_CODE_FREE_MATRIX( descX );
    free( piv );

    return 0;
}
