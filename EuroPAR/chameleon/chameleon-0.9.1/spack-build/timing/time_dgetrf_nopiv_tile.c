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

#define _NAME  "MORSE_dgetrf_Tile"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_GETRF(M, N)
#define _FADDS FADDS_GETRF(M, N)

#include "./timing.c"

static int
RunTest(int *iparam, double *dparam, morse_time_t *t_) 
{
    PASTE_CODE_IPARAM_LOCALS( iparam );

    if ( M != N && check ) {
        fprintf(stderr, "Check cannot be perfomed with M != N\n");
        check = 0;
    }

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA, 1, double, MorseRealDouble, LDA, M, N );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descX,  check, double, MorseRealDouble, LDB, M, NRHS );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descAC, check, double, MorseRealDouble, LDA, M, N    );
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descB,  check, double, MorseRealDouble, LDB, M, NRHS );
    
    MORSE_dplrnt_Tile(descA, 3456);

    /* Save A for check */
    if (check == 1){
        MORSE_dlacpy_Tile(MorseUpperLower, descA, descAC);
    }
    
    START_TIMING();
    MORSE_dgetrf_nopiv_Tile( descA );
    STOP_TIMING();
    
    /* Check the solution */
    if ( check )
    {
        MORSE_dplrnt_Tile( descX, 7732 );
        MORSE_dlacpy_Tile(MorseUpperLower, descX, descB);

        MORSE_dgetrs_nopiv_Tile( descA, descX );

        dparam[IPARAM_ANORM] = MORSE_dlange_Tile(MorseInfNorm, descAC);
        dparam[IPARAM_BNORM] = MORSE_dlange_Tile(MorseInfNorm, descB);
        dparam[IPARAM_XNORM] = MORSE_dlange_Tile(MorseInfNorm, descX);
        MORSE_dgemm_Tile( MorseNoTrans, MorseNoTrans, 1.0, descAC, descX, -1.0, descB );
        dparam[IPARAM_RES] = MORSE_dlange_Tile(MorseInfNorm, descB);
        PASTE_CODE_FREE_MATRIX( descX  );
        PASTE_CODE_FREE_MATRIX( descAC );
        PASTE_CODE_FREE_MATRIX( descB  );
    }

    PASTE_CODE_FREE_MATRIX( descA );
 
    return 0;
}
