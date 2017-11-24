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
 * @file core_csytf2_nopiv.c
 *
 *  PLASMA core_blas kernel
 *  PLASMA is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Hatem Ltaief
 * @author Jakub Kurzak
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @author Florent Pruvost
 * @author Marc Sergent
 * @date 2014-10-10
 * @generated c Tue Sep 26 20:43:03 2017
 *
 **/
#include "coreblas/include/coreblas.h"

/***************************************************************************//**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

static MORSE_Complex32_t zone  =  1.;
static MORSE_Complex32_t mzone = -1.;

int CORE_csytf2_nopiv(MORSE_enum uplo, int n, MORSE_Complex32_t *A, int lda)
{
    MORSE_Complex32_t *Akk = A;   /* A [k  ][k] */
    MORSE_Complex32_t *Amk;
    MORSE_Complex32_t  alpha;
    int k;

    if (n == 0)
        return 0;

    if ( uplo == MorseLower )
    {
        for ( k=0; k<n-1; k++ )
        {
            Amk = Akk+1; /* A [k+1][k] */

            *Akk = csqrtf(*Akk);
            if ( *Akk == 0.0 )
                return k+1;

            alpha = 1. / (*Akk);

            /* Scale the diagonal to compute L((k+1):n,k) */
            cblas_cscal(n-k-1, CBLAS_SADDR( alpha ), Amk, 1 );

            /* Move to next Akk */
            Akk += (lda+1);

            cblas_csyrk(CblasColMajor, CblasLower, CblasNoTrans,
                        n-k-1, 1,
                        CBLAS_SADDR( mzone ), Amk, lda,
                        CBLAS_SADDR( zone  ), Akk, lda);
        }
    }
    else
    {
        for ( k=0; k<n-1; k++ )
        {
            Amk = Akk + lda;  /* A [k][k+1] */

            *Akk = csqrtf(*Akk);
            if ( *Akk == 0.0 )
                return k+1;

            alpha = 1. / (*Akk);

            /* Scale the diagonal to compute L((k+1):n,k) */
            cblas_cscal(n-k-1, CBLAS_SADDR( alpha ), Amk, lda );

            /* Move to next Akk */
            Akk += (lda+1);

            cblas_csyrk(CblasColMajor, CblasUpper, CblasTrans,
                        n-k-1, 1,
                        CBLAS_SADDR( mzone ), Amk, lda,
                        CBLAS_SADDR( zone  ), Akk, lda);
        }
    }

    /* Factorize last diagonal element */
    *Akk = csqrtf(*Akk);
    if ( *Akk == 0.0 )
        return n;

    return 0;
}

