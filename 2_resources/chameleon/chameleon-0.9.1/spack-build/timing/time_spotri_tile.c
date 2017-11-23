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

#define _NAME  "MORSE_spotri_Tile"
/* See Lawn 41 page 120 */
#define _FMULS (FMULS_POTRF( N ) + FMULS_POTRI( N ))
#define _FADDS (FADDS_POTRF( N ) + FADDS_POTRI( N ))

//#define POTRI_SYNC

#include "./timing.c"

static int
RunTest(int *iparam, float *dparam, morse_time_t *t_) 
{
    PASTE_CODE_IPARAM_LOCALS( iparam );
    MORSE_enum uplo = MorseLower;

    LDA = max(LDA, N);

    /* Allocate Data */
    PASTE_CODE_ALLOCATE_MATRIX_TILE( descA, 1, float, MorseRealFloat, LDA, N, N );

    /* 
     * Initialize Data 
     * It's done in static to avoid having the same sequence than one 
     * the function we want to trace
     */
    MORSE_splgsy_Tile( (float)N, descA, 51 );

    /* MORSE SPOTRF / STRTRI / SLAUUM  */
    /*
     * Example of the different way to combine several asynchonous calls
     */
#if defined(TRACE_BY_SEQUENCE)
    {
        MORSE_sequence_t *sequence[3];
        MORSE_request_t request[3] = { MORSE_REQUEST_INITIALIZER,
                                       MORSE_REQUEST_INITIALIZER,
                                       MORSE_REQUEST_INITIALIZER };

        MORSE_Sequence_Create(&sequence[0]);
        MORSE_Sequence_Create(&sequence[1]);
        MORSE_Sequence_Create(&sequence[2]);

        if ( ! iparam[IPARAM_ASYNC] ) {
            START_TIMING();

            MORSE_spotrf_Tile_Async(uplo, descA,                sequence[0], &request[0]);
            MORSE_Sequence_Wait(sequence[0]);

            MORSE_strtri_Tile_Async(uplo, MorseNonUnit, descA, sequence[1], &request[1]);
            MORSE_Sequence_Wait(sequence[1]);

            MORSE_slauum_Tile_Async(uplo, descA,                sequence[2], &request[2]);
            MORSE_Sequence_Wait(sequence[2]);
            MORSE_Desc_Getoncpu( descA );
            STOP_TIMING();

        } else {

            START_TIMING();
            MORSE_spotrf_Tile_Async(uplo, descA,                sequence[0], &request[0]);
            MORSE_strtri_Tile_Async(uplo, MorseNonUnit, descA, sequence[1], &request[1]);
            MORSE_slauum_Tile_Async(uplo, descA,                sequence[2], &request[2]);

            MORSE_Sequence_Wait(sequence[0]);
            MORSE_Sequence_Wait(sequence[1]);
            MORSE_Sequence_Wait(sequence[2]);
            MORSE_Desc_Getoncpu( descA );
            STOP_TIMING();
        }

        MORSE_Sequence_Destroy(sequence[0]);
        MORSE_Sequence_Destroy(sequence[1]);
        MORSE_Sequence_Destroy(sequence[2]);
    }
#else
    {
        if ( ! iparam[IPARAM_ASYNC] ) {

            START_TIMING();
            MORSE_spotrf_Tile(uplo, descA);
            MORSE_strtri_Tile(uplo, MorseNonUnit, descA);
            MORSE_slauum_Tile(uplo, descA);
            STOP_TIMING();

        } else {

            /* Default: we use Asynchonous call with only one sequence */
            MORSE_sequence_t *sequence;
            MORSE_request_t request[2] = { MORSE_REQUEST_INITIALIZER,
                                           MORSE_REQUEST_INITIALIZER };

            START_TIMING();
            MORSE_Sequence_Create(&sequence);
            MORSE_spotrf_Tile_Async(uplo, descA, sequence, &request[0]);
            MORSE_spotri_Tile_Async(uplo, descA, sequence, &request[1]);
            MORSE_Sequence_Wait(sequence);
            MORSE_Desc_Getoncpu( descA );
            STOP_TIMING();

            MORSE_Sequence_Destroy(sequence);
        }
    }
#endif

    /* Check the solution */
    if ( check )
    {
        dparam[IPARAM_ANORM] = 0.0;
        dparam[IPARAM_XNORM] = 0.0;
        dparam[IPARAM_BNORM] = 0.0;
        dparam[IPARAM_RES]   = 0.0;
    }

    PASTE_CODE_FREE_MATRIX( descA );

    return 0;
}
