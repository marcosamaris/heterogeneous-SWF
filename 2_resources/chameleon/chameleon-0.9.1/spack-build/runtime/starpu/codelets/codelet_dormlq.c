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
 * @file codelet_dormlq.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Hatem Ltaief
 * @author Jakub Kurzak
 * @author Dulceneia Becker
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:05 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_dormlq overwrites the general real M-by-N tile C with
 *
 *                    SIDE = 'L'     SIDE = 'R'
 *    TRANS = 'N':      Q * C          C * Q
 *    TRANS = 'C':      Q**T * C       C * Q**T
 *
 *  where Q is a real unitary matrix defined as the product of k
 *  elementary reflectors
 *
 *    Q = H(k) . . . H(2) H(1)
 *
 *  as returned by CORE_dgelqt. Q is of order M if SIDE = 'L' and of order N
 *  if SIDE = 'R'.
 *
 *******************************************************************************
 *
 * @param[in] side
 *         @arg MorseLeft  : apply Q or Q**T from the Left;
 *         @arg MorseRight : apply Q or Q**T from the Right.
 *
 * @param[in] trans
 *         @arg MorseNoTrans   :  No transpose, apply Q;
 *         @arg MorseTrans :  Transpose, apply Q**T.
 *
 * @param[in] M
 *         The number of rows of the tile C.  M >= 0.
 *
 * @param[in] N
 *         The number of columns of the tile C.  N >= 0.
 *
 * @param[in] K
 *         The number of elementary reflectors whose product defines
 *         the matrix Q.
 *         If SIDE = MorseLeft,  M >= K >= 0;
 *         if SIDE = MorseRight, N >= K >= 0.
 *
 * @param[in] IB
 *         The inner-blocking size.  IB >= 0.
 *
 * @param[in] A
 *         Dimension:  (LDA,M) if SIDE = MorseLeft,
 *                     (LDA,N) if SIDE = MorseRight,
 *         The i-th row must contain the vector which defines the
 *         elementary reflector H(i), for i = 1,2,...,k, as returned by
 *         CORE_dgelqt in the first k rows of its array argument A.
 *
 * @param[in] LDA
 *         The leading dimension of the array A.  LDA >= max(1,K).
 *
 * @param[in] T
 *         The IB-by-K triangular factor T of the block reflector.
 *         T is upper triangular by block (economic storage);
 *         The rest of the array is not referenced.
 *
 * @param[in] LDT
 *         The leading dimension of the array T. LDT >= IB.
 *
 * @param[in,out] C
 *         On entry, the M-by-N tile C.
 *         On exit, C is overwritten by Q*C or Q**T*C or C*Q**T or C*Q.
 *
 * @param[in] LDC
 *         The leading dimension of the array C. LDC >= max(1,M).
 *
 * @param[in,out] WORK
 *         On exit, if INFO = 0, WORK(1) returns the optimal LDWORK.
 *
 * @param[in] LDWORK
 *         The dimension of the array WORK.
 *         If SIDE = MorseLeft,  LDWORK >= max(1,N);
 *         if SIDE = MorseRight, LDWORK >= max(1,M).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *
 ******************************************************************************/

void MORSE_TASK_dormlq(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int k, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       MORSE_desc_t *C, int Cm, int Cn, int ldc)
{
    struct starpu_codelet *codelet = &cl_dormlq;
    void (*callback)(void*) = options->profiling ? cl_dormlq_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( T, Tm, Tn ) ||
         morse_desc_islocal( C, Cm, Cn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &side,              sizeof(MORSE_enum),
            STARPU_VALUE,    &trans,             sizeof(MORSE_enum),
            STARPU_VALUE,    &m,                 sizeof(int),
            STARPU_VALUE,    &n,                 sizeof(int),
            STARPU_VALUE,    &k,                 sizeof(int),
            STARPU_VALUE,    &ib,                sizeof(int),
            STARPU_R,         RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &lda,               sizeof(int),
            STARPU_R,         RTBLKADDR(T, double, Tm, Tn),
            STARPU_VALUE,    &ldt,               sizeof(int),
            STARPU_RW,        RTBLKADDR(C, double, Cm, Cn),
            STARPU_VALUE,    &ldc,               sizeof(int),
            /* ib * nb */
            STARPU_SCRATCH,   options->ws_worker,
            STARPU_VALUE,    &nb,                sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_dormlq_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum trans;
    int m;
    int n;
    int k;
    int ib;
    double *A;
    int lda;
    double *T;
    int ldt;
    double *C;
    int ldc;
    double *WORK;
    int ldwork;

    A    = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    T    = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C    = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    WORK = (double *)STARPU_MATRIX_GET_PTR(descr[3]); /* ib * nb */

    starpu_codelet_unpack_args(cl_arg, &side, &trans, &m, &n, &k, &ib,
                               &lda, &ldt, &ldc, &ldwork);

    CORE_dormlq(side, trans, m, n, k, ib,
                A, lda, T, ldt, C, ldc, WORK, ldwork);
}

#if defined(CHAMELEON_USE_MAGMA)

magma_int_t
magma_dormlqt_gpu( magma_side_t side, magma_trans_t trans,
                   magma_int_t M, magma_int_t N, magma_int_t K, magma_int_t IB,
                   const double *A,    magma_int_t LDA,
                   const double *T,    magma_int_t LDT,
                   double *C,    magma_int_t LDC,
                   double *WORK, magma_int_t LDWORK )
{
    int i, kb;
    int i1, i3;
    int nq, nw;
    int ic = 0;
    int jc = 0;
    int ni = N;
    int mi = M;

    /* Check input arguments */
    if ((side != MagmaLeft) && (side != MagmaRight)) {
        return -1;
    }
    /*
     * NQ is the order of Q and NW is the minimum dimension of WORK
     */
    if (side == MagmaLeft) {
        nq = M;
        nw = N;
    }
    else {
        nq = N;
        nw = M;
    }

    if ((trans != MagmaNoTrans) && (trans != MagmaTrans)) {
        return -2;
    }
    if (M < 0) {
        return -3;
    }
    if (N < 0) {
        return -4;
    }
    if ((K < 0) || (K > nq)) {
        return -5;
    }
    if ((IB < 0) || ( (IB == 0) && ((M > 0) && (N > 0)) )) {
        return -6;
    }
    if ((LDA < max(1,K)) && (K > 0)) {
        return -8;
    }
    if ((LDC < max(1,M)) && (M > 0)) {
        return -12;
    }
    if ((LDWORK < max(1,nw)) && (nw > 0)) {
        return -14;
    }

    /* Quick return */
    if ((M == 0) || (N == 0) || (K == 0))
        return MAGMA_SUCCESS;

    if (((side == MagmaLeft) && (trans == MagmaNoTrans))
        || ((side == MagmaRight) && (trans != MagmaNoTrans))) {
        i1 = 0;
        i3 = IB;
    }
    else {
        i1 = ( ( K-1 ) / IB )*IB;
        i3 = -IB;
    }

    if( trans == MorseNoTrans) {
        trans = MorseTrans;
    }
    else {
        trans = MorseNoTrans;
    }

    for(i = i1; (i >- 1) && (i < K); i+=i3 ) {
        kb = min(IB, K-i);

        if (side == MagmaLeft) {
            /*
             * H or H' is applied to C(i:m,1:n)
             */
            mi = M - i;
            ic = i;
        }
        else {
            /*
             * H or H' is applied to C(1:m,i:n)
             */
            ni = N - i;
            jc = i;
        }

        magma_dlarfb_gpu( side, trans, MagmaForward, MagmaRowwise,
                          mi, ni, kb,
                          A + LDA * i  + i,  LDA,
                          T + LDT * i,       LDT,
                          C + LDC * jc + ic, LDC,
                          WORK, LDWORK);
    }
    return MAGMA_SUCCESS;
}


static void cl_dormlq_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *d_work;
    MORSE_enum side;
    MORSE_enum trans;
    int m;
    int n;
    int k;
    int ib;
    double *A, *T, *C, *WORK;
    int lda, ldt, ldc, ldwork;
    int info = 0;

    starpu_codelet_unpack_args(cl_arg, &side, &trans, &m, &n, &k, &ib,
                               &lda, &ldt, &ldc, &ldwork);

    A    = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    T    = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C    = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    WORK = (double *)STARPU_MATRIX_GET_PTR(descr[3]); /* ib * nb */

    magma_dormlqt_gpu( side, trans, m, n, k, ib,
                       A, lda, T, ldt, C, ldc, WORK, ldwork );

    cudaThreadSynchronize();
}
#endif

/*
 * Codelet definition
 */
#if defined(CHAMELEON_USE_MAGMA) || defined(CHAMELEON_SIMULATION)
CODELETS(dormlq, 4, cl_dormlq_cpu_func, cl_dormlq_cuda_func, 0)
#else
CODELETS_CPU(dormlq, 4, cl_dormlq_cpu_func)
#endif
