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
 * @file core_dtsqrt.c
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
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:04 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "coreblas/include/coreblas.h"
#undef COMPLEX
#define REAL

/***************************************************************************//**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 * CORE_dtsqrt computes a QR factorization of a rectangular matrix
 * formed by coupling a real N-by-N upper triangular tile A1
 * on top of a real M-by-N tile A2:
 *
 *    | A1 | = Q * R
 *    | A2 |
 *
 *******************************************************************************
 *
 * @param[in] M
 *         The number of rows of the tile A2. M >= 0.
 *
 * @param[in] N
 *         The number of rows of the tile A1.
 *         The number of columns of the tiles A1 and A2. N >= 0.
 *
 * @param[in] IB
 *         The inner-blocking size.  IB >= 0.
 *
 * @param[in,out] A1
 *         On entry, the N-by-N tile A1.
 *         On exit, the elements on and above the diagonal of the array
 *         contain the N-by-N upper trapezoidal tile R;
 *         the elements below the diagonal are not referenced.
 *
 * @param[in] LDA1
 *         The leading dimension of the array A1. LDA1 >= max(1,N).
 *
 * @param[in,out] A2
 *         On entry, the M-by-N tile A2.
 *         On exit, all the elements with the array TAU, represent
 *         the unitary tile Q as a product of elementary reflectors
 *         (see Further Details).
 *
 * @param[in] LDA2
 *         The leading dimension of the tile A2. LDA2 >= max(1,M).
 *
 * @param[out] T
 *         The IB-by-N triangular factor T of the block reflector.
 *         T is upper triangular by block (economic storage);
 *         The rest of the array is not referenced.
 *
 * @param[in] LDT
 *         The leading dimension of the array T. LDT >= IB.
 *
 * @param[out] TAU
 *         The scalar factors of the elementary reflectors (see Further
 *         Details).
 *
 * @param[out] WORK
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *
 ******************************************************************************/


int CORE_dtsqrt(int M, int N, int IB,
                double *A1, int LDA1,
                double *A2, int LDA2,
                double *T, int LDT,
                double *TAU, double *WORK)
{
    static double zone  = 1.0;
    static double dzero = 0.0;

    double alpha;
    int i, ii, sb;

    /* Check input arguments */
    if (M < 0) {
        coreblas_error(1, "Illegal value of M");
        return -1;
    }
    if (N < 0) {
        coreblas_error(2, "Illegal value of N");
        return -2;
    }
    if (IB < 0) {
        coreblas_error(3, "Illegal value of IB");
        return -3;
    }
    if ((LDA2 < max(1,M)) && (M > 0)) {
        coreblas_error(8, "Illegal value of LDA2");
        return -8;
    }

    /* Quick return */
    if ((M == 0) || (N == 0) || (IB == 0))
        return MORSE_SUCCESS;

    for(ii = 0; ii < N; ii += IB) {
        sb = min(N-ii, IB);
        for(i = 0; i < sb; i++) {
            /*
             * Generate elementary reflector H( II*IB+I ) to annihilate
             * A( II*IB+I:M, II*IB+I )
             */
            LAPACKE_dlarfg_work(M+1, &A1[LDA1*(ii+i)+ii+i], &A2[LDA2*(ii+i)], 1, &TAU[ii+i]);

            if (ii+i+1 < N) {
                /*
                 * Apply H( II*IB+I ) to A( II*IB+I:M, II*IB+I+1:II*IB+IB ) from the left
                 */
                alpha = -conj(TAU[ii+i]);
                cblas_dcopy(
                    sb-i-1,
                    &A1[LDA1*(ii+i+1)+(ii+i)], LDA1,
                    WORK, 1);
#ifdef COMPLEX
                LAPACKE_dlacgv_work(sb-i-1, WORK, 1);
#endif
                cblas_dgemv(
                    CblasColMajor, (CBLAS_TRANSPOSE)MorseTrans,
                    M, sb-i-1,
                    (zone), &A2[LDA2*(ii+i+1)], LDA2,
                    &A2[LDA2*(ii+i)], 1,
                    (zone), WORK, 1);
#ifdef COMPLEX
                LAPACKE_dlacgv_work(sb-i-1, WORK, 1 );
#endif
                cblas_daxpy(
                    sb-i-1, (alpha),
                    WORK, 1,
                    &A1[LDA1*(ii+i+1)+ii+i], LDA1);
#ifdef COMPLEX
                LAPACKE_dlacgv_work(sb-i-1, WORK, 1 );
#endif
                cblas_dger(
                    CblasColMajor, M, sb-i-1, (alpha),
                    &A2[LDA2*(ii+i)], 1,
                    WORK, 1,
                    &A2[LDA2*(ii+i+1)], LDA2);
            }
            /*
             * Calculate T
             */
            alpha = -TAU[ii+i];
            cblas_dgemv(
                CblasColMajor, (CBLAS_TRANSPOSE)MorseTrans, M, i,
                (alpha), &A2[LDA2*ii], LDA2,
                &A2[LDA2*(ii+i)], 1,
                (dzero), &T[LDT*(ii+i)], 1);

            cblas_dtrmv(
                CblasColMajor, (CBLAS_UPLO)MorseUpper,
                (CBLAS_TRANSPOSE)MorseNoTrans, (CBLAS_DIAG)MorseNonUnit, i,
                &T[LDT*ii], LDT,
                &T[LDT*(ii+i)], 1);

            T[LDT*(ii+i)+i] = TAU[ii+i];
        }
        if (N > ii+sb) {
            CORE_dtsmqr(
                MorseLeft, MorseTrans,
                sb, N-(ii+sb), M, N-(ii+sb), IB, IB,
                &A1[LDA1*(ii+sb)+ii], LDA1,
                &A2[LDA2*(ii+sb)], LDA2,
                &A2[LDA2*ii], LDA2,
                &T[LDT*ii], LDT,
                WORK, sb);
        }
    }
    return MORSE_SUCCESS;
}


