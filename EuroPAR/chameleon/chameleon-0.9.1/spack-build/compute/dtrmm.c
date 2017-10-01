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
 * @file dtrmm.c
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
 * @generated d Tue Sep 26 20:43:01 2017
 *
 **/
#include "control/common.h"

/***************************************************************************//**
 *
 * @ingroup double
 *
 *  MORSE_dtrmm - Computes B = alpha*op( A )*B or B = alpha*B*op( A ).
 *
 *******************************************************************************
 *
 * @param[in] side
 *          Specifies whether A appears on the left or on the right of X:
 *          = MorseLeft:  A*X = B
 *          = MorseRight: X*A = B
 *
 * @param[in] uplo
 *          Specifies whether the matrix A is upper triangular or lower triangular:
 *          = MorseUpper: Upper triangle of A is stored;
 *          = MorseLower: Lower triangle of A is stored.
 *
 * @param[in] transA
 *          Specifies whether the matrix A is transposed, not transposed or conjugate transposed:
 *          = MorseNoTrans:   A is transposed;
 *          = MorseTrans:     A is not transposed;
 *          = MorseTrans: A is conjugate transposed.
 *
 * @param[in] diag
 *          Specifies whether or not A is unit triangular:
 *          = MorseNonUnit: A is non unit;
 *          = MorseUnit:    A us unit.
 *
 * @param[in] N
 *          The order of the matrix A. N >= 0.
 *
 * @param[in] NRHS
 *          The number of right hand sides, i.e., the number of columns of the matrix B. NRHS >= 0.
 *
 * @param[in] alpha
 *          alpha specifies the scalar alpha.
 *
 * @param[in] A
 *          The triangular matrix A. If uplo = MorseUpper, the leading N-by-N upper triangular
 *          part of the array A contains the upper triangular matrix, and the strictly lower
 *          triangular part of A is not referenced. If uplo = MorseLower, the leading N-by-N
 *          lower triangular part of the array A contains the lower triangular matrix, and the
 *          strictly upper triangular part of A is not referenced. If diag = MorseUnit, the
 *          diagonal elements of A are also not referenced and are assumed to be 1.
 *
 * @param[in] LDA
 *          The leading dimension of the array A. LDA >= max(1,N).
 *
 * @param[in,out] B
 *          On entry, the N-by-NRHS right hand side matrix B.
 *          On exit, if return value = 0, the N-by-NRHS solution matrix X.
 *
 * @param[in] LDB
 *          The leading dimension of the array B. LDB >= max(1,N).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *
 *******************************************************************************
 *
 * @sa MORSE_dtrmm_Tile
 * @sa MORSE_dtrmm_Tile_Async
 * @sa MORSE_ctrmm
 * @sa MORSE_dtrmm
 * @sa MORSE_strmm
 *
 ******************************************************************************/
int MORSE_dtrmm(MORSE_enum side, MORSE_enum uplo,
                 MORSE_enum transA, MORSE_enum diag,
                 int N, int NRHS, double alpha,
                 double *A, int LDA,
                 double *B, int LDB)
{
    int NB, NA;
    int status;
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    MORSE_desc_t descA, descB;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dtrmm", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }

    if (side == MorseLeft) {
      NA = N;
    } else {
      NA = NRHS;
    }

    /* Check input arguments */
    if (side != MorseLeft && side != MorseRight) {
        morse_error("MORSE_dtrmm", "illegal value of side");
        return -1;
    }
    if (uplo != MorseUpper && uplo != MorseLower) {
        morse_error("MORSE_dtrmm", "illegal value of uplo");
        return -2;
    }
    if (transA != MorseTrans && 
        transA != MorseNoTrans   && 
        transA != MorseTrans ) 
    {
        morse_error("MORSE_dtrmm", "illegal value of transA");
        return -3;
    }
    if (diag != MorseUnit && diag != MorseNonUnit) {
        morse_error("MORSE_dtrmm", "illegal value of diag");
        return -4;
    }
    if (N < 0) {
        morse_error("MORSE_dtrmm", "illegal value of N");
        return -5;
    }
    if (NRHS < 0) {
        morse_error("MORSE_dtrmm", "illegal value of NRHS");
        return -6;
    }
    if (LDA < max(1, NA)) {
        morse_error("MORSE_dtrmm", "illegal value of LDA");
        return -8;
    }
    if (LDB < max(1, N)) {
        morse_error("MORSE_dtrmm", "illegal value of LDB");
        return -10;
    }
    /* Quick return */
    if (min(N, NRHS) == 0)
        return MORSE_SUCCESS;

    /* Tune NB depending on M, N & NRHS; Set NBNB */
    status = morse_tune(MORSE_FUNC_DPOSV, N, N, NRHS);
    if (status != MORSE_SUCCESS) {
        morse_error("MORSE_dtrmm", "morse_tune() failed");
        return status;
    }

    /* Set NT & NTRHS */
    NB = MORSE_NB;

    morse_sequence_create(morse, &sequence);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooplap2tile( descA, A, NB, NB, LDA, NA,   0, 0, NA, NA,    sequence, &request,
                             morse_desc_mat_free(&(descA)) );
        morse_dooplap2tile( descB, B, NB, NB, LDB, NRHS, 0, 0, N,  NRHS, sequence, &request,
                             morse_desc_mat_free(&(descA)); morse_desc_mat_free(&(descB)));
/*    } else {*/
/*        morse_diplap2tile( descA, A, NB, NB, LDA, NA,   0, 0, NA, NA,  */
/*                            sequence, &request);*/
/*        morse_diplap2tile( descB, B, NB, NB, LDB, NRHS, 0, 0, N,  NRHS,*/
/*                            sequence, &request);*/
/*    }*/

    /* Call the tile interface */
    MORSE_dtrmm_Tile_Async(
        side, uplo, transA, diag, alpha, &descA, &descB, sequence, &request);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooptile2lap(descB, B, NB, NB, LDB, NRHS,  sequence, &request);
        RUNTIME_barrier(morse);
        morse_desc_mat_free(&descA);
        morse_desc_mat_free(&descB);
/*    } else {*/
/*        morse_diptile2lap( descA, A, NB, NB, LDA, NA,    sequence, &request);*/
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
 *  MORSE_dtrmm_Tile - Computes triangular solve.
 *  Tile equivalent of MORSE_dtrmm().
 *  Operates on matrices stored by tiles.
 *  All matrices are passed through descriptors.
 *  All dimensions are taken from the descriptors.
 *
 *******************************************************************************
 *
 * @param[in] side
 *          Specifies whether A appears on the left or on the right of X:
 *          = MorseLeft:  A*X = B
 *          = MorseRight: X*A = B
 *
 * @param[in] uplo
 *          Specifies whether the matrix A is upper triangular or lower triangular:
 *          = MorseUpper: Upper triangle of A is stored;
 *          = MorseLower: Lower triangle of A is stored.
 *
 * @param[in] transA
 *          Specifies whether the matrix A is transposed, not transposed or conjugate transposed:
 *          = MorseNoTrans:   A is transposed;
 *          = MorseTrans:     A is not transposed;
 *          = MorseTrans: A is conjugate transposed.
 *
 * @param[in] diag
 *          Specifies whether or not A is unit triangular:
 *          = MorseNonUnit: A is non unit;
 *          = MorseUnit:    A us unit.
 *
 * @param[in] alpha
 *          alpha specifies the scalar alpha.
 *
 * @param[in] A
 *          The triangular matrix A. If uplo = MorseUpper, the leading N-by-N upper triangular
 *          part of the array A contains the upper triangular matrix, and the strictly lower
 *          triangular part of A is not referenced. If uplo = MorseLower, the leading N-by-N
 *          lower triangular part of the array A contains the lower triangular matrix, and the
 *          strictly upper triangular part of A is not referenced. If diag = MorseUnit, the
 *          diagonal elements of A are also not referenced and are assumed to be 1.
 *
 * @param[in,out] B
 *          On entry, the N-by-NRHS right hand side matrix B.
 *          On exit, if return value = 0, the N-by-NRHS solution matrix X.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *******************************************************************************
 *
 * @sa MORSE_dtrmm
 * @sa MORSE_dtrmm_Tile_Async
 * @sa MORSE_ctrmm_Tile
 * @sa MORSE_dtrmm_Tile
 * @sa MORSE_strmm_Tile
 *
 ******************************************************************************/
int MORSE_dtrmm_Tile(MORSE_enum side, MORSE_enum uplo,
                      MORSE_enum transA, MORSE_enum diag,
                      double alpha, MORSE_desc_t *A, MORSE_desc_t *B)
{
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    int status;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dtrmm_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    morse_sequence_create(morse, &sequence);
    MORSE_dtrmm_Tile_Async(side, uplo, transA, diag, alpha, A, B, sequence, &request);
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
 *  MORSE_dtrmm_Tile_Async - Performs triangular matrix multiplication.
 *  Non-blocking equivalent of MORSE_dtrmm_Tile().
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
 * @sa MORSE_dtrmm
 * @sa MORSE_dtrmm_Tile
 * @sa MORSE_ctrmm_Tile_Async
 * @sa MORSE_dtrmm_Tile_Async
 * @sa MORSE_strmm_Tile_Async
 *
 ******************************************************************************/
int MORSE_dtrmm_Tile_Async(MORSE_enum side, MORSE_enum uplo,
                            MORSE_enum transA, MORSE_enum diag,
                            double alpha, MORSE_desc_t *A, MORSE_desc_t *B,
                            MORSE_sequence_t *sequence, MORSE_request_t *request)
{
    MORSE_context_t *morse;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dtrmm_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    if (sequence == NULL) {
        morse_fatal_error("MORSE_dtrmm_Tile", "NULL sequence");
        return MORSE_ERR_UNALLOCATED;
    }
    if (request == NULL) {
        morse_fatal_error("MORSE_dtrmm_Tile", "NULL request");
        return MORSE_ERR_UNALLOCATED;
    }
    /* Check sequence status */
    if (sequence->status == MORSE_SUCCESS)
        request->status = MORSE_SUCCESS;
    else
        return morse_request_fail(sequence, request, MORSE_ERR_SEQUENCE_FLUSHED);

    /* Check descriptors for correctness */
    if (morse_desc_check(A) != MORSE_SUCCESS) {
        morse_error("MORSE_dtrmm_Tile", "invalid first descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (morse_desc_check(B) != MORSE_SUCCESS) {
        morse_error("MORSE_dtrmm_Tile", "invalid second descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    /* Check input arguments */
    if (A->nb != A->mb || B->nb != B->mb) {
        morse_error("MORSE_dtrmm_Tile", "only square tiles supported");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (side != MorseLeft && side != MorseRight) {
        morse_error("MORSE_dtrmm_Tile", "illegal value of side");
        return morse_request_fail(sequence, request, -1);
    }
    if (uplo != MorseUpper && uplo != MorseLower) {
        morse_error("MORSE_dtrmm_Tile", "illegal value of uplo");
        return morse_request_fail(sequence, request, -2);
    }
    if (transA != MorseTrans && transA != MorseNoTrans && transA != MorseTrans) {
        morse_error("MORSE_dtrmm_Tile", "illegal value of transA");
        return morse_request_fail(sequence, request, -3);
    }
    if (diag != MorseUnit && diag != MorseNonUnit) {
        morse_error("MORSE_dtrmm_Tile", "illegal value of diag");
        return morse_request_fail(sequence, request, -4);
    }

    /* Quick return */
    morse_pdtrmm(side, uplo, transA, diag, alpha, A, B, sequence, request);

    return MORSE_SUCCESS;
}
