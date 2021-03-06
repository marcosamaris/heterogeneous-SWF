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
 * @file dgetrf_nopiv.c
 *
 *  MORSE computational routines
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.6.0
 * @author Omar Zenati
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2013-02-01
 *
 * @generated d Tue Sep 26 20:43:05 2017
 *
 **/
#include "control/common.h"

/***************************************************************************//**
 *
 * @ingroup double
 *
 *  MORSE_dgetrf_nopiv - Computes an LU factorization of a general M-by-N matrix A
 *  using the tile LU algorithm without row pivoting.
 *  WARNING: Don't use this function if you are not sure your matrix is diagonal
 *  dominant.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A. N >= 0.
 *
 * @param[in,out] A
 *          On entry, the M-by-N matrix to be factored.
 *          On exit, the tile factors L and U from the factorization.
 *
 * @param[in] LDA
 *          The leading dimension of the array A. LDA >= max(1,M).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *          \retval >0 if i, U(i,i) is exactly zero. The factorization has been
 *               completed, but the factor U is exactly singular, and division
 *               by zero will occur if it is used to solve a system of
 *               equations.
 *
 *******************************************************************************
 *
 * @sa MORSE_dgetrf_nopiv_Tile
 * @sa MORSE_dgetrf_nopiv_Tile_Async
 * @sa MORSE_cgetrf_nopiv
 * @sa MORSE_dgetrf_nopiv
 * @sa MORSE_sgetrf_nopiv
 *
 ******************************************************************************/
int MORSE_dgetrf_nopiv(int M, int N,
                       double *A, int LDA)
{
    int NB;
    int status;
    MORSE_desc_t descA ;
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dgetrf_nopiv", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    /* Check input arguments */
    if (M < 0) {
        morse_error("MORSE_dgetrf_nopiv", "illegal value of M");
        return -1;
    }
    if (N < 0) {
        morse_error("MORSE_dgetrf_nopiv", "illegal value of N");
        return -2;
    }
    if (LDA < max(1, M)) {
        morse_error("MORSE_dgetrf_nopiv", "illegal value of LDA");
        return -4;
    }
    /* Quick return */
    if (min(M, N) == 0)
        return MORSE_SUCCESS;

    /* Tune NB & IB depending on M, N & NRHS; Set NBNBSIZE */
    status = morse_tune(MORSE_FUNC_DGESV, M, N, 0);
    if (status != MORSE_SUCCESS) {
        morse_error("MORSE_dgetrf_nopiv", "morse_tune() failed");
        return status;
    }

    /* Set NT & NTRHS */
    NB = MORSE_NB;

    morse_sequence_create(morse, &sequence);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooplap2tile( descA, A, NB, NB, LDA, N, 0, 0, N, N,
                             sequence, &request,
                             morse_desc_mat_free(&(descA)) );
/*    } else {*/
/*        morse_diplap2tile(  descA, A, NB, NB, LDA, N, 0, 0, N, N,*/
/*                             sequence, &request);*/
/*    }*/

    /* Call the tile interface */
    MORSE_dgetrf_nopiv_Tile_Async(&descA, sequence, &request);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooptile2lap(descA, A, NB, NB, LDA, N, sequence, &request );
        RUNTIME_barrier(morse);
        morse_desc_mat_free(&descA);
/*    } else {*/
/*        morse_diptile2lap( descA, A, NB, NB, LDA, N,*/
/*                             sequence, &request );*/
/*        RUNTIME_barrier(morse);*/
/*    }*/

    status = sequence->status;
    morse_sequence_destroy(morse, sequence);

    return status;
}

/***************************************************************************//**
 *
 * @ingroup double_Tile
 *
 *  MORSE_dgetrf_nopiv_Tile - Computes the tile LU factorization of a matrix.
 *  Tile equivalent of MORSE_dgetrf_nopiv().  Operates on matrices stored by
 *  tiles.  All matrices are passed through descriptors.  All dimensions are
 *  taken from the descriptors.
 *
 *******************************************************************************
 *
 * @param[in,out] A
 *          On entry, the M-by-N matrix to be factored.
 *          On exit, the tile factors L and U from the factorization.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval >0 if i, U(i,i) is exactly zero. The factorization has been completed,
 *               but the factor U is exactly singular, and division by zero will occur
 *               if it is used to solve a system of equations.
 *
 *******************************************************************************
 *
 * @sa MORSE_dgetrf_nopiv
 * @sa MORSE_dgetrf_nopiv_Tile_Async
 * @sa MORSE_cgetrf_nopiv_Tile
 * @sa MORSE_dgetrf_nopiv_Tile
 * @sa MORSE_sgetrf_nopiv_Tile
 * @sa MORSE_dgetrs_Tile
 *
 ******************************************************************************/
int MORSE_dgetrf_nopiv_Tile(MORSE_desc_t *A)
{
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    int status;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dgetrf_nopiv_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    morse_sequence_create(morse, &sequence);
    MORSE_dgetrf_nopiv_Tile_Async(A, sequence, &request);
    RUNTIME_barrier(morse);
    RUNTIME_desc_getoncpu(A);
    
    status = sequence->status;
    morse_sequence_destroy(morse, sequence);
    return status;
}

/***************************************************************************//**
 *
 * @ingroup double_Tile_Async
 *
 *  MORSE_dgetrf_nopiv_Tile_Async - Computes the tile LU factorization of a
 *  matrix.  Non-blocking equivalent of MORSE_dgetrf_nopiv_Tile().  May return
 *  before the computation is finished.  Allows for pipelining of operations ar
 *  runtime.
 *
 *******************************************************************************
 *
 * @param[in,out] A
 *          On entry, the M-by-N matrix to be factored.
 *          On exit, the tile factors L and U from the factorization.
 *
 * @param[in] sequence
 *          Identifies the sequence of function calls that this call belongs to
 *          (for completion checks and exception handling purposes).
 *
 * @param[out] request
 *          Identifies this function call (for exception handling purposes).
 *
 *******************************************************************************
 *
 * @sa MORSE_dgetrf_nopiv
 * @sa MORSE_dgetrf_nopiv_Tile
 * @sa MORSE_cgetrf_nopiv_Tile_Async
 * @sa MORSE_dgetrf_nopiv_Tile_Async
 * @sa MORSE_sgetrf_nopiv_Tile_Async
 * @sa MORSE_dgetrs_Tile_Async
 *
 ******************************************************************************/
int MORSE_dgetrf_nopiv_Tile_Async(MORSE_desc_t *A,
                                  MORSE_sequence_t *sequence,
                                  MORSE_request_t *request)
{
    MORSE_context_t *morse;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dgetrf_nopiv_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    if (sequence == NULL) {
        morse_fatal_error("MORSE_dgetrf_nopiv_Tile", "NULL sequence");
        return MORSE_ERR_UNALLOCATED;
    }
    if (request == NULL) {
        morse_fatal_error("MORSE_dgetrf_nopiv_Tile", "NULL request");
        return MORSE_ERR_UNALLOCATED;
    }
    /* Check sequence status */
    if (sequence->status == MORSE_SUCCESS)
        request->status = MORSE_SUCCESS;
    else
        return morse_request_fail(sequence, request, MORSE_ERR_SEQUENCE_FLUSHED);

    /* Check descriptors for correctness */
    if (morse_desc_check(A) != MORSE_SUCCESS) {
        morse_error("MORSE_dgetrf_nopiv_Tile", "invalid first descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }

    /* Check input arguments */
    if (A->nb != A->mb) {
        morse_error("MORSE_dgetrf_nopiv_Tile", "only square tiles supported");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }

    morse_pdgetrf_nopiv(A, sequence, request);

    return MORSE_SUCCESS;
}
