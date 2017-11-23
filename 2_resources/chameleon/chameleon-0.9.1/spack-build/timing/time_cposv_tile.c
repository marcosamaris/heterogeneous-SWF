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

#define _NAME  "MORSE_cposv_Tile"
/* See Lawn 41 page 120 */
#define _FMULS (FMULS_POTRF( N ) + FMULS_POTRS( N, NRHS ))
#define _FADDS (FADDS_POTRF( N ) + FADDS_POTRS( N, NRHS ))

#include "./timing.c"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_)
{
    PASTE_CODE_IPARAM_LOCALS( iparam );
    MORSE_enum uplo = MorseUpper;

    LDA = max(LDA, N);

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA, 1,      MORSE_Complex32_t, MorseComplexFloat, LDA, N, N );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descX, 1,      MORSE_Complex32_t, MorseComplexFloat, LDB, N, NRHS );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descAC, check, MORSE_Complex32_t, MorseComplexFloat, LDA, N, N );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descB,  check, MORSE_Complex32_t, MorseComplexFloat, LDB, N, NRHS );

    /* Initialize AT and bT for Symmetric Positif Matrix */
    MORSE_cplghe_Tile((float)N, descA, 51 );
    MORSE_cplrnt_Tile( descX, 7732 );

    /* Save AT and bT for check */
    if (check == 1){
        MORSE_clacpy_Tile(MorseUpperLower, descA, descAC);
        MORSE_clacpy_Tile(MorseUpperLower, descX, descB);
    }
    /* MORSE CPOSV */
    START_TIMING();
    MORSE_cposv_Tile(uplo, descA, descX);
    STOP_TIMING();

    /* Check the solution */
    if (check)
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

    return 0;
}
