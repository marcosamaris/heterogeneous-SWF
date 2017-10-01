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
 * @file dsymm.c
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
 *  MORSE_dsymm - Performs one of the matrix-matrix operations
 *
 *     \f[ C = \alpha \times A \times B + \beta \times C \f]
 *
 *  or
 *
 *     \f[ C = \alpha \times B \times A + \beta \times C \f]
 *
 *  where alpha and beta are scalars, A is an symmetric matrix and  B and
 *  C are m by n matrices.
 *
 *******************************************************************************
 *
 * @param[in] side
 *          Specifies whether the symmetric matrix A appears on the
 *          left or right in the operation as follows:
 *          = MorseLeft:      \f[ C = \alpha \times A \times B + \beta \times C \f]
 *          = MorseRight:     \f[ C = \alpha \times B \times A + \beta \times C \f]
 *
 * @param[in] uplo
 *          Specifies whether the upper or lower triangular part of
 *          the symmetric matrix A is to be referenced as follows:
 *          = MorseLower:     Only the lower triangular part of the
 *                             symmetric matrix A is to be referenced.
 *          = MorseUpper:     Only the upper triangular part of the
 *                             symmetric matrix A is to be referenced.
 *
 * @param[in] M
 *          Specifies the number of rows of the matrix C. M >= 0.
 *
 * @param[in] N
 *          Specifies the number of columns of the matrix C. N >= 0.
 *
 * @param[in] alpha
 *          Specifies the scalar alpha.
 *
 * @param[in] A
 *          A is a LDA-by-ka matrix, where ka is M when side = MorseLeft,
 *          and is N otherwise. Only the uplo triangular part is referenced.
 *
 * @param[in] LDA
 *          The leading dimension of the array A. LDA >= max(1,ka).
 *
 * @param[in] B
 *          B is a LDB-by-N matrix, where the leading M-by-N part of
 *          the array B must contain the matrix B.
 *
 * @param[in] LDB
 *          The leading dimension of the array B. LDB >= max(1,M).
 *
 * @param[in] beta
 *          Specifies the scalar beta.
 *
 * @param[in,out] C
 *          C is a LDC-by-N matrix.
 *          On exit, the array is overwritten by the M by N updated matrix.
 *
 * @param[in] LDC
 *          The leading dimension of the array C. LDC >= max(1,M).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *******************************************************************************
 *
 * @sa MORSE_dsymm_Tile
 * @sa MORSE_csymm
 * @sa MORSE_dsymm
 * @sa MORSE_ssymm
 *
 ******************************************************************************/
int MORSE_dsymm(MORSE_enum side, MORSE_enum uplo, int M, int N,
                 double alpha, double *A, int LDA,
                                           double *B, int LDB,
                 double beta,  double *C, int LDC)
{
    int NB;
    int Am;
    int status;
    MORSE_desc_t descA, descB, descC;
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dsymm", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }

    /* Check input arguments */
    if ( (side != MorseLeft) && (side != MorseRight) ){
        morse_error("MORSE_dsymm", "illegal value of side");
        return -1;
    }
    if ((uplo != MorseLower) && (uplo != MorseUpper)) {
        morse_error("MORSE_dsymm", "illegal value of uplo");
        return -2;
    }
    Am = ( side == MorseLeft ) ? M : N;
    if (M < 0) {
        morse_error("MORSE_dsymm", "illegal value of M");
        return -3;
    }
    if (N < 0) {
        morse_error("MORSE_dsymm", "illegal value of N");
        return -4;
    }
    if (LDA < max(1, Am)) {
        morse_error("MORSE_dsymm", "illegal value of LDA");
        return -7;
    }
    if (LDB < max(1, M)) {
        morse_error("MORSE_dsymm", "illegal value of LDB");
        return -9;
    }
    if (LDC < max(1, M)) {
        morse_error("MORSE_dsymm", "illegal value of LDC");
        return -12;
    }

    /* Quick return */
    if (M == 0 || N == 0 ||
        ((alpha == (double)0.0) && beta == (double)1.0))
        return MORSE_SUCCESS;

    /* Tune NB depending on M, N & NRHS; Set NBNB */
    status = morse_tune(MORSE_FUNC_DSYMM, M, N, 0);
    if (status != MORSE_SUCCESS) {
        morse_error("MORSE_dsymm", "morse_tune() failed");
        return status;
    }

    /* Set MT & NT & KT */
    NB = MORSE_NB;

    morse_sequence_create(morse, &sequence);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooplap2tile( descA, A, NB, NB, LDA, Am, 0, 0, Am, Am, sequence, &request,
                             morse_desc_mat_free(&(descA)) );
        morse_dooplap2tile( descB, B, NB, NB, LDB, N,  0, 0, M,  N, sequence, &request,
                             morse_desc_mat_free(&(descA)); morse_desc_mat_free(&(descB)));
        morse_dooplap2tile( descC, C, NB, NB, LDC, N,  0, 0, M,  N, sequence, &request,
                             morse_desc_mat_free(&(descA)); morse_desc_mat_free(&(descB)); morse_desc_mat_free(&(descC)));
/*    } else {*/
/*        morse_diplap2tile( descA, A, NB, NB, LDA, Am, 0, 0, Am, Am,*/
/*                            sequence, &request);*/
/*        morse_diplap2tile( descB, B, NB, NB, LDB, N,  0, 0, M,  N,*/
/*                            sequence, &request);*/
/*        morse_diplap2tile( descC, C, NB, NB, LDC, N,  0, 0, M,  N,*/
/*                            sequence, &request);*/
/*    }*/

    /* Call the tile interface */
    MORSE_dsymm_Tile_Async(
        side, uplo, alpha, &descA, &descB, beta, &descC, sequence, &request);

/*    if ( MORSE_TRANSLATION == MORSE_OUTOFPLACE ) {*/
        morse_dooptile2lap(descC, C, NB, NB, LDC, N,  sequence, &request);
        RUNTIME_barrier(morse);
        morse_desc_mat_free(&descA);
        morse_desc_mat_free(&descB);
        morse_desc_mat_free(&descC);
/*    } else {*/
/*        morse_diptile2lap( descA, A, NB, NB, LDA, Am,  sequence, &request);*/
/*        morse_diptile2lap( descB, B, NB, NB, LDB, N,  sequence, &request);*/
/*        morse_diptile2lap( descC, C, NB, NB, LDC, N,  sequence, &request);*/
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
 *  MORSE_dsymm_Tile - Performs symmetric matrix multiplication.
 *  Tile equivalent of MORSE_dsymm().
 *  Operates on matrices stored by tiles.
 *  All matrices are passed through descriptors.
 *  All dimensions are taken from the descriptors.
 *
 *******************************************************************************
 *
 * @param[in] side
 *          Specifies whether the symmetric matrix A appears on the
 *          left or right in the operation as follows:
 *          = MorseLeft:      \f[ C = \alpha \times A \times B + \beta \times C \f]
 *          = MorseRight:     \f[ C = \alpha \times B \times A + \beta \times C \f]
 *
 * @param[in] uplo
 *          Specifies whether the upper or lower triangular part of
 *          the symmetric matrix A is to be referenced as follows:
 *          = MorseLower:     Only the lower triangular part of the
 *                             symmetric matrix A is to be referenced.
 *          = MorseUpper:     Only the upper triangular part of the
 *                             symmetric matrix A is to be referenced.
 *
 * @param[in] alpha
 *          Specifies the scalar alpha.
 *
 * @param[in] A
 *          A is a LDA-by-ka matrix, where ka is M when side = MorseLeft,
 *          and is N otherwise. Only the uplo triangular part is referenced.
 *
 * @param[in] B
 *          B is a LDB-by-N matrix, where the leading M-by-N part of
 *          the array B must contain the matrix B.
 *
 * @param[in] beta
 *          Specifies the scalar beta.
 *
 * @param[in,out] C
 *          C is a LDC-by-N matrix.
 *          On exit, the array is overwritten by the M by N updated matrix.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *******************************************************************************
 *
 * @sa MORSE_dsymm
 * @sa MORSE_dsymm_Tile_Async
 * @sa MORSE_csymm_Tile
 * @sa MORSE_dsymm_Tile
 * @sa MORSE_ssymm_Tile
 *
 ******************************************************************************/
int MORSE_dsymm_Tile(MORSE_enum side, MORSE_enum uplo,
                      double alpha, MORSE_desc_t *A, MORSE_desc_t *B,
                      double beta,  MORSE_desc_t *C)
{
    MORSE_context_t *morse;
    MORSE_sequence_t *sequence = NULL;
    MORSE_request_t request = MORSE_REQUEST_INITIALIZER;
    int status;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dsymm_Tile", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    morse_sequence_create(morse, &sequence);
    MORSE_dsymm_Tile_Async(side, uplo, alpha, A, B, beta, C, sequence, &request);
    RUNTIME_barrier(morse);
    RUNTIME_desc_getoncpu(A);
        RUNTIME_desc_getoncpu(B);
        RUNTIME_desc_getoncpu(C);
    
    status = sequence->status;
    morse_sequence_destroy(morse, sequence);
    return status;
}

/***************************************************************************//**
 *
 * @ingroup double_Tile_Async
 *
 *  MORSE_dsymm_Tile_Async - Performs symmetric matrix multiplication.
 *  Non-blocking equivalent of MORSE_dsymm_Tile().
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
 * @sa MORSE_dsymm
 * @sa MORSE_dsymm_Tile
 * @sa MORSE_csymm_Tile_Async
 * @sa MORSE_dsymm_Tile_Async
 * @sa MORSE_ssymm_Tile_Async
 *
 ******************************************************************************/
int MORSE_dsymm_Tile_Async(MORSE_enum side, MORSE_enum uplo,
                            double alpha, MORSE_desc_t *A, MORSE_desc_t *B,
                            double beta,  MORSE_desc_t *C,
                            MORSE_sequence_t *sequence, MORSE_request_t *request)
{
    MORSE_context_t *morse;

    morse = morse_context_self();
    if (morse == NULL) {
        morse_fatal_error("MORSE_dsymm_Tile_Async", "MORSE not initialized");
        return MORSE_ERR_NOT_INITIALIZED;
    }
    if (sequence == NULL) {
        morse_fatal_error("MORSE_dsymm_Tile_Async", "NULL sequence");
        return MORSE_ERR_UNALLOCATED;
    }
    if (request == NULL) {
        morse_fatal_error("MORSE_dsymm_Tile_Async", "NULL request");
        return MORSE_ERR_UNALLOCATED;
    }
    /* Check sequence status */
    if (sequence->status == MORSE_SUCCESS)
        request->status = MORSE_SUCCESS;
    else
        return morse_request_fail(sequence, request, MORSE_ERR_SEQUENCE_FLUSHED);

    /* Check descriptors for correctness */
    if (morse_desc_check(A) != MORSE_SUCCESS) {
        morse_error("MORSE_dsymm_Tile_Async", "invalid first descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (morse_desc_check(B) != MORSE_SUCCESS) {
        morse_error("MORSE_dsymm_Tile_Async", "invalid second descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if (morse_desc_check(C) != MORSE_SUCCESS) {
        morse_error("MORSE_dsymm_Tile_Async", "invalid third descriptor");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    /* Check input arguments */
    if ( (side != MorseLeft) && (side != MorseRight) ){
        morse_error("MORSE_dsymm_Tile_Async", "illegal value of side");
        return morse_request_fail(sequence, request, -1);
    }
    if ((uplo != MorseLower) && (uplo != MorseUpper)) {
        morse_error("MORSE_dsymm_Tile_Async", "illegal value of uplo");
        return morse_request_fail(sequence, request, -2);
    }

    /* Check matrices sizes */
    if ( (B->m != C->m) || (B->n != C->n) ) {
        morse_error("MORSE_dsymm_Tile_Async", "B and C must have the same size");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if ( (A->m != A->n) ||
         ( (side == MorseLeft)  && (A->m != B->m ) ) ||
         ( (side == MorseRight) && (A->m != B->n ) ) ) {
        morse_error("MORSE_dsymm_Tile_Async", "Matrix A must be square of size M or N regarding side.");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }

    /* Check tiles sizes */
    if ( (B->mb != C->mb) || (B->nb != C->nb) ) {
        morse_error("MORSE_dsymm_Tile_Async", "B and C must have the same tile sizes");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }
    if ( (A->mb != A->nb) ||
         ( (side == MorseLeft)  && (A->mb != B->mb ) ) ||
         ( (side == MorseRight) && (A->mb != B->nb ) ) ) {
        morse_error("MORSE_dsymm_Tile_Async", "Matrix A must be square with square tiles wich fits the reagding tile size of B and C");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }

    /* Check submatrix starting point */
    /* if ( (B->i != C->i) || (B->j != C->j) ) { */
    /*     morse_error("MORSE_dsymm_Tile_Async", "B and C submatrices doesn't match"); */
    /*     return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE); */
    /* } */
    /* if ( (A->i != A->j) ||  */
    /*          ( (side == MorseLeft)  && (A->i != B->i ) ) ||  */
    /*          ( (side == MorseRight) && (A->i != B->j ) ) ) { */
    /*     morse_error("MORSE_dsymm_Tile_Async", "Submatrix A must start on diagnonal and match submatrices B and C."); */
    /*     return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE); */
    /* } */
    if( (A->i != 0) || (A->j != 0) ||
        (B->i != 0) || (B->j != 0) ||
        (C->i != 0) || (C->j != 0) ) {
        morse_error("MORSE_dsymm_Tile_Async", "Submatrices are not supported for now");
        return morse_request_fail(sequence, request, MORSE_ERR_ILLEGAL_VALUE);
    }

    /* Quick return */
    if (C->m == 0 || C->n == 0 ||
        ( (alpha == (double)0.0) && (beta == (double)1.0) ))
        return MORSE_SUCCESS;

    morse_pdsymm(side, uplo, alpha, A, B, beta, C, sequence, request);

    return MORSE_SUCCESS;
}
