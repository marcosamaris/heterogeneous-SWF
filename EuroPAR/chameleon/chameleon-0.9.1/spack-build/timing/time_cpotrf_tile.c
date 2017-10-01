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

#define _NAME  "MORSE_cpotrf_Tile"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_POTRF( N )
#define _FADDS FADDS_POTRF( N )

#include "./timing.c"
#include "timing_cauxiliary.h"

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
    MORSE_cplghe_Tile( (float)N, descA, 51 );

    /* Save A for check */
    //PASTE_TILE_TO_LAPACK( descA, A, check, MORSE_Complex32_t, LDA, N );
    if (check == 1){
        MORSE_clacpy_Tile(MorseUpperLower, descA, descAC);
    }

    //RUNTIME_clocality_allrestrict( STARPU_CUDA );

    /* MORSE CPOSV */
    START_TIMING();
    MORSE_cpotrf_Tile(uplo, descA);
    STOP_TIMING();

    /* Check the solution */
    if ( check )
    {
        MORSE_cplrnt_Tile( descB, 7672 );

//        PASTE_TILE_TO_LAPACK( descB, B, check, MORSE_Complex32_t, LDB, NRHS );
//        MORSE_cpotrs_Tile( uplo, descA, descB );
//        PASTE_TILE_TO_LAPACK( descB, X, check, MORSE_Complex32_t, LDB, NRHS );
//        /* LAPACK check */
//        if ( MORSE_My_Mpi_Rank() == 0 ) {
//            dparam[IPARAM_RES] = c_check_solution(N, N, NRHS, A, LDA, B, X, LDB,
//                                                &(dparam[IPARAM_ANORM]),
//                                                &(dparam[IPARAM_BNORM]),
//                                                &(dparam[IPARAM_XNORM]));
//        }

        MORSE_clacpy_Tile(MorseUpperLower, descB, descX);
        MORSE_cpotrs_Tile( uplo, descA, descX );
        dparam[IPARAM_ANORM] = MORSE_clange_Tile(MorseInfNorm, descAC);
        dparam[IPARAM_BNORM] = MORSE_clange_Tile(MorseInfNorm, descB);
        dparam[IPARAM_XNORM] = MORSE_clange_Tile(MorseInfNorm, descX);
//		if ( MORSE_My_Mpi_Rank() == 0 )
//			printf("Morse anorm, xnorm, bnorm: %e,%e,%e\n",dparam[IPARAM_ANORM],dparam[IPARAM_XNORM],dparam[IPARAM_BNORM]);
		MORSE_cgemm_Tile( MorseNoTrans, MorseNoTrans, 1.0, descAC, descX, -1.0, descB );
		dparam[IPARAM_RES] = MORSE_clange_Tile(MorseInfNorm, descB);

        PASTE_CODE_FREE_MATRIX( descB  );
//        free( A );
//        free( B );
//        free( X );
        PASTE_CODE_FREE_MATRIX( descAC );
        PASTE_CODE_FREE_MATRIX( descX  );

    }
    PASTE_CODE_FREE_MATRIX( descA );
    MORSE_TASK_dataflush_all();

    return 0;
}
