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
 * @file core_sparfb.c
 *
 *  PLASMA core_blas kernel
 *  PLASMA is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Dulceneia Becker
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2011-06-14
 * @generated s Tue Sep 26 20:43:02 2017
 *
 **/
#include "coreblas/include/cblas.h"
#include "coreblas/include/lapacke.h"
#include "coreblas/include/coreblas.h"

/***************************************************************************//**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_sparfb applies a real upper triangular block reflector H
 *  or its transpose H' to a real rectangular matrix formed by
 *  coupling two tiles A1 and A2. Matrix V is:
 *
 *          COLUMNWISE                    ROWWISE
 *
 *         |     K     |                 |      N2-L     |   L  |
 *      __ _____________ __           __ _________________        __
 *         |    |      |                 |               | \
 *         |    |      |                 |               |   \    L
 *    M2-L |    |      |              K  |_______________|_____\  __
 *         |    |      | M2              |                      |
 *      __ |____|      |                 |                      | K-L
 *         \    |      |              __ |______________________| __
 *       L   \  |      |
 *      __     \|______| __              |          N2          |
 *
 *         | L |  K-L  |
 *
 *******************************************************************************
 *
 * @param[in] side
 *         @arg MorseLeft  : apply Q or Q**T from the Left;
 *         @arg MorseRight : apply Q or Q**T from the Right.
 *
 * @param[in] trans
 *         @arg MorseNoTrans   : No transpose, apply Q;
 *         @arg MorseTrans : ConjTranspose, apply Q**T.
 *
 * @param[in] direct
 *         Indicates how H is formed from a product of elementary
 *         reflectors
 *         @arg MorseForward  : H = H(1) H(2) . . . H(k) (Forward)
 *         @arg MorseBackward : H = H(k) . . . H(2) H(1) (Backward)
 *
 * @param[in] storev
 *         Indicates how the vectors which define the elementary
 *         reflectors are stored:
 *         @arg MorseColumnwise
 *         @arg MorseRowwise
 *
 * @param[in] M1
 *         The number of columns of the tile A1. M1 >= 0.
 *
 * @param[in] N1
 *         The number of rows of the tile A1. N1 >= 0.
 *
 * @param[in] M2
 *         The number of columns of the tile A2. M2 >= 0.
 *
 * @param[in] N2
 *         The number of rows of the tile A2. N2 >= 0.
 *
 * @param[in] K
 *         The order of the matrix T (= the number of elementary
 *         reflectors whose product defines the block reflector).
 *
 * @param[in] L
 *         The size of the triangular part of V
 *
 * @param[in,out] A1
 *         On entry, the M1-by-N1 tile A1.
 *         On exit, A1 is overwritten by the application of Q.
 *
 * @param[in] LDA1
 *         The leading dimension of the array A1. LDA1 >= max(1,N1).
 *
 * @param[in,out] A2
 *         On entry, the M2-by-N2 tile A2.
 *         On exit, A2 is overwritten by the application of Q.
 *
 * @param[in] LDA2
 *         The leading dimension of the tile A2. LDA2 >= max(1,N2).
 *
 * @param[in] V
 *         (LDV,K) if STOREV = 'C'
 *         (LDV,M2) if STOREV = 'R' and SIDE = 'L'
 *         (LDV,N2) if STOREV = 'R' and SIDE = 'R'
 *         Matrix V.
 *
 * @param[in] LDV
 *         The leading dimension of the array V.
 *         If STOREV = 'C' and SIDE = 'L', LDV >= max(1,M2);
 *         if STOREV = 'C' and SIDE = 'R', LDV >= max(1,N2);
 *         if STOREV = 'R', LDV >= K.
 *
 * @param[out] T
 *         The triangular K-by-K matrix T in the representation of the
 *         block reflector.
 *         T is upper triangular by block (economic storage);
 *         The rest of the array is not referenced.
 *
 * @param[in] LDT
 *         The leading dimension of the array T. LDT >= K.
 *
 * @param[in,out] WORK
 *
 * @param[in] LDWORK
 *         The dimension of the array WORK.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *
 ******************************************************************************/
/* This kernel is never traced so return type on previous line for convert2eztrace.pl script */
int
CORE_sparfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev,
            int M1, int N1, int M2, int N2, int K, int L,
                  float *A1, int LDA1,
                  float *A2, int LDA2,
            const float *V, int LDV,
            const float *T, int LDT,
                  float *WORK, int LDWORK)
{
    static float zone  =  1.0;
    static float mzone = -1.0;

    int j;

    /* Check input arguments */
    if ((side != MorseLeft) && (side != MorseRight)) {
        coreblas_error(1, "Illegal value of side");
        return -1;
    }
    if ((trans != MorseNoTrans) && (trans != MorseTrans)) {
        coreblas_error(2, "Illegal value of trans");
        return -2;
    }
    if ((direct != MorseForward) && (direct != MorseBackward)) {
        coreblas_error(3, "Illegal value of direct");
        return -3;
    }
    if ((storev != MorseColumnwise) && (storev != MorseRowwise)) {
        coreblas_error(4, "Illegal value of storev");
        return -4;
    }
    if (M1 < 0) {
        coreblas_error(5, "Illegal value of M1");
        return -5;
    }
    if (N1 < 0) {
        coreblas_error(6, "Illegal value of N1");
        return -6;
    }
    if ((M2 < 0) ||
        ( (side == MorseRight) && (M1 != M2) ) ) {
        coreblas_error(7, "Illegal value of M2");
        return -7;
    }
    if ((N2 < 0) ||
        ( (side == MorseLeft) && (N1 != N2) ) ) {
        coreblas_error(8, "Illegal value of N2");
        return -8;
    }
    if (K < 0) {
        coreblas_error(9, "Illegal value of K");
        return -9;
    }

    /* Quick return */
    if ((M1 == 0) || (N1 == 0) || (M2 == 0) || (N2 == 0) || (K == 0))
        return MORSE_SUCCESS;

    if (direct == MorseForward) {

        if (side == MorseLeft) {

            /*
             * Column or Rowwise / Forward / Left
             * ----------------------------------
             *
             * Form  H * A  or  H' * A  where  A = ( A1 )
             *                                     ( A2 )
             */

            /* W = A1 + op(V) * A2 */
            CORE_spamm(
                    MorseW, MorseLeft, storev,
                    K, N1, M2, L,
                    A1, LDA1,
                    A2, LDA2,
                    V, LDV,
                    WORK, LDWORK);

            /* W = op(T) * W */
            cblas_strmm(
                CblasColMajor, CblasLeft, CblasUpper,
                (CBLAS_TRANSPOSE)trans, CblasNonUnit, K, N2,
                (zone), T, LDT, WORK, LDWORK);

            /* A1 = A1 - W */
            for(j = 0; j < N1; j++) {
                cblas_saxpy(
                        K, (mzone),
                        &WORK[LDWORK*j], 1,
                        &A1[LDA1*j], 1);
            }

            /* A2 = A2 - op(V) * W  */
            /* W also changes: W = V * W, A2 = A2 - W */
            CORE_spamm(
                    MorseA2, MorseLeft, storev,
                    M2, N2, K, L,
                    A1, LDA1,
                    A2, LDA2,
                    V, LDV,
                    WORK, LDWORK);
        }
        else {
            /*
             * Column or Rowwise / Forward / Right
             * -----------------------------------
             *
             * Form  H * A  or  H' * A  where A  = ( A1 A2 )
             *
             */

            /* W = A1 + A2 * op(V) */
            CORE_spamm(
                    MorseW, MorseRight, storev,
                    M1, K, N2, L,
                    A1, LDA1,
                    A2, LDA2,
                    V, LDV,
                    WORK, LDWORK);

            /* W = W * op(T) */
            cblas_strmm(
                CblasColMajor, CblasRight, CblasUpper,
                (CBLAS_TRANSPOSE)trans, CblasNonUnit, M2, K,
                (zone), T, LDT, WORK, LDWORK);

            /* A1 = A1 - W */
            for(j = 0; j < K; j++) {
                cblas_saxpy(
                        M1, (mzone),
                        &WORK[LDWORK*j], 1,
                        &A1[LDA1*j], 1);
            }

            /* A2 = A2 - W * op(V) */
            /* W also changes: W = W * V', A2 = A2 - W */
            CORE_spamm(
                    MorseA2, MorseRight, storev,
                    M2, N2, K, L,
                    A1, LDA1,
                    A2, LDA2,
                    V, LDV,
                    WORK, LDWORK);
        }
    }
    else {
        coreblas_error(3, "Not implemented (Backward / Left or Right)");
        return MORSE_ERR_NOT_SUPPORTED;
    }

    return MORSE_SUCCESS;
}