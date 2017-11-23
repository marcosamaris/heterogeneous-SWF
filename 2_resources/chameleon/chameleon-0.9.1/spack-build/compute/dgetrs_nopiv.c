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
 * @file dgetrs_nopiv.c
 *
 *  MORSE computational routines
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Jakub Kurzak
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @author Florent Pruvost
 * @date 2014-11-08
 * @generated d Tue Sep 26 20:43:05 2017
 *
 **/
#include "control/common.h"

/***************************************************************************//**
 *
 * @ingroup double
 *
 *  MORSE_dgetrs_nopiv - Solves a system of linear equations A * X = B, with a general N-by-N matrix A
 *  using the tile LU factorization computed by MORSE_dgetrf_nopiv.
 *
 *******************************************************************************
 *
 * @param[in] trans
 *          Intended to specify the the form of the system of equations:
 *          = MorseNoTrans:   A * X = B     (No transpose)
 *          = MorseTrans:     A**T * X = B  (Transpose)
 *          = MorseTrans: A**T * X = B  (Conjugate transpose)
 *          Currently only MorseNoTrans is supported.
 *
 * @param[in] N
 *          The order of the matrix A.  N >= 0.
 *
 * @param[in] NRHS
 *          The number of right hand sides, i.e., the number of columns of the matrix B.
 *          NRHS >= 0.
 *
 * @param[in] A
 *          The tile factors L and U from the factorization, computed by MORSE_dgetrf_nopiv.
 *
 * @param[in] LDA
 *          The leading dimension of the array A. LDA >= max(1,N).
 *
 * @param[in,out] B
 *          On entry, the N-by-NRHS matrix of right hand side matrix B.
 *          On exit, the solution matrix X.
 *
 * @param[in] LDB
 *          The leading dimension of the array B. LDB >= max(1,N).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \return <0 if -i, the i-th argument had an illegal value
 *
 *******************************************************************************
 *
 * @sa MORSE_dgetrs_nopiv_Tile
 * @sa MORSE_dgetrs_nopiv_Tile_Async
 * @sa MORSE_cgetrs_nopiv
 * @sa MORSE_dgetrs_nopiv
 * @sa MORSE_sgetrs_nopiv
 * @sa MORSE_dgetrf_nopiv
 *
 ******************************************************************************/
int MORSE_dgetrs_nopiv(MORSE_enum trans, int N, int NRHS,
                       double *A, int LDA,
                       double *B, int LDB)
{
    int NB;
    int status;
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    MORSE_desc_t descA, descB;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dgetrs_nopiv", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    /* Check input arguments */
    if (trans != MorseNoTrans) {
        morse_error("MORSE_dgetrs_nopiv", "only MorseNoTrans supported");
        return MORSE_ERR_NOT_SUPPORTED;
    }
    if (N < 0) {
        morse_error("MORSE_dgetrs_nopiv", "illegal value of N");
        return -2;
    }
    if (NRHS < 0) {
        morse_error("MORSE_dgetrs_nopiv", "illegal value of NRHS");
        return -3;
    }
    if (LDA < max(1, N)) {
        morse_error("MORSE_dgetrs_nopiv", "illegal value of LDA");
        return -5;
    }
    if (LDB < max(1, N)) {
        morse_error("MORSE_dgetrs_nopiv", "illegal value of LDB");
        return -9;
    }
    /* Quick return */
    if (min(N, NRHS) == 0)
        return MORSE_SUCCESS;

    /* Tune NB & IB depending on N & NRHS; Set NBNBSIZE */
    status = morse_tune(MORSE_FUNC_DGESV, N, N, NRHS);
    if (status != MORSE_SUCCESS) {
        morse_error("MORSE_dgetrs_nopiv", "morse_tune() failed");
        return status;
    }

    /* Set NT & NTRHS */
    NB    = MORSE_NB;

    morse_sequence_create(morse, &sequence);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooplap2tile( descA, A, NB, NB, LDA, N,    0, 0, N, N,    sequence, &request,
                             morse_desc_mat_free(&(descA)) );
        morse_dooplap2tile( descB, B, NB, NB, LDB, NRHS, 0, 0, N, NRHS, sequence, &request,
                             morse_desc_mat_free(&(descA)); morse_desc_mat_free(&(descB)));
/*    } else {*/
/*        morse_diplap2tile( descA, A, NB, NB, LDA, N,    0, 0, N, N,   */
/*                            sequence, &request);*/
/*        morse_diplap2tile( descB, B, NB, NB, LDB, NRHS, 0, 0, N, NRHS,*/
/*                            sequence, &request);*/
/*    }*/

    /* Call the tile interface */
    MORSE_dgetrs_nopiv_Tile_Async(&descA, &descB, sequence, &request);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooptile2lap(descB, B, NB, NB, LDB, NRHS,  sequence, &request);
        RUNTIME_barrier(morse);
        morse_desc_mat_free(&descA);
        morse_desc_mat_free(&descB);
/*    } else {*/
/*        morse_diptile2lap( descA, A, NB, NB, LDA, N,     sequence, &request);*/
/*        morse_diptile2lap( descB, B, NB, NB, LDB, NRHS,  sequence, &request);*/
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
 *  MORSE_dgetrs_nopiv_Tile - Solves a system of linear equations using previously
 *  computed LU factorization.
 *  Tile equivalent of MORSE_dgetrs_nopiv().
 *  Operates on matrices stored by tiles.
 *  All matrices are passed through descriptors.
 *  All dimensions are taken from the descriptors.
 *
 *******************************************************************************
 *
 * @param[in] A
 *          The tile factors L and U from the factorization, computed by MORSE_dgetrf_nopiv.
 *
 * @param[in,out] B
 *          On entry, the N-by-NRHS matrix of right hand side matrix B.
 *          On exit, the solution matrix X.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *******************************************************************************
 *
 * @sa MORSE_dgetrs_nopiv
 * @sa MORSE_dgetrs_nopiv_Tile_Async
 * @sa MORSE_cgetrs_nopiv_Tile
 * @sa MORSE_dgetrs_nopiv_Tile
 * @sa MORSE_sgetrs_nopiv_Tile
 * @sa MORSE_dgetrf_nopiv_Tile
 *
 ******************************************************************************/
int MORSE_dgetrs_nopiv_Tile(MORSE_desc_t *A, MORSE_desc_t *B)
{
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    int status;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dgetrs_nopiv_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    morse_sequence_create(morse, &sequence);
    MORSE_dgetrs_nopiv_Tile_Async(A, B, sequence, &request);
    RUNTIME_barrier(morse);
    RUNTIME_desc_getoncpu(A);
    RUNTIME_desc_getoncpu(B);
    
    status = sequence->status;
    morse_sequence_destroy(morse, sequence);
    return status;
}

/***************************************************************************//**
 *
 * @ingroup double_Tile_Async
 *
 *  MORSE_dgetrs_nopiv_Tile_Async - Solves a system of linear equations using previously
 *  computed LU factorization.
 *  Non-blocking equivalent of MORSE_dgetrs_nopiv_Tile().
 *  May return before the computation is finished.
 *  Allows for pipelining of operations at runtime.
 *
 *******************************************************************************
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
 * @sa MORSE_dgetrs_nopiv
 * @sa MORSE_dgetrs_nopiv_Tile
 * @sa MORSE_cgetrs_nopiv_Tile_Async
 * @sa MORSE_dgetrs_nopiv_Tile_Async
 * @sa MORSE_sgetrs_nopiv_Tile_Async
 * @sa MORSE_dgetrf_nopiv_Tile_Async
 *
 ******************************************************************************/
int MORSE_dgetrs_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *B,
                                  MORSE_sequence_t *sequence, MORSE_request_t *request)
{
    MORSE_context_t *morse;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dgetrs_nopiv_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    if (sequence == NULL) {
        morse_fatal_error("MORSE_dgetrs_nopiv_Tile", "NULL sequence");
        return MORSE_ERR_UNALLOCATED;
    }
    if (request == NULL) {
        morse_fatal_error("MORSE_dgetrs_nopiv_Tile", "NULL request");
        return MORSE_ERR_UNALLOCATED;
    }
    /* Check sequence status */
    if (sequence->status == MORSE_SUCCESS)
        request->status = MORSE_SUCCESS;
    else
        return morse_request_fail(sequence, request, MORSE_ERR_SEQUENCE_FLUSHED);

    /* Check descriptors for correctness */
    if (morse_desc_check(A) != MORSE_SUCCESS) {
        morse_error("MORSE_dgetrs_nopiv_Tile", "invalid first descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (morse_desc_check(B) != MORSE_SUCCESS) {
        morse_error("MORSE_dgetrs_nopiv_Tile", "invalid third descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    /* Check input arguments */
    if (A->nb != A->mb || B->nb != B->mb) {
        morse_error("MORSE_dgetrs_nopiv_Tile", "only square tiles supported");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    /* Quick return */
/*
    if (min(N, NRHS) == 0)
        return MORSE_SUCCESS;
*/
    morse_pdtrsm(MorseLeft, MorseLower, MorseNoTrans, MorseUnit, (double)1.0, A, B, sequence, request);

    morse_pdtrsm(MorseLeft, MorseUpper, MorseNoTrans, MorseNonUnit, (double)1.0, A, B, sequence, request);

    return MORSE_SUCCESS;
}
