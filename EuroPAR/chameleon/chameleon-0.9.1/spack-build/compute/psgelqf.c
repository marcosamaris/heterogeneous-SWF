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
 * @file psgelqf.c
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
 * @generated s Tue Sep 26 20:43:02 2017
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
 *  Parallel tile LQ factorization - dynamic scheduling
 **/
void morse_psgelqf(MORSE_desc_t *A, MORSE_desc_t *T,
                   MORSE_sequence_t *sequence, MORSE_request_t *request)
{
    MORSE_context_t *morse;
    MORSE_option_t options;
    size_t ws_worker = 0;
    size_t ws_host = 0;
    MORSE_desc_t *DIAG = NULL;

    int k, m, n;
    int ldak, ldam;
    int tempkm, tempkn, tempmm, tempnn;
    int ib, minMT;

    morse = morse_context_self();
    if (sequence->status != MORSE_SUCCESS)
        return;
    RUNTIME_options_init(&options, morse, sequence, request);

    ib = MORSE_IB;

    if (A->m > A->n) {
        minMT = A->nt;
    } else {
        minMT = A->mt;
    }

    /*
     * sgelqt = A->nb * (ib+1)
     * sormlq = A->nb * ib
     * stslqt = A->nb * (ib+1)
     * stsmlq = A->nb * ib
     */
    ws_worker = A->nb * (ib+1);

    /* Allocation of temporary (scratch) working space */
#if defined(CHAMELEON_USE_MAGMA)
    /* Worker space
     *
     * sgelqt = max( A->nb * (ib+1), ib * (ib + A->nb) )
     * sormlq = A->nb * ib
     * stslqt = max( A->nb * (ib+1), ib * (ib + A->nb) )
     * stsmlq = 2 * A->nb * ib
     */
    ws_worker = max( ws_worker, ib * (ib + A->nb) );
    ws_worker = max( ws_worker, ib * A->nb * 2 );

    /* Host space
     *
     * sgelqt =     ib * A->nb + 3 * ib * ib + A->nb
     * stslqt = 3 * ib * A->nb +     ib * ib + A->nb
     */
    ws_host = max( ws_host,     ib * A->nb + 3 * ib * ib + A->nb );
    ws_host = max( ws_host, 3 * ib * A->nb +     ib * ib + A->nb );
#endif

    ws_worker *= sizeof(float);
    ws_host   *= sizeof(float);

    RUNTIME_options_ws_alloc( &options, ws_worker, ws_host );

    /* necessary to avoid dependencies between tslqt and ormlq tasks regarding the diag tile */
    DIAG = (MORSE_desc_t*)malloc(sizeof(MORSE_desc_t));
    morse_sdesc_alloc2(*DIAG, A->mb, A->nb, (minMT-1)*A->mb, A->nb, 0, 0, (minMT-1)*A->mb, A->nb);

    for (k = 0; k < min(A->mt, A->nt); k++) {
        tempkm = k == A->mt-1 ? A->m-k*A->mb : A->mb;
        tempkn = k == A->nt-1 ? A->n-k*A->nb : A->nb;
        ldak = BLKLDD(A, k);
        MORSE_TASK_sgelqt(
            &options,
            tempkm, tempkn, ib, T->nb,
            A(k, k), ldak,
            T(k, k), T->mb);
        if ( k < (A->mt-1) ) {
#if defined(CHAMELEON_COPY_DIAG)
            MORSE_TASK_slacpy(
                &options,
                MorseUpper, A->mb, A->nb, A->nb,
                A(k, k), ldak,
                DIAG(k), ldak );
#endif
#if defined(CHAMELEON_USE_MAGMA)
            MORSE_TASK_slaset(
                &options,
                MorseLower, A->mb, A->nb,
                0., 1.,
                DIAG(k), A->mb );
#endif
        }
        for (m = k+1; m < A->mt; m++) {
            tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
            ldam = BLKLDD(A, m);
            MORSE_TASK_sormlq(
                &options,
                MorseRight, MorseTrans,
                tempmm, tempkn, tempkn, ib, T->nb,
                DIAG(k), A->mb,
                T(k, k), T->mb,
                A(m, k), ldam);
        }
        for (n = k+1; n < A->nt; n++) {
            tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
            MORSE_TASK_stslqt(
                &options,
                tempkm, tempnn, ib, T->nb,
                A(k, k), ldak,
                A(k, n), ldak,
                T(k, n), T->mb);
            for (m = k+1; m < A->mt; m++) {
                tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
                ldam = BLKLDD(A, m);
                MORSE_TASK_stsmlq(
                    &options,
                    MorseRight, MorseTrans,
                    tempmm, A->nb, tempmm, tempnn, A->mb, ib, T->nb,
                    A(m, k), ldam,
                    A(m, n), ldam,
                    A(k, n), ldak,
                    T(k, n), T->mb);
            }
        }
    }
    RUNTIME_options_ws_free(&options);
    RUNTIME_options_finalize(&options, morse);
    MORSE_TASK_dataflush_all();

    morse_desc_mat_free(DIAG);
    free(DIAG);
}
