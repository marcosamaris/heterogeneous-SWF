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
 * @file pcgeqrf.c
 *
 *  MORSE auxiliary routines
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Jakub Kurzak
 * @author Hatem Ltaief
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated c Tue Sep 26 20:43:02 2017
 *
 **/
#include "control/common.h"

#define A(m,n) A,  m,  n
#define T(m,n) T,  m,  n
#if defined(CHAMELEON_COPY_DIAG)
#define DIAG(k) DIAG, k, 0
#else
#define DIAG(k) A, k, k
#endif

/***************************************************************************//**
 *  Parallel tile QR factorization - dynamic scheduling
 **/
void morse_pcgeqrf(MORSE_desc_t *A, MORSE_desc_t *T,
                   MORSE_sequence_t *sequence, MORSE_request_t *request)
{
    MORSE_context_t *morse;
    MORSE_option_t options;
    size_t ws_worker = 0;
    size_t ws_host = 0;
    MORSE_desc_t *DIAG = NULL;

    int k, m, n;
    int ldak, ldam;
    int tempkm, tempkn, tempnn, tempmm;
    int ib;
    int minMNT = min(A->mt, A->nt);

    morse = morse_context_self();
    if (sequence->status != MORSE_SUCCESS)
        return;
    RUNTIME_options_init(&options, morse, sequence, request);

    ib = MORSE_IB;

    /*
     * cgeqrt = A->nb * (ib+1)
     * cunmqr = A->nb * ib
     * ctsqrt = A->nb * (ib+1)
     * ctsmqr = A->nb * ib
     */
    ws_worker = A->nb * (ib+1);

    /* Allocation of temporary (scratch) working space */
#if defined(CHAMELEON_USE_MAGMA)
    /* Worker space
     *
     * cgeqrt = max( A->nb * (ib+1), ib * (ib + A->nb) )
     * cunmqr = A->nb * ib
     * ctsqrt = max( A->nb * (ib+1), ib * (ib + A->nb) )
     * ctsmqr = 2 * A->nb * ib
     */
    ws_worker = max( ws_worker, ib * (ib + A->nb) );
    ws_worker = max( ws_worker, ib * A->nb * 2 );

    /* Host space
     *
     * cgeqrt = ib * (A->mb+3*ib) + A->mb )
     * ctsqrt = 2 * ib * (A->nb+ib) + A->nb
     */
    ws_host = max( ws_host, ib * (A->mb + 3 * ib) + A->mb );
    ws_host = max( ws_host,  2 * ib * (A->nb + ib) + A->nb );
#endif

    ws_worker *= sizeof(MORSE_Complex32_t);
    ws_host   *= sizeof(MORSE_Complex32_t);

    RUNTIME_options_ws_alloc( &options, ws_worker, ws_host );

    /* necessary to avoid dependencies between tsqrt and unmqr tasks regarding the diag tile */
    DIAG = (MORSE_desc_t*)malloc(sizeof(MORSE_desc_t));
    morse_cdesc_alloc2(*DIAG, A->mb, A->nb, min(A->m, A->n), A->nb, 0, 0, min(A->m, A->n), A->nb);

    for (k = 0; k < minMNT; k++) {
        tempkm = k == A->mt-1 ? A->m-k*A->mb : A->mb;
        tempkn = k == A->nt-1 ? A->n-k*A->nb : A->nb;
        ldak = BLKLDD(A, k);
        MORSE_TASK_cgeqrt(
            &options,
            tempkm, tempkn, ib, T->nb,
            A(k, k), ldak,
            T(k, k), T->mb);
        if ( k < (A->nt-1) ) {
#if defined(CHAMELEON_COPY_DIAG)
            MORSE_TASK_clacpy(
                &options,
                MorseLower, A->mb, A->nb, A->nb,
                A(k, k), ldak,
                DIAG(k), ldak );
#endif
#if defined(CHAMELEON_USE_MAGMA)
            MORSE_TASK_claset(
                &options,
                MorseUpper, A->mb, A->nb,
                0., 1.,
                DIAG(k), ldak );
#endif
        }
        for (n = k+1; n < A->nt; n++) {
            tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
            MORSE_TASK_cunmqr(
                &options,
                MorseLeft, MorseConjTrans,
                tempkm, tempnn, tempkm, ib, T->nb,
                DIAG(k), ldak,
                T(k, k), T->mb,
                A(k, n), ldak);
        }
        for (m = k+1; m < A->mt; m++) {
            tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
            ldam = BLKLDD(A, m);
            MORSE_TASK_ctsqrt(
                &options,
                tempmm, tempkn, ib, T->nb,
                A(k, k), ldak,
                A(m, k), ldam,
                T(m, k), T->mb);
            for (n = k+1; n < A->nt; n++) {
                tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
                MORSE_TASK_ctsmqr(
                    &options,
                    MorseLeft, MorseConjTrans,
                    A->mb, tempnn, tempmm, tempnn, A->nb, ib, T->nb,
                    A(k, n), ldak,
                    A(m, n), ldam,
                    A(m, k), ldam,
                    T(m, k), T->mb);
            }
        }
    }
    RUNTIME_options_ws_free(&options);
    RUNTIME_options_finalize(&options, morse);
    MORSE_TASK_dataflush_all();

    morse_desc_mat_free(DIAG);
    free(DIAG);
}
