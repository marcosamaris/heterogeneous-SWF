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
 * @file basic_cpotrf.c
 *
 *  MORSE example routines
 *  MORSE is a software package provided by Inria Bordeaux - Sud-Ouest, LaBRI,
 *  University of Bordeaux, Bordeaux INP
 *
 * @version 1.0.0
 * @author Florent Pruvost
 * @date 2014-10-13
 * @generated c Tue Sep 26 20:43:19 2017
 *
 **/

#include "posv_morse_functions.h"

int main(int argc, char *argv[]) {

    int N, NB, NCPU, NCUDA;
    MORSE_desc_t *descA = NULL, *descAC = NULL, *descB = NULL, *descX = NULL;

    /* initialize some parameters with default values */
    int iparam[IPARAM_SIZEOF];
    memset(iparam, 0, IPARAM_SIZEOF*sizeof(int));
    init_iparam(iparam);
    iparam[IPARAM_UPLO] = MorseUpper;

    /* read arguments */
    read_args(argc, argv, iparam);
    N  = iparam[IPARAM_N];
    NB = iparam[IPARAM_NB];

    /* initialize the number of thread if not given by the user in argv*/
    if ( iparam[IPARAM_THRDNBR] == -1 ) {
      get_thread_count( &(iparam[IPARAM_THRDNBR]) );
      iparam[IPARAM_THRDNBR] -= iparam[IPARAM_NCUDAS];
    }
    NCPU  = iparam[IPARAM_THRDNBR];
    NCUDA = iparam[IPARAM_NCUDAS];

    printf("N, NB: %d %d\n", N, NB);
    printf("NCPU, NCUDA: %d %d\n", NCPU, NCUDA);

    /* initialize MORSE */
    MORSE_Init( NCPU, NCUDA);
    MORSE_Set(MORSE_TILE_SIZE,        NB );
    MORSE_Set(MORSE_INNER_BLOCK_SIZE, iparam[IPARAM_IB] );

    print_header( argv[0], iparam);

    /*
     * initialize the structure required for MORSE sequential task-based algorithms
     * MORSE_desc_t is a structure wrapping your data allowing MORSE to get
     * pointers to tiles
     */
    MORSE_Desc_Create(&descA, NULL, MorseComplexFloat,
                      NB, NB, NB*NB, N, N, 0, 0, N, N, 1, 1);

    /* generate A matrix with random values such that it is hermitian */
    MORSE_cplghe_Tile( (float)N, descA, 51 );

    /* generate RHS */
    MORSE_Desc_Create(&descB, NULL, MorseComplexFloat,
                      NB, NB, NB*NB, N, 1, 0, 0, N, 1, 1, 1);
    MORSE_cplrnt_Tile( descB, 7672 );

    /* copy A before facto. in order to check the result */
    MORSE_Desc_Create(&descAC, NULL, MorseComplexFloat,
                      NB, NB, NB*NB, N, N, 0, 0, N, N, 1, 1);
    MORSE_clacpy_Tile(MorseUpperLower, descA, descAC);

    /* copy B before solving in order to check the result */
    MORSE_Desc_Create(&descX, NULL, MorseComplexFloat,
                      NB, NB, NB*NB, N, 1, 0, 0, N, 1, 1, 1);
    MORSE_clacpy_Tile(MorseUpperLower, descB, descX);

    /* solve the system AX = B using the Cholesky factorization,
     * A is replaced by its factorization L or L^T depending on uplo
     * B is stored in X on entry, X contains the result on exit */
    MORSE_cposv_Tile(iparam[IPARAM_UPLO], descA, descX);
    /* note that this call is equivalent to
     * MORSE_cpotrf_Tile(uplo, descA) followed by
     * MORSE_cpotrs_Tile(uplo, descA, descX )
     * */

    /* check if solve is correct i.e. AX-B = 0 */
    /* compute norms to check the result */
    float anorm = MORSE_clange_Tile(MorseInfNorm, descAC);
    float bnorm = MORSE_clange_Tile(MorseInfNorm, descB);
    float xnorm = MORSE_clange_Tile(MorseInfNorm, descX);

    /* compute A*X-B, store the result in B */
    MORSE_cgemm_Tile( MorseNoTrans, MorseNoTrans, 1.0, descAC, descX, -1.0, descB );
    float res = MORSE_clange_Tile(MorseInfNorm, descB);

    /* check residual and print a message */
    #if defined(CHAMELEON_SIMULATION)
    float    eps = 0.;
    #else
    float    eps = LAPACKE_slamch_work( 'e' );
    #endif
    /*
     * if hres = 0 then the test succeed
     * else the test failed
     */
    int hres = 0;
    hres = ( res / N / eps / (anorm * xnorm + bnorm ) > 100.0 );
    printf( "   ||Ax-b||       ||A||       ||x||       ||b|| ||Ax-b||/N/eps/(||A||||x||+||b||)  RETURN\n");
    if (hres)
        printf( "%8.5e %8.5e %8.5e %8.5e                       %8.5e FAILURE \n",
            res, anorm, xnorm, bnorm,
            res / N / eps / (anorm * xnorm + bnorm ));
    else
        printf( "%8.5e %8.5e %8.5e %8.5e                       %8.5e SUCCESS \n",
            res, anorm, xnorm, bnorm,
            res / N / eps / (anorm * xnorm + bnorm ));

    /* destroy MORSE specific structures */
    MORSE_Desc_Destroy( &descX  );
    MORSE_Desc_Destroy( &descB  );
    MORSE_Desc_Destroy( &descAC );
    MORSE_Desc_Destroy( &descA  );

    /* Finalize MORSE */
    MORSE_Finalize();

    return EXIT_SUCCESS;
}

