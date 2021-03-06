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
 * @file core_stsmqr.c
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
 * @author Azzam Haidar
 * @author Dulceneia Becker
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated s Tue Sep 26 20:43:04 2017
 *
 **/
#include "coreblas/include/coreblas.h"

/***************************************************************************//**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_stsmqr overwrites the general real M1-by-N1 tile A1 and
 *  M2-by-N2 tile A2 with
 *
 *                        SIDE = 'L'        SIDE = 'R'
 *    TRANS = 'N':         Q * | A1 |     | A1 A2 | * Q
 *                             | A2 |
 *
 *    TRANS = 'C':      Q**T * | A1 |     | A1 A2 | * Q**T
 *                             | A2 |
 *
 *  where Q is a real unitary matrix defined as the product of k
 *  elementary reflectors
 *
 *    Q = H(1) H(2) . . . H(k)
 *
 *  as returned by CORE_STSQRT.
 *
 *******************************************************************************
 *
 * @param[in] side
 *         @arg MorseLeft  : apply Q or Q**T from the Left;
 *         @arg MorseRight : apply Q or Q**T from the Right.
 *
 * @param[in] trans
 *         @arg MorseNoTrans   :  No transpose, apply Q;
 *         @arg MorseTrans :  ConjTranspose, apply Q**T.
 *
 * @param[in] M1
 *         The number of rows of the tile A1. M1 >= 0.
 *
 * @param[in] N1
 *         The number of columns of the tile A1. N1 >= 0.
 *
 * @param[in] M2
 *         The number of rows of the tile A2. M2 >= 0.
 *         M2 = M1 if side == MorseRight.
 *
 * @param[in] N2
 *         The number of columns of the tile A2. N2 >= 0.
 *         N2 = N1 if side == MorseLeft.
 *
 * @param[in] K
 *         The number of elementary reflectors whose product defines
 *         the matrix Q.
 *
 * @param[in] IB
 *         The inner-blocking size.  IB >= 0.
 *
 * @param[in,out] A1
 *         On entry, the M1-by-N1 tile A1.
 *         On exit, A1 is overwritten by the application of Q.
 *
 * @param[in] LDA1
 *         The leading dimension of the array A1. LDA1 >= max(1,M1).
 *
 * @param[in,out] A2
 *         On entry, the M2-by-N2 tile A2.
 *         On exit, A2 is overwritten by the application of Q.
 *
 * @param[in] LDA2
 *         The leading dimension of the tile A2. LDA2 >= max(1,M2).
 *
 * @param[in] V
 *         The i-th row must contain the vector which defines the
 *         elementary reflector H(i), for i = 1,2,...,k, as returned by
 *         CORE_STSQRT in the first k columns of its array argument V.
 *
 * @param[in] LDV
 *         The leading dimension of the array V. LDV >= max(1,K).
 *
 * @param[in] T
 *         The IB-by-N1 triangular factor T of the block reflector.
 *         T is upper triangular by block (economic storage);
 *         The rest of the array is not referenced.
 *
 * @param[in] LDT
 *         The leading dimension of the array T. LDT >= IB.
 *
 * @param[out] WORK
 *         Workspace array of size
 *             LDWORK-by-N1 if side == MorseLeft
 *             LDWORK-by-IB if side == MorseRight
 *
 * @param[in] LDWORK
 *         The leading dimension of the array WORK.
 *             LDWORK >= max(1,IB) if side == MorseLeft
 *             LDWORK >= max(1,M1) if side == MorseRight
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *
 ******************************************************************************/

int CORE_stsmqr(MORSE_enum side, MORSE_enum trans,
                int M1, int N1, int M2, int N2, int K, int IB,
                float *A1, int LDA1,
                float *A2, int LDA2,
                const float *V, int LDV,
                const float *T, int LDT,
                float *WORK, int LDWORK)
{
    int i, i1, i3;
    int NQ, NW;
    int kb;
    int ic = 0;
    int jc = 0;
    int mi = M1;
    int ni = N1;

    /* Check input arguments */
    if ((side != MorseLeft) && (side != MorseRight)) {
        coreblas_error(1, "Illegal value of side");
        return -1;
    }

    /* NQ is the order of Q */
    if (side == MorseLeft) {
        NQ = M2;
        NW = IB;
    }
    else {
        NQ = N2;
        NW = M1;
    }

    if ((trans != MorseNoTrans) && (trans != MorseTrans)) {
        coreblas_error(2, "Illegal value of trans");
        return -2;
    }
    if (M1 < 0) {
        coreblas_error(3, "Illegal value of M1");
        return -3;
    }
    if (N1 < 0) {
        coreblas_error(4, "Illegal value of N1");
        return -4;
    }
    if ( (M2 < 0) ||
         ( (M2 != M1) && (side == MorseRight) ) ){
        coreblas_error(5, "Illegal value of M2");
        return -5;
    }
    if ( (N2 < 0) ||
         ( (N2 != N1) && (side == MorseLeft) ) ){
        coreblas_error(6, "Illegal value of N2");
        return -6;
    }
    if ((K < 0) ||
        ( (side == MorseLeft)  && (K > M1) ) ||
        ( (side == MorseRight) && (K > N1) ) ) {
        coreblas_error(7, "Illegal value of K");
        return -7;
    }
    if (IB < 0) {
        coreblas_error(8, "Illegal value of IB");
        return -8;
    }
    if (LDA1 < max(1,M1)){
        coreblas_error(10, "Illegal value of LDA1");
        return -10;
    }
    if (LDA2 < max(1,M2)){
        coreblas_error(12, "Illegal value of LDA2");
        return -12;
    }
    if (LDV < max(1,NQ)){
        coreblas_error(14, "Illegal value of LDV");
        return -14;
    }
    if (LDT < max(1,IB)){
        coreblas_error(16, "Illegal value of LDT");
        return -16;
    }
    if (LDWORK < max(1,NW)){
        coreblas_error(18, "Illegal value of LDWORK");
        return -18;
    }

    /* Quick return */
    if ((M1 == 0) || (N1 == 0) || (M2 == 0) || (N2 == 0) || (K == 0) || (IB == 0))
        return MORSE_SUCCESS;

    if (((side == MorseLeft)  && (trans != MorseNoTrans))
        || ((side == MorseRight) && (trans == MorseNoTrans))) {
        i1 = 0;
        i3 = IB;
    }
    else {
        i1 = ((K-1) / IB)*IB;
        i3 = -IB;
    }

    for(i = i1; (i > -1) && (i < K); i += i3) {
        kb = min(IB, K-i);

        if (side == MorseLeft) {
            /*
             * H or H' is applied to C(i:m,1:n)
             */
            mi = M1 - i;
            ic = i;
        }
        else {
            /*
             * H or H' is applied to C(1:m,i:n)
             */
            ni = N1 - i;
            jc = i;
        }
        /*
         * Apply H or H' (NOTE: CORE_sparfb used to be CORE_stsrfb)
         */
        CORE_sparfb(
            side, trans, MorseForward, MorseColumnwise,
            mi, ni, M2, N2, kb, 0,
            &A1[LDA1*jc+ic], LDA1,
            A2, LDA2,
            &V[LDV*i], LDV,
            &T[LDT*i], LDT,
            WORK, LDWORK);
    }
    return MORSE_SUCCESS;
}


