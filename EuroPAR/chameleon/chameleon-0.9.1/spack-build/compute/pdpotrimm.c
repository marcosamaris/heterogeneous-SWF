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
 * @file pdpotrimm.c
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
 * @generated d Tue Sep 26 20:43:04 2017
 *
 **/
#include "control/common.h"

#define A(m,n) A,  m,  n
#define B(m,n) B,  m,  n
#define C(m,n) C,  m,  n
/***************************************************************************//**
 *  Parallel tile Cholesky factorization - dynamic scheduling
 **/
void morse_pdpotrimm(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *C,
                          MORSE_sequence_t *sequence, MORSE_request_t *request)
{
    MORSE_context_t *morse;
    MORSE_option_t options;

    int k, m, n;
    int lda, ldab, ldb, ldc;
    int ldak, ldam, ldan;
    int tempkm, tempmm, tempnn, tempkn;

    double alpha  = (double) 1.0;
    double beta  = (double) 0.0;
    double zbeta;
    double zone  = (double) 1.0;
    double mzone = (double)-1.0;


    morse = morse_context_self();
    if (sequence->status != MORSE_SUCCESS)
        return;
    RUNTIME_options_init(&options, morse, sequence, request);

#ifdef CHAMELEON_USE_MAGMA
    {
      int nb = magma_get_dpotrf_nb(A->nb);
      RUNTIME_options_ws_alloc( &options, nb*nb, 0 );
    }
#endif

    /*
     *  MorseLower
     */
    if (uplo == MorseLower) {
        /*
         *  DPOTRF
         */
	for (k = 0; k < A->mt; k++) {
	    tempkm = k == A->mt-1 ? A->m-k*A->mb : A->mb;
	    ldak = BLKLDD(A, k);
	    MORSE_TASK_dpotrf(
		&options,
		MorseLower, tempkm, A->mb,
                A(k, k), ldak, A->nb*k);
	    
            for (m = k+1; m < A->mt; m++) {
                tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
                ldam = BLKLDD(A, m);
                MORSE_TASK_dtrsm(
                    &options,
                    MorseRight, MorseLower, MorseTrans, MorseNonUnit,
                    tempmm, A->mb, A->mb,
                    zone, A(k, k), ldak,
                          A(m, k), ldam);
            }
            MORSE_TASK_dataflush( &options, A(k, k) );

	    for (n = k+1; n < A->nt; n++) {
		tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
		ldan = BLKLDD(A, n);
		MORSE_TASK_dsyrk(
		    &options,
		    MorseLower, MorseNoTrans,
		    tempnn, A->nb, A->mb,
		    -1.0, A(n, k), ldan,
		     1.0, A(n, n), ldan);
		
		for (m = n+1; m < A->mt; m++) {
		    tempmm = m == A->mt-1 ? A->m - m*A->mb : A->mb;
		    ldam = BLKLDD(A, m);
		    MORSE_TASK_dgemm(
			&options,
			MorseNoTrans, MorseTrans,
			tempmm, tempnn, A->mb, A->mb,
			mzone, A(m, k), ldam,
			       A(n, k), ldan,
			zone,  A(m, n), ldam);
		}
		MORSE_TASK_dataflush( &options, A(n, k) );
	    }
	}
        /*
         *  DTRTRI
         */
        for (n = 0; n < A->nt; n++) {
            tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
            ldan = BLKLDD(A, n);
            for (m = n+1; m < A->mt; m++) {
                tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
                ldam = BLKLDD(A, m);
                MORSE_TASK_dtrsm(
                    &options,
                    MorseRight, uplo, MorseNoTrans, MorseNonUnit,
                    tempmm, tempnn, A->mb,
                    mzone, A(n, n), ldan,
                           A(m, n), ldam);
            }
            for (m = n+1; m < A->mt; m++) {
                tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
                ldam = BLKLDD(A, m);
                for (k = 0; k < n; k++) {
                    tempkn = k == A->nt-1 ? A->n-k*A->nb : A->nb;
                    MORSE_TASK_dgemm(
                        &options,
                        MorseNoTrans, MorseNoTrans,
                        tempmm, tempkn, tempnn, A->mb,
                        zone, A(m, n), ldam,
                              A(n, k), ldan,
                        zone, A(m, k), ldam);
                }
            }
            for (m = 0; m < n; m++) {
                tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
                MORSE_TASK_dtrsm(
                    &options,
                    MorseLeft, uplo, MorseNoTrans, MorseNonUnit,
                    tempnn, tempmm, A->mb,
                    zone, A(n, n), ldan,
                          A(n, m), ldan);
            }
            MORSE_TASK_dtrtri(
                &options,
                uplo, MorseNonUnit,
                tempnn, A->mb,
                A(n, n), ldan, A->nb*n);
        }
        /*
         *  DLAUUM
         */
        for (m = 0; m < A->mt; m++) {
            tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
            ldam = BLKLDD(A, m);
            for(n = 0; n < m; n++) {
                tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
                MORSE_TASK_dsyrk(
                    &options,
                    uplo, MorseTrans,
                    tempnn, tempmm, A->mb,
                    1.0, A(m, n), ldam,
                    1.0, A(n, n), A->mb);

                for(k = n+1; k < m; k++) {
                    tempkm = k == A->mt-1 ? A->m-k*A->mb : A->mb;
                    MORSE_TASK_dgemm(
                        &options,
                        MorseTrans, MorseNoTrans,
                        tempkm, tempnn, tempmm, A->mb,
                        zone, A(m, k), ldam,
                              A(m, n), ldam,
                        zone, A(k, n), A->mb);
                }
            }
            for (n = 0; n < m; n++) {
                tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
                MORSE_TASK_dtrmm(
                    &options,
                    MorseLeft, uplo, MorseTrans, MorseNonUnit,
                    tempmm, tempnn, A->mb,
                    zone, A(m, m), ldam,
                          A(m, n), ldam);
            }
            MORSE_TASK_dlauum(
                &options,
                uplo,
                tempmm,
                A->mb, A(m, m), ldam);
        }
        /*
         *  DSYMM
         */
        for (m = 0; m < C->mt; m++) {
            tempmm = m == C->mt-1 ? C->m-m*C->mb : C->mb;
            ldc = BLKLDD(C, m);
            for (n = 0; n < C->nt; n++) {
                tempnn = n == C->nt-1 ? C->n-n*C->nb : C->nb;
                lda = BLKLDD(A, n);
                ldb = BLKLDD(B, m);
                for (k = 0; k < C->nt; k++) {
                    tempkn = k == C->nt-1 ? C->n-k*C->nb : C->nb;
                    ldak = BLKLDD(A, k);
                    zbeta = k == 0 ? beta : zone;
                    if (k < n) {
                       MORSE_TASK_dgemm(
                           &options,
                           MorseNoTrans, MorseTrans,
                           tempmm, tempnn, tempkn, A->mb,
                           alpha, B(m, k), ldb,  /* ldb * K */
                           A(n, k), lda,  /* lda * K */
                           zbeta, C(m, n), ldc); /* ldc * Y */
                    }
                    else {
                        if (k == n) {
                           MORSE_TASK_dsymm(
                               &options,
                               MorseRight, uplo,
                               tempmm, tempnn, A->mb,
                               alpha, A(k, k), ldak, /* ldak * Y */
                               B(m, k), ldb,  /* ldb  * Y */
                               zbeta, C(m, n), ldc); /* ldc  * Y */
                        }
                        else {
                            MORSE_TASK_dgemm(
                                &options,
                                MorseNoTrans, MorseNoTrans,
                                tempmm, tempnn, tempkn, A->mb,
                                alpha, B(m, k), ldb,  /* ldb  * K */
                                A(k, n), ldak, /* ldak * Y */
                                zbeta, C(m, n), ldc); /* ldc  * Y */
                        }
                    }
                }
            }
        }
    }
    /*
     *  MorseUpper
     */
    else {
        /*
         *  DPOTRF
         */
        for (k = 0; k < A->nt; k++) {
            tempkm = k == A->nt-1 ? A->n-k*A->nb : A->nb;
            ldak = BLKLDD(A, k);
            MORSE_TASK_dpotrf(
                &options,
                MorseUpper,
                tempkm, A->mb,
                A(k, k), ldak, A->nb*k);

            for (n = k+1; n < A->nt; n++) {
                tempnn = n == A->nt-1 ? A->n - n*A->nb : A->nb;
                MORSE_TASK_dtrsm(
                    &options,
                    MorseLeft, MorseUpper, MorseTrans, MorseNonUnit,
                    A->mb, tempnn, A->mb,
                    zone, A(k, k), ldak,
		          A(k, n), ldak);
            }
            MORSE_TASK_dataflush( &options, A(k, k) );


	    for (m = k+1; m < A->mt; m++) {
		tempmm = m == A->mt-1 ? A->m - m*A->mb : A->mb;
		ldam = BLKLDD(A, m);

                MORSE_TASK_dsyrk(
                    &options,
                    MorseUpper, MorseTrans,
                    tempmm, A->mb, A->mb,
                    -1.0, A(k, m), ldak,
		     1.0, A(m, m), ldam);
 

		for (n = m+1; n < A->nt; n++) {
		    tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;

                    MORSE_TASK_dgemm(
                        &options,
                        MorseTrans, MorseNoTrans,
                        tempmm, tempnn, A->mb, A->mb,
                        mzone, A(k, m), ldak,
			       A(k, n), ldak,
                        zone,  A(m, n), ldam);
		}
		MORSE_TASK_dataflush( &options, A(k, m) );
	    }
	}
        /*
         *  DTRTRI
         */
        for (m = 0; m < A->mt; m++) {
            tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
            ldam = BLKLDD(A, m);
            for (n = m+1; n < A->nt; n++) {
                tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
                MORSE_TASK_dtrsm(
                    &options,
                    MorseLeft, uplo, MorseNoTrans, MorseNonUnit,
                    tempmm, tempnn, A->mb,
                    mzone, A(m, m), ldam,
                           A(m, n), ldam);
            }
            for (n = 0; n < m; n++) {
                tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
                ldan = BLKLDD(A, n);
                for (k = m+1; k < A->nt; k++) {
                    tempkn = k == A->nt-1 ? A->n-k*A->nb : A->nb;
                    MORSE_TASK_dgemm(
                        &options,
                        MorseNoTrans, MorseNoTrans,
                        tempnn, tempkn, tempmm, A->mb,
                        zone, A(n, m), ldan,
                              A(m, k), ldam,
                        zone, A(n, k), ldan);
                }
                MORSE_TASK_dtrsm(
                    &options,
                    MorseRight, uplo, MorseNoTrans, MorseNonUnit,
                    tempnn, tempmm, A->mb,
                    zone, A(m, m), ldam,
                          A(n, m), ldan);
            }
            MORSE_TASK_dtrtri(
                &options,
                uplo, MorseNonUnit,
                tempmm, A->mb,
                A(m, m), ldam, A->mb*m);
        }
        /*
         *  DLAUUM
         */
        for (m = 0; m < A->mt; m++) {
            tempmm = m == A->mt-1 ? A->m-m*A->mb : A->mb;
            ldam = BLKLDD(A, m);
            for (n = 0; n < m; n++) {
                tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
                MORSE_TASK_dsyrk(
                    &options,
                    uplo, MorseNoTrans,
                    tempnn, tempmm, A->mb,
                    1.0, A(n, m), A->mb,
                    1.0, A(n, n), A->mb);

                for (k = n+1; k < m; k++){
                    tempkm = k == A->mt-1 ? A->m-k*A->mb : A->mb;
                    MORSE_TASK_dgemm(
                        &options,
                        MorseNoTrans, MorseTrans,
                        tempnn, tempkm, tempmm, A->mb,
                        zone, A(n, m), A->mb,
                              A(k, m), A->mb,
                        zone, A(n, k), A->mb);
                }
            }
            for (n = 0; n < m; n++) {
                tempnn = n == A->nt-1 ? A->n-n*A->nb : A->nb;
                MORSE_TASK_dtrmm(
                    &options,
                    MorseRight, uplo, MorseTrans, MorseNonUnit,
                    tempnn, tempmm, A->mb,
                    zone, A(m, m), ldam,
                          A(n, m), A->mb);
            }
            MORSE_TASK_dlauum(
                &options,
                uplo,
                tempmm,
                A->mb, A(m, m), ldam);
        }
        /*
         *  DSYMM
         */
        for (m = 0; m < C->mt; m++) {
            tempmm = m == C->mt-1 ? C->m-m*C->mb : C->mb;
            ldc = BLKLDD(C, m);
            for (n = 0; n < C->nt; n++) {
                tempnn = n == C->nt-1 ? C->n-n*C->nb : C->nb;
                lda = BLKLDD(A, n);
                ldb = BLKLDD(B, m);
                for (k = 0; k < C->nt; k++) {
                    tempkn = k == C->nt-1 ? C->n-k*C->nb : C->nb;
                    ldak = BLKLDD(A, k);
                    zbeta = k == 0 ? beta : zone;
                    if (k < n) {
                        MORSE_TASK_dgemm(
                            &options,
                            MorseNoTrans, MorseNoTrans,
                            tempmm, tempnn, tempkn, A->mb,
                            alpha, B(m, k), ldb,  /* ldb  * K */
                            A(k, n), ldak, /* ldak * Y */
                            zbeta, C(m, n), ldc); /* ldc  * Y */
                    }
                    else {
                        if (k == n) {
                            MORSE_TASK_dsymm(
                                &options,
                                MorseRight, uplo,
                                tempmm, tempnn, A->mb,
                                alpha, A(k, k), ldak, /* ldak * Y */
                                B(m, k), ldb,  /* ldb  * Y */
                                zbeta, C(m, n), ldc); /* ldc  * Y */
                        }
                        else {
                            MORSE_TASK_dgemm(
                                &options,
                                MorseNoTrans, MorseTrans,
                                tempmm, tempnn, tempkn, A->mb,
                                alpha, B(m, k), ldb,  /* ldb * K */
                                A(n, k), lda,  /* lda * K */
                                zbeta, C(m, n), ldc); /* ldc * Y */
                        }
                    }
                }
            }
        }
    }

#ifdef CHAMELEON_USE_MAGMA
    RUNTIME_options_ws_free(&options);
#endif
    RUNTIME_options_finalize(&options, morse);
}
