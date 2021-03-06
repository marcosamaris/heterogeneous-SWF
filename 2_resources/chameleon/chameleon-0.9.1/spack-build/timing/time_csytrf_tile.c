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
 * @generated c Tue Sep 26 20:43:24 2017
 *
 **/
#define _TYPE  MORSE_Complex32_t
#define _PREC  float
#define _LAMCH LAPACKE_slamch_work

#define _NAME  "MORSE_csytrf_Tile"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_SYTRF( N )
#define _FADDS FADDS_SYTRF( N )

#include "./timing.c"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_)
{
    PASTE_CODE_IPARAM_LOCALS( iparam );
    int uplo = MorseUpper;

    LDA = max(LDA, N);

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA,  1,     MORSE_Complex32_t, MorseComplexFloat, LDA, N, N    );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descB,  check, MORSE_Complex32_t, MorseComplexFloat, LDB, N, NRHS );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descAC, check, MORSE_Complex32_t, MorseComplexFloat, LDA, N, N    );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descX,  check, MORSE_Complex32_t, MorseComplexFloat, LDB, N, NRHS );
    MORSE_cplgsy_Tile( (float)N, descA, 51 );

    /* Save A for check */
    if (check == 1){
        MORSE_clacpy_Tile(MorseUpperLower, descA, descAC);
    }

    /* MORSE CSYSV */
    START_TIMING();
    MORSE_csytrf_Tile(uplo, descA);
    STOP_TIMING();

    /* Check the solution */
    if ( check )
    {
        MORSE_cplrnt_Tile( descB, 7672 );
        MORSE_clacpy_Tile(MorseUpperLower, descB, descX);
        MORSE_csytrs_Tile( uplo, descA, descX );
        dparam[IPARAM_ANORM] = MORSE_clange_Tile(MorseInfNorm, descAC);
        dparam[IPARAM_BNORM] = MORSE_clange_Tile(MorseInfNorm, descB);
        dparam[IPARAM_XNORM] = MORSE_clange_Tile(MorseInfNorm, descX);
		MORSE_cgemm_Tile( MorseNoTrans, MorseNoTrans, 1.0, descAC, descX, -1.0, descB );
		dparam[IPARAM_RES] = MORSE_clange_Tile(MorseInfNorm, descB);

        PASTE_CODE_FREE_MATRIX( descB  );
        PASTE_CODE_FREE_MATRIX( descAC );
        PASTE_CODE_FREE_MATRIX( descX  );

    } 
	
    PASTE_CODE_FREE_MATRIX( descA );
    MORSE_TASK_dataflush_all();

    return 0;
}
