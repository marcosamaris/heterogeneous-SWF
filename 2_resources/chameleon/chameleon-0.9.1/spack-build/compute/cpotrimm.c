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
 * @file cpotrimm.c
 *
 *  MORSE computational routines
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated c Tue Sep 26 20:43:08 2017
 *
 **/
#include "control/common.h"

/***************************************************************************//**
 *
 * @ingroup MORSE_Complex32_t
 *
 *  MORSE_cpotrimm - Computes the inverse of a complex Hermitian positive definite
 *  matrix A using the Cholesky factorization A = U**H*U or A = L*L**H
 *  computed by MORSE_cpotrf.
 *
 *******************************************************************************
 *
 * @param[in] uplo
 *          = MorseUpper: Upper triangle of A is stored;
 *          = MorseLower: Lower triangle of A is stored.
 *
 * @param[in] N
 *          The order of the matrix A. N >= 0.
 *
 * @param[in,out] A
 *          On entry, the triangular factor U or L from the Cholesky
 *          factorization A = U**H*U or A = L*L**H, as computed by
 *          MORSE_cpotrf.
 *          On exit, the upper or lower triangle of the (Hermitian)
 *          inverse of A, overwriting the input factor U or L.
 *
 * @param[in] LDA
 *          The leading dimension of the array A. LDA >= max(1,N).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *          \retval >0 if i, the (i,i) element of the factor U or L is
 *                zero, and the inverse could not be computed.
 *
 *******************************************************************************
 *
 * @sa MORSE_cpotrimm_Tile
 * @sa MORSE_cpotrimm_Tile_Async
 * @sa MORSE_cpotri
 * @sa MORSE_dpotri
 * @sa MORSE_spotri
 * @sa MORSE_cpotrf
 *
 ******************************************************************************/
int MORSE_cpotrimm(MORSE_enum uplo, int N,
                  MORSE_Complex32_t *A, int LDA,
                  MORSE_Complex32_t *B, int LDB,
                  MORSE_Complex32_t *C, int LDC)
{
    int NB;
    int status;
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    MORSE_desc_t descA, descB, descC;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_cpotrimm", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    /* Check input arguments */
    if (uplo != MorseUpper && uplo != MorseLower) {
        morse_error("MORSE_cpotrimm", "illegal value of uplo");
        return -1;
    }
    if (N < 0) {
        morse_error("MORSE_cpotrimm", "illegal value of N");
        return -2;
    }
    if (LDA < max(1, N)) {
        morse_error("MORSE_cpotrimm", "illegal value of LDA");
        return -4;
    }
    if (LDB < max(1, N)) {
        morse_error("MORSE_cpotrimm", "illegal value of LDB");
        return -6;
    }
    if (LDC < max(1, N)) {
        morse_error("MORSE_cpotrimm", "illegal value of LDC");
        return -8;
    }
    /* Quick return */
    if (max(N, 0) == 0)
        return MORSE_SUCCESS;

    /* Tune NB depending on M, N & NRHS; Set NBNB */
    status = morse_tune(MORSE_FUNC_CPOSV, N, N, 0);
    if (status != MORSE_SUCCESS) {
        morse_error("MORSE_cpotrimm", "morse_tune() failed");
        return status;
    }

    /* Set NT */
    NB   = MORSE_NB;

    morse_sequence_create(morse, &sequence);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_cooplap2tile( descA, A, NB, NB, LDA, N, 0, 0, N, N, sequence, &request,
                             morse_desc_mat_free(&(descA)) );
        morse_cooplap2tile( descB, B, NB, NB, LDB, N, 0, 0, N, N, sequence, &request,
                             morse_desc_mat_free(&(descA)); morse_desc_mat_free(&(descB)));
        morse_cooplap2tile( descC, C, NB, NB, LDC, N, 0, 0, N, N,  sequence, &request,
                             morse_desc_mat_free(&(descA)); morse_desc_mat_free(&(descB)); morse_desc_mat_free(&(descC)));
/*    } else {*/
/*        morse_ciplap2tile(  descA, A, NB, NB, LDA, N, 0, 0, N, N,*/
/*                            sequence, &request);*/
/*    }*/

    /* Call the tile interface */
    MORSE_cpotrimm_Tile_Async(uplo, &descA, &descB, &descC, sequence, &request);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_cooptile2lap(descA, A, NB, NB, LDA, N,  sequence, &request);
        morse_cooptile2lap(descB, A, NB, NB, LDB, N,  sequence, &request);
        morse_cooptile2lap(descC, C, NB, NB, LDC, N,  sequence, &request);
        RUNTIME_barrier(morse);
        morse_desc_mat_free(&descA);
        morse_desc_mat_free(&descB);
        morse_desc_mat_free(&descC);
/*    } else {*/
/*        morse_ciptile2lap( descA, A, NB, NB, LDA, N,  sequence, &request);*/
/*        RUNTIME_barrier(morse);*/
/*    }*/

    status = sequence->status;
    morse_sequence_destroy(morse, sequence);
    return status;
}

/***************************************************************************//**
 *
 * @ingroup MORSE_Complex32_t_Tile
 *
 *  MORSE_cpotrimm_Tile - Computes the inverse of a complex Hermitian
 *  positive definite matrix A using the Cholesky factorization
 *  A = U**H*U or A = L*L**H computed by MORSE_cpotrf.
 *  Tile equivalent of MORSE_cpotrimm().
 *  Operates on matrices stored by tiles.
 *  All matrices are passed through descriptors.
 *  All dimensions are taken from the descriptors.
 *
 *******************************************************************************
 *
 * @param[in] uplo
 *          = MorseUpper: Upper triangle of A is stored;
 *          = MorseLower: Lower triangle of A is stored.
 *
 * @param[in] A
 *          On entry, the triangular factor U or L from the Cholesky
 *          factorization A = U**H*U or A = L*L**H, as computed by
 *          MORSE_cpotrf.
 *          On exit, the upper or lower triangle of the (Hermitian)
 *          inverse of A, overwriting the input factor U or L.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval >0 if i, the leading minor of order i of A is not
 *               positive definite, so the factorization could not be
 *               completed, and the solution has not been computed.
 *
 *******************************************************************************
 *
 * @sa MORSE_cpotrimm
 * @sa MORSE_cpotrimm_Tile_Async
 * @sa MORSE_cpotri_Tile
 * @sa MORSE_dpotri_Tile
 * @sa MORSE_spotri_Tile
 * @sa MORSE_cpotrf_Tile
 *
 ******************************************************************************/
int MORSE_cpotrimm_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *C)
{
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    int status;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_cpotrimm_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    morse_sequence_create(morse, &sequence);
    MORSE_cpotrimm_Tile_Async(uplo, A, B, C, sequence, &request);
    RUNTIME_barrier(morse);
    RUNTIME_desc_getoncpu(C);
    
    status = sequence->status;
    morse_sequence_destroy(morse, sequence);
    return status;
}

/***************************************************************************//**
 *
 * @ingroup MORSE_Complex32_t_Tile_Async
 *
 *  MORSE_cpotrimm_Tile_Async - Computes the inverse of a complex Hermitian
 *  positive definite matrix A using the Cholesky factorization A = U**H*U
 *  or A = L*L**H computed by MORSE_cpotrf.
 *  Non-blocking equivalent of MORSE_cpotrimm_Tile().
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
 * @sa MORSE_cpotrimm
 * @sa MORSE_cpotrimm_Tile
 * @sa MORSE_cpotri_Tile_Async
 * @sa MORSE_dpotri_Tile_Async
 * @sa MORSE_spotri_Tile_Async
 * @sa MORSE_cpotrf_Tile_Async
 *
 ******************************************************************************/
int MORSE_cpotrimm_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *C,
                             MORSE_sequence_t *sequence, MORSE_request_t *request)
{
    MORSE_context_t *morse;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_cpotrimm_Tile_Async", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    if (sequence == NULL) {
        morse_fatal_error("MORSE_cpotrimm_Tile_Async", "NULL sequence");
        return MORSE_ERR_UNALLOCATED;
    }
    if (request == NULL) {
        morse_fatal_error("MORSE_cpotrimm_Tile_Async", "NULL request");
        return MORSE_ERR_UNALLOCATED;
    }
    /* Check sequence status */
    if (sequence->status == MORSE_SUCCESS)
        request->status = MORSE_SUCCESS;
    else
        return morse_request_fail(sequence, request, MORSE_ERR_SEQUENCE_FLUSHED);

    /* Check descriptors for correctness */
    if (morse_desc_check(A) != MORSE_SUCCESS) {
        morse_error("MORSE_cpotrimm_Tile_Async", "invalid descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (morse_desc_check(B) != MORSE_SUCCESS) {
        morse_error("MORSE_cpotrimm_Tile_Async", "invalid descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (morse_desc_check(C) != MORSE_SUCCESS) {
        morse_error("MORSE_cpotrimm_Tile_Async", "invalid descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    /* Check input arguments */
    if (A->nb != A->mb) {
        morse_error("MORSE_cpotrimm_Tile_Async", "only square tiles supported");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (B->nb != B->mb) {
        morse_error("MORSE_cpotrimm_Tile_Async", "only square tiles supported");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (C->nb != C->mb) {
        morse_error("MORSE_cpotrimm_Tile_Async", "only square tiles supported");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (uplo != MorseUpper && uplo != MorseLower) {
        morse_error("MORSE_cpotrimm_Tile_Async", "illegal value of uplo");
        return morse_request_fail(sequence, request, -1);
    }
    /* Quick return */
/*
    if (max(N, 0) == 0)
        return MORSE_SUCCESS;
*/
    morse_pcpotrimm(uplo, A, B, C, sequence, request);
    

    /*
    morse_pctrtri(uplo, MorseNonUnit, A, sequence, request);

    morse_pclauum(uplo, A, sequence, request);
    */

    return MORSE_SUCCESS;
}
