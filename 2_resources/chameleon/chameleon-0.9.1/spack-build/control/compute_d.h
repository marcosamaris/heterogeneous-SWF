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
 * @file compute_d.h
 *
 *  MORSE auxiliary routines
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
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:42:59 2017
 *
 **/

/***************************************************************************//**
 *  Macro for matrix conversion / Lapack interface
 **/
#define morse_ddesc_alloc2(descA, mb, nb, lm, ln, i, j, m, n)         \
    descA = morse_desc_init(                                          \
        MorseRealDouble, (mb), (nb), ((mb)*(nb)),                  \
        (m), (n), (i), (j), (m), (n), 1, 1);                          \
    morse_desc_mat_alloc( &(descA) );

#define morse_ddesc_alloc( descA, mb, nb, lm, ln, i, j, m, n, free)   \
    descA = morse_desc_init(                                          \
        MorseRealDouble, (mb), (nb), ((mb)*(nb)),                  \
        (m), (n), (i), (j), (m), (n), 1, 1);                          \
    if ( morse_desc_mat_alloc( &(descA) ) ) {                         \
        morse_error( __func__, "morse_desc_mat_alloc() failed");       \
        {free;};                                                       \
        return MORSE_ERR_OUT_OF_RESOURCES;                            \
    }

#define morse_dooplap2tile( descA, A, mb, nb, lm, ln, i, j, m, n, seq, req, free) \
    descA = morse_desc_init(                                           \
        MorseRealDouble, (mb), (nb), ((mb)*(nb)),                   \
        (lm), (ln), (i), (j), (m), (n), 1, 1);                         \
    if ( morse_desc_mat_alloc( &(descA) ) ) {                          \
        morse_error( __func__, "morse_desc_mat_alloc() failed");        \
        {free;};                                                        \
        return MORSE_ERR_OUT_OF_RESOURCES;                             \
    }                                                                   \
    morse_pdlapack_to_tile(A, lm, &descA, seq, req);

#define morse_diplap2tile( descA, A, mb, nb, lm, ln, i, j, m, n, seq, req) \
    descA = morse_desc_init(                                         \
        MorseRealDouble, (mb), (nb), ((mb)*(nb)),                 \
        (lm), (ln), (i), (j), (m), (n), 1, 1);                        \
    descA.mat = A;                                                    \
    MORSE_dgecfi_Async((lm), (ln), (A), MorseCM, (mb), (nb),        \
                        MorseCCRB, (mb), (nb), (seq), (req));


#define morse_dooptile2lap( descA, A, mb, nb, lm, ln, seq, req)    \
    morse_pdtile_to_lapack(&descA, A, lm, seq, req);

#define morse_diptile2lap( descA, A, mb, nb, lm, ln, seq, req)         \
    MORSE_dgecfi_Async((lm), (ln), (A), MorseCCRB, (mb), (nb),        \
                        MorseCM, (mb), (nb), (seq), (req));

/***************************************************************************//**
 *  Declarations of internal sequential functions
 **/
int morse_dshift(MORSE_context_t *morse, int m, int n, double *A,
                  int nprob, int me, int ne, int L,
                  MORSE_sequence_t *sequence, MORSE_request_t *request);

/***************************************************************************//**
 *  Declarations of parallel functions (dynamic scheduling) - alphabetical order
 **/
void morse_pdgeadd(double alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdbarrier_tl2pnl(MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdbarrier_pnl2tl(MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdbarrier_tl2row(MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdbarrier_row2tl(MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgebrd_tb2bd(MORSE_enum uplo, MORSE_desc_t *A, double *D, double *E, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgebrd_ge2tb(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgelqf(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgelqfrh(MORSE_desc_t *A, MORSE_desc_t *T, int BS, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgemm(MORSE_enum transA, MORSE_enum transB, double alpha, MORSE_desc_t *A, MORSE_desc_t *B, double beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgeqrf(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgeqrfrh(MORSE_desc_t *A, MORSE_desc_t *T, int BS, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgerbh(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgerbbrh(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgetmi2(MORSE_enum idep, MORSE_enum odep, MORSE_enum storev, int m, int n, int mb, int nb, double *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgetrf_incpiv(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgetrf_reclap(MORSE_desc_t *A, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdgetrf_rectil(MORSE_desc_t *A, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdhbcpy_t2bl(MORSE_enum uplo, MORSE_desc_t *A, double *AB, int LDAB, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdsygst(MORSE_enum itype, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
void morse_pdsymm(MORSE_enum side, MORSE_enum uplo, double alpha, MORSE_desc_t *A, MORSE_desc_t *B, double beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdsyrk(MORSE_enum uplo, MORSE_enum trans, double alpha, MORSE_desc_t *A, double beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdsyr2k(MORSE_enum uplo, MORSE_enum trans, double alpha, MORSE_desc_t *A, MORSE_desc_t *B, double beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
void morse_pdsytrd_sy2sb(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlacpy(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlag2s(MORSE_desc_t *A, MORSE_desc_t *SB, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlange(MORSE_enum norm, MORSE_desc_t *A, double *result, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
void morse_pdlansy(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, double *result, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
void morse_pdlansy(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, double *result, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlantr(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, double *result, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlaset( MORSE_enum uplo, double alpha, double beta, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlaset2(MORSE_enum uplo, double alpha,                          MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlaswp(MORSE_desc_t *B, int *IPIV, int inc, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlaswpc(MORSE_desc_t *B, int *IPIV, int inc, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdlauum(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdplgsy(double bump, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdplgsy(double bump, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
void morse_pdplrnt(MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
void morse_pdpotrf(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdshift(int, int, int, double *, int *, int, int, int, MORSE_sequence_t*, MORSE_request_t*);
void morse_pdsymm(MORSE_enum side, MORSE_enum uplo, double alpha, MORSE_desc_t *A, MORSE_desc_t *B, double beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdsyrk(MORSE_enum uplo, MORSE_enum trans, double alpha, MORSE_desc_t *A, double beta,  MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdsyr2k(MORSE_enum uplo, MORSE_enum trans, double alpha, MORSE_desc_t *A, MORSE_desc_t *B, double beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdtrmm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, double alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdtrsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, double alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdtrsmpl(MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *L, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdtrsmrv(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, double alpha, MORSE_desc_t *A, MORSE_desc_t *W, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdtrtri(MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdorgbr(MORSE_enum side, MORSE_desc_t *A, MORSE_desc_t *O, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdorgbrrh(MORSE_enum side, MORSE_desc_t *A, MORSE_desc_t *O, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdorgqr(MORSE_desc_t *A, MORSE_desc_t *Q, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdorgqrrh(MORSE_desc_t *A, MORSE_desc_t *Q, MORSE_desc_t *T, int BS, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdorglq(MORSE_desc_t *A, MORSE_desc_t *Q, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdorglqrh(MORSE_desc_t *A, MORSE_desc_t *Q, MORSE_desc_t *T, int BS, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdorgtr(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *Q, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdormqr(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdormqrrh(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *T, int BS, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdormlq(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
void morse_pdormlqrh(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *T, int BS, MORSE_sequence_t *sequence, MORSE_request_t *request);
