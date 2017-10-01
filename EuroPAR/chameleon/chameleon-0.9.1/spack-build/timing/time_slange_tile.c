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
 * @generated s Tue Sep 26 20:43:25 2017
 *
 **/
#define _TYPE  float
#define _PREC  float
#define _LAMCH LAPACKE_slamch_work

#define _NAME  "MORSE_slange_Tile"
/* See Lawn 41 page 120 */
#define _FMULS FMULS_LANGE(M, N)
#define _FADDS FADDS_LANGE(M, N)

#include "./timing.c"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_)
{
    float normmorse, normlapack, result;
    float eps;
    int   norm[4] = { MorseMaxNorm, MorseOneNorm, MorseInfNorm, MorseFrobeniusNorm };
    PASTE_CODE_IPARAM_LOCALS( iparam );

    eps = LAPACKE_slamch_work('e');

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA, 1,     float, MorseRealFloat, LDA, M, N    );
    MORSE_splrnt_Tile( descA, 3436 );

    /* MORSE SPOSV */
    START_TIMING();
    normmorse = MORSE_slange_Tile(MorseInfNorm, descA);
    STOP_TIMING();

    /* Check the solution */
    if ( check )
    {
        /* Allocate Data */
        PASTE_TILE_TO_LAPACK( descA, A, check, float, M, N );
        float *work = (float*) malloc(max(M,N)*sizeof(float));
        normlapack = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, A, LDA, work);
        result = fabs(normmorse - normlapack);
        switch(norm[2]) {
        case MorseMaxNorm:
            /* result should be perfectly equal */
            break;
        case MorseInfNorm:
            /* Sum order on the line can differ */
            result = result / (float)N;
            break;
        case MorseOneNorm:
            /* Sum order on the column can differ */
            result = result / (float)M;
            break;
        case MorseFrobeniusNorm:
            /* Sum oreder on every element can differ */
            result = result / ((float)M * (float)N);
            break;
        }
        if ( MORSE_My_Mpi_Rank() == 0 ) {
            dparam[IPARAM_ANORM] = normlapack;
            dparam[IPARAM_BNORM] = 0.;
            dparam[IPARAM_XNORM] = 1.;
            dparam[IPARAM_RES] = result;
        }
        free( work );
        free( A );
    }

    PASTE_CODE_FREE_MATRIX( descA );

    return 0;
}
