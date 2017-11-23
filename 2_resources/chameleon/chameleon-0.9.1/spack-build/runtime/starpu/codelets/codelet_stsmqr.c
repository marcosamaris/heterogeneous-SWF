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
 * @file codelet_stsmqr.c
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
 * @author Azzam Haidar
 * @author Dulceneia Becker
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated s Tue Sep 26 20:43:04 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_s.h"

/**
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

void MORSE_TASK_stsmqr(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt)
{
    struct starpu_codelet *codelet = &cl_stsmqr;
    void (*callback)(void*) = options->profiling ? cl_stsmqr_callback : NULL;
    int ldwork = side == MorseLeft ? ib : nb;

    if ( morse_desc_islocal( A1, A1m, A1n ) ||
         morse_desc_islocal( A2, A2m, A2n ) ||
         morse_desc_islocal( V,  Vm,  Vn  ) ||
         morse_desc_islocal( T,  Tm,  Tn  ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &side,              sizeof(MORSE_enum),
            STARPU_VALUE,    &trans,             sizeof(MORSE_enum),
            STARPU_VALUE,    &m1,                sizeof(int),
            STARPU_VALUE,    &n1,                sizeof(int),
            STARPU_VALUE,    &m2,                sizeof(int),
            STARPU_VALUE,    &n2,                sizeof(int),
            STARPU_VALUE,    &k,                 sizeof(int),
            STARPU_VALUE,    &ib,                sizeof(int),
            STARPU_RW,        RTBLKADDR(A1, float, A1m, A1n),
            STARPU_VALUE,    &lda1,              sizeof(int),
            STARPU_RW,        RTBLKADDR(A2, float, A2m, A2n),
            STARPU_VALUE,    &lda2,              sizeof(int),
            STARPU_R,         RTBLKADDR(V, float, Vm, Vn),
            STARPU_VALUE,    &ldv,               sizeof(int),
            STARPU_R,         RTBLKADDR(T, float, Tm, Tn),
            STARPU_VALUE,    &ldt,               sizeof(int),
            /* max( ib*nb, 2*ib*nb ) */
            STARPU_SCRATCH,   options->ws_worker,
            STARPU_VALUE,    &ldwork,            sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_stsmqr_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum trans;
    int m1;
    int n1;
    int m2;
    int n2;
    int k;
    int ib;
    float *A1;
    int lda1;
    float *A2;
    int lda2;
    float *V;
    int ldv;
    float *T;
    int ldt;
    float *WORK;
    int ldwork;

    A1   = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    A2   = (float *)STARPU_MATRIX_GET_PTR(descr[1]);
    V    = (float *)STARPU_MATRIX_GET_PTR(descr[2]);
    T    = (float *)STARPU_MATRIX_GET_PTR(descr[3]);
    WORK = (float *)STARPU_MATRIX_GET_PTR(descr[4]); /* ib * nb */

    starpu_codelet_unpack_args(cl_arg, &side, &trans, &m1, &n1, &m2, &n2, &k, &ib,
                               &lda1, &lda2, &ldv, &ldt, &ldwork);

    CORE_stsmqr(side, trans, m1, n1, m2, n2, k, ib,
                A1, lda1, A2, lda2, V, ldv, T, ldt, WORK, ldwork);
}


#if defined(CHAMELEON_USE_MAGMA)

#if defined(CHAMELEON_USE_CUBLAS_V2)
magma_int_t
magma_sparfb_gpu(magma_side_t side, magma_trans_t trans,
		         magma_direct_t direct, magma_storev_t storev,
		         magma_int_t M1, magma_int_t N1,
		         magma_int_t M2, magma_int_t N2,
		         magma_int_t K, magma_int_t L,
		               float *A1, magma_int_t LDA1,
		               float *A2, magma_int_t LDA2,
		         const float *V, magma_int_t LDV,
		         const float *T, magma_int_t LDT,
		               float *WORK, magma_int_t LDWORK,
		               float *WORKC, magma_int_t LDWORKC,
		               CUstream stream)

{
#if defined(PRECISION_z) || defined(PRECISION_c)
    float szero = float(0.0, 0.0);
    float zone  = float(1.0, 0.0);
    float mzone = float(-1.0, 0.0);
#else
    float szero = 0.0;
    float zone  = 1.0;
    float mzone = -1.0;
#endif /* defined(PRECISION_z) || defined(PRECISION_c) */

    int j;
    magma_trans_t transW;
    magma_trans_t transA2;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasOperation_t cublasTrans;
    cublasOperation_t cublasTransW;
    cublasOperation_t cublasTransA2;

    stat = cublasCreate(&handle);
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("CUBLAS initialization failed\n");
        assert( stat == CUBLAS_STATUS_SUCCESS );
    }

    stat = cublasSetStream(handle, stream);
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("cublasSetStream failed\n");
        assert( stat == CUBLAS_STATUS_SUCCESS );
    }

    if (trans == MagmaNoTrans){
        cublasTrans = CUBLAS_OP_N;
    }else if(trans == MagmaTrans){
        cublasTrans = CUBLAS_OP_T;
    }else if(trans == MagmaTrans){
        cublasTrans = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in magma_sparfb_gpu: bad trans parameter %d\n", trans);
    }

    /* Check input arguments */
    if ((side != MagmaLeft) && (side != MagmaRight)) {
        return -1;
    }
    if ((trans != MagmaNoTrans) && (trans != MagmaTrans)) {
        return -2;
    }
    if ((direct != MagmaForward) && (direct != MagmaBackward)) {
        return -3;
    }
    if ((storev != MagmaColumnwise) && (storev != MagmaRowwise)) {
        return -4;
    }
    if (M1 < 0) {
        return -5;
    }
    if (N1 < 0) {
        return -6;
    }
    if ((M2 < 0) ||
        ( (side == MagmaRight) && (M1 != M2) ) ) {
        return -7;
    }
    if ((N2 < 0) ||
        ( (side == MagmaLeft) && (N1 != N2) ) ) {
        return -8;
    }
    if (K < 0) {
        return -9;
    }

    /* Quick return */
    if ((M1 == 0) || (N1 == 0) || (M2 == 0) || (N2 == 0) || (K == 0))
        return MAGMA_SUCCESS;

    if (direct == MagmaForward) {

        if (side == MagmaLeft) {

            /*
             * Column or Rowwise / Forward / Left
             * ----------------------------------
             *
             * Form  H * A  or  H' * A  where  A = ( A1 )
             *                                     ( A2 )
             */

            /*
             * W = A1 + V' * A2:
             *      W = A1
             *      W = W + V' * A2
             *
             */
            cudaMemcpy2DAsync( WORK, LDWORK * sizeof(float),
                               A1,   LDA1   * sizeof(float),
                               K * sizeof(float), N1,
                               cudaMemcpyDeviceToDevice, stream );

            transW  = storev == MorseColumnwise ? MagmaTrans : MagmaNoTrans;
            transA2 = storev == MorseColumnwise ? MagmaNoTrans : MagmaTrans;

            if (transW == MagmaNoTrans){
                cublasTransW = CUBLAS_OP_N;
            }else if(transW == MagmaTrans){
                cublasTransW = CUBLAS_OP_T;
            }else if(transW == MagmaTrans){
                cublasTransW = CUBLAS_OP_C;
            }else{
                fprintf(stderr, "Error in magma_sparfb_gpu: bad transW parameter %d\n", transW);
            }
            if (transA2 == MagmaNoTrans){
                cublasTransA2 = CUBLAS_OP_N;
            }else if(transA2 == MagmaTrans){
                cublasTransA2 = CUBLAS_OP_T;
            }else if(transA2 == MagmaTrans){
                cublasTransA2 = CUBLAS_OP_C;
            }else{
                fprintf(stderr, "Error in magma_sparfb_gpu: bad transA2 parameter %d\n", transA2);
            }

            cublasSgemm(handle, cublasTransW, CUBLAS_OP_N,
                        K, N1, M2,
                        (const float *) &zone,
                        (const float*)V     /* K*M2  */, LDV,
                        (const float*)A2    /* M2*N1 */, LDA2,
                        (const float *) &zone,
                        (float*)WORK  /* K*N1  */, LDWORK);

            if (WORKC == NULL) {
                /* W = op(T) * W */
                cublasStrmm( handle,
                    CUBLAS_SIDE_LEFT, CUBLAS_FILL_MODE_UPPER,
                    cublasTrans, CUBLAS_DIAG_NON_UNIT,
                    K, N2,
                    (const float *) &zone,
                    (const float*)T, LDT,
                    (float*)WORK, LDWORK,
                    (float*)WORK, LDWORK);


                /* A1 = A1 - W = A1 - op(T) * W */
                for(j = 0; j < N1; j++) {
                    cublasSaxpy(handle, K, (const float *) &mzone,
                                (const float*)(WORK + LDWORK*j), 1,
                                (float*)(A1 + LDA1*j), 1);
                }

                /* A2 = A2 - op(V) * W  */
                cublasSgemm(handle, cublasTransA2, CUBLAS_OP_N,
                            M2, N2, K,
                            (const float *) &mzone,
                            (const float*)V     /* M2*K  */, LDV,
                            (const float*)WORK  /* K*N2  */, LDWORK,
                            (const float *) &zone,
                            (float*)A2    /* m2*N2 */, LDA2);

            } else {
                /* Wc = V * op(T) */
                cublasSgemm( handle, cublasTransA2, cublasTrans,
                             M2, K, K,
                             (const float *) &zone,  V,     LDV,
                                    T,     LDT,
                             (const float *) &szero, WORKC, LDWORKC );

                /* A1 = A1 - opt(T) * W */
                cublasSgemm( handle, cublasTrans, CUBLAS_OP_N,
                             K, N1, K,
                             (const float *) &mzone,
                             (const float *)T,    LDT,
                             (const float *)WORK, LDWORK,
                             (const float *) &zone,
                             (float*)A1,   LDA1 );

                /* A2 = A2 - Wc * W */
                cublasSgemm( handle, CUBLAS_OP_N, CUBLAS_OP_N,
                             M2, N2, K,
                             (const float *) &mzone,
                             (const float *)WORKC, LDWORKC,
                             (const float *)WORK,  LDWORK,
                             (const float *) &zone,
                             (float *)A2,    LDA2 );
            }
        }
        else {
            /*
             * Column or Rowwise / Forward / Right
             * -----------------------------------
             *
             * Form  H * A  or  H' * A  where A  = ( A1 A2 )
             *
             */

            /*
             * W = A1 + A2 * V':
             *      W = A1
             *      W = W + A2 * V'
             *
             */
            cudaMemcpy2DAsync( WORK, LDWORK * sizeof(float),
                               A1,   LDA1   * sizeof(float),
                               M1 * sizeof(float), K,
                               cudaMemcpyDeviceToDevice, stream );

            transW  = storev == MorseColumnwise ? MagmaNoTrans : MagmaTrans;
            transA2 = storev == MorseColumnwise ? MagmaTrans : MagmaNoTrans;

            if (transW == MagmaNoTrans){
                cublasTransW = CUBLAS_OP_N;
            }else if(transW == MagmaTrans){
                cublasTransW = CUBLAS_OP_T;
            }else if(transW == MagmaTrans){
                cublasTransW = CUBLAS_OP_C;
            }else{
                fprintf(stderr, "Error in magma_sparfb_gpu: bad transW parameter %d\n", transW);
            }
            if (transA2 == MagmaNoTrans){
                cublasTransA2 = CUBLAS_OP_N;
            }else if(transA2 == MagmaTrans){
                cublasTransA2 = CUBLAS_OP_T;
            }else if(transA2 == MagmaTrans){
                cublasTransA2 = CUBLAS_OP_C;
            }else{
                fprintf(stderr, "Error in magma_sparfb_gpu: bad transA2 parameter %d\n", transA2);
            }

            cublasSgemm(handle, CUBLAS_OP_N, cublasTransW,
                        M1, K, N2,
                        (const float *) &zone,
                        (const float*)A2    /* M1*N2 */, LDA2,
                        (const float*)V     /* N2*K  */, LDV,
                        (const float *) &zone,
                        (float*)WORK  /* M1*K  */, LDWORK);

            if (WORKC == NULL) {
                /* W = W * op(T) */
                cublasStrmm( handle,
                    CUBLAS_SIDE_RIGHT, CUBLAS_FILL_MODE_UPPER,
                    cublasTrans, CUBLAS_DIAG_NON_UNIT,
                    M2, K,
                    (const float *) &zone,
                    (const float*)T, LDT,
                    (float*)WORK, LDWORK,
                    (float*)WORK, LDWORK);


                /* A1 = A1 - W = A1 - W * op(T) */
                for(j = 0; j < K; j++) {
                    cublasSaxpy(handle, M1, (const float *) &mzone,
                        (const float*)(WORK + LDWORK*j), 1,
                        (float*)(A1 + LDA1*j), 1);
                }

                /* A2 = A2 - W * op(V)  */
                cublasSgemm(handle, CUBLAS_OP_N, cublasTransA2,
                            M2, N2, K,
                            (const float *) &mzone,
                            (const float*)WORK  /* M2*K  */, LDWORK,
                            (const float*)V     /* K*N2  */, LDV,
                            (const float *) &zone,
                            (float*)A2    /* M2*N2 */, LDA2);

            } else {
                /* A1 = A1 - W * opt(T) */
                cublasSgemm( handle, CUBLAS_OP_N, cublasTrans,
                    M1, K, K,
                    (const float *) &mzone,
                    (const float *)WORK, LDWORK,
                    (const float *)T,    LDT,
                    (const float *) &zone,
                    (float *)A1,   LDA1 );

                /* Wc = op(T) * V */
                cublasSgemm( handle, cublasTrans, cublasTransA2,
                             K, N2, K,
                             (const float *) &zone,
                             (const float *)T,     LDT,
                             (const float *)V,     LDV,
                             (const float *) &szero,
                             (float *)WORKC, LDWORKC );

                /* A2 = A2 - W * Wc */
                cublasSgemm( handle, CUBLAS_OP_N, CUBLAS_OP_N,
                             M2, N2, K,
                             (const float *) &mzone,
                             (const float *)WORK,  LDWORK,
                             (const float *)WORKC, LDWORKC,
                             (const float *) &zone,
                             (float *)A2,    LDA2 );
            }
        }
    }
    else {
        fprintf(stderr, "Not implemented (Backward / Left or Right)");
        return MAGMA_ERR_NOT_SUPPORTED;
    }

    cublasDestroy(handle);

    return MAGMA_SUCCESS;
}
#else /* CHAMELEON_USE_CUBLAS_V2 */
magma_int_t
magma_sparfb_gpu(magma_side_t side, magma_trans_t trans,
                 magma_direct_t direct, magma_storev_t storev,
                 magma_int_t M1, magma_int_t N1,
                 magma_int_t M2, magma_int_t N2,
                 magma_int_t K, magma_int_t L,
                       float *A1, magma_int_t LDA1,
                       float *A2, magma_int_t LDA2,
                 const float *V, magma_int_t LDV,
                 const float *T, magma_int_t LDT,
                       float *WORK, magma_int_t LDWORK,
                       float *WORKC, magma_int_t LDWORKC,
                       CUstream stream)
{
#if defined(PRECISION_z) || defined(PRECISION_c)
    float szero = float(0.0, 0.0);
    float zone  = float(1.0, 0.0);
    float mzone = float(-1.0, 0.0);
#else
    float szero = 0.0;
    float zone  = 1.0;
    float mzone = -1.0;
#endif /* defined(PRECISION_z) || defined(PRECISION_c) */

    int j;
    magma_trans_t transW;
    magma_trans_t transA2;

    /* Check input arguments */
    if ((side != MagmaLeft) && (side != MagmaRight)) {
        return -1;
    }
    if ((trans != MagmaNoTrans) && (trans != MagmaTrans)) {
        return -2;
    }
    if ((direct != MagmaForward) && (direct != MagmaBackward)) {
        return -3;
    }
    if ((storev != MagmaColumnwise) && (storev != MagmaRowwise)) {
        return -4;
    }
    if (M1 < 0) {
        return -5;
    }
    if (N1 < 0) {
        return -6;
    }
    if ((M2 < 0) ||
        ( (side == MagmaRight) && (M1 != M2) ) ) {
        return -7;
    }
    if ((N2 < 0) ||
        ( (side == MagmaLeft) && (N1 != N2) ) ) {
        return -8;
    }
    if (K < 0) {
        return -9;
    }

    /* Quick return */
    if ((M1 == 0) || (N1 == 0) || (M2 == 0) || (N2 == 0) || (K == 0))
        return MAGMA_SUCCESS;

    if (direct == MagmaForward) {

        if (side == MagmaLeft) {

            /*
             * Column or Rowwise / Forward / Left
             * ----------------------------------
             *
             * Form  H * A  or  H' * A  where  A = ( A1 )
             *                                     ( A2 )
             */

            /*
             * W = A1 + V' * A2:
             *      W = A1
             *      W = W + V' * A2
             *
             */
            cudaMemcpy2DAsync( WORK, LDWORK * sizeof(float),
                               A1,   LDA1   * sizeof(float),
                               K * sizeof(float), N1,
                               cudaMemcpyDeviceToDevice, stream );

            transW  = storev == MorseColumnwise ? MagmaTrans : MagmaNoTrans;
            transA2 = storev == MorseColumnwise ? MagmaNoTrans : MagmaTrans;

            cublasSgemm(morse_lapack_const(transW), morse_lapack_const(MagmaNoTrans),
                        K, N1, M2,
                        zone,
                        (float*)V     /* K*M2  */, LDV,
                        (float*)A2    /* M2*N1 */, LDA2,
                        zone,
                        (float*)WORK  /* K*N1  */, LDWORK);

            if (WORKC == NULL) {
                /* W = op(T) * W */
                cublasStrmm( morse_lapack_const(MagmaLeft), morse_lapack_const(MagmaUpper),
                             morse_lapack_const(trans), morse_lapack_const(MagmaNonUnit),
                             K, N2,
                             zone,
                             (float*)T, LDT,
                             (float*)WORK, LDWORK);


                /* A1 = A1 - W = A1 - op(T) * W */
                for(j = 0; j < N1; j++) {
                    cublasSaxpy(K, mzone,
                                (float*)(WORK + LDWORK*j), 1,
                                (float*)(A1 + LDA1*j), 1);
                }

                /* A2 = A2 - op(V) * W  */
                cublasSgemm(morse_lapack_const(transA2), morse_lapack_const(MagmaNoTrans),
                            M2, N2, K,
                            mzone,
                            (float*)V     /* M2*K  */, LDV,
                            (float*)WORK  /* K*N2  */, LDWORK,
                            zone,
                            (float*)A2    /* m2*N2 */, LDA2);

            } else {
                /* Wc = V * op(T) */
                cublasSgemm( morse_lapack_const(transA2), morse_lapack_const(trans),
                             M2, K, K,
                             zone,  V,     LDV,
                                    T,     LDT,
                             szero, WORKC, LDWORKC );

                /* A1 = A1 - opt(T) * W */
                cublasSgemm( morse_lapack_const(trans), morse_lapack_const(MagmaNoTrans),
                             K, N1, K,
                             mzone, T,    LDT,
                                    WORK, LDWORK,
                             zone,  A1,   LDA1 );

                /* A2 = A2 - Wc * W */
                cublasSgemm( morse_lapack_const(MagmaNoTrans), morse_lapack_const(MagmaNoTrans),
                             M2, N2, K,
                             mzone, WORKC, LDWORKC,
                                    WORK,  LDWORK,
                             zone,  A2,    LDA2 );
            }
        }
        else {
            /*
             * Column or Rowwise / Forward / Right
             * -----------------------------------
             *
             * Form  H * A  or  H' * A  where A  = ( A1 A2 )
             *
             */

            /*
             * W = A1 + A2 * V':
             *      W = A1
             *      W = W + A2 * V'
             *
             */
            cudaMemcpy2DAsync( WORK, LDWORK * sizeof(float),
                               A1,   LDA1   * sizeof(float),
                               M1 * sizeof(float), K,
                               cudaMemcpyDeviceToDevice, stream );

            transW  = storev == MorseColumnwise ? MagmaNoTrans : MagmaTrans;
            transA2 = storev == MorseColumnwise ? MagmaTrans : MagmaNoTrans;

            cublasSgemm(morse_lapack_const(MagmaNoTrans), morse_lapack_const(transW),
                        M1, K, N2,
                        zone,
                        (float*)A2    /* M1*N2 */, LDA2,
                        (float*)V     /* N2*K  */, LDV,
                        zone,
                        (float*)WORK  /* M1*K  */, LDWORK);

            if (WORKC == NULL) {
                /* W = W * op(T) */
                cublasStrmm( morse_lapack_const(MagmaRight), morse_lapack_const(MagmaUpper),
                             morse_lapack_const(trans), morse_lapack_const(MagmaNonUnit),
                             M2, K,
                             zone,
                             (float*)T, LDT,
                             (float*)WORK, LDWORK);


                /* A1 = A1 - W = A1 - W * op(T) */
                for(j = 0; j < K; j++) {
                    cublasSaxpy(M1, mzone,
                                (float*)(WORK + LDWORK*j), 1,
                                (float*)(A1 + LDA1*j), 1);
                }

                /* A2 = A2 - W * op(V)  */
                cublasSgemm(morse_lapack_const(MagmaNoTrans), morse_lapack_const(transA2),
                            M2, N2, K,
                            mzone,
                            (float*)WORK  /* M2*K  */, LDWORK,
                            (float*)V     /* K*N2  */, LDV,
                            zone,
                            (float*)A2    /* M2*N2 */, LDA2);

            } else {
                /* A1 = A1 - W * opt(T) */
                cublasSgemm( morse_lapack_const(MagmaNoTrans), morse_lapack_const(trans),
                             M1, K, K,
                             mzone, WORK, LDWORK,
                                    T,    LDT,
                             zone,  A1,   LDA1 );

                /* Wc = op(T) * V */
                cublasSgemm( morse_lapack_const(trans), morse_lapack_const(transA2),
                             K, N2, K,
                             zone,  T,     LDT,
                                    V,     LDV,
                             szero, WORKC, LDWORKC );

                /* A2 = A2 - W * Wc */
                cublasSgemm( morse_lapack_const(MagmaNoTrans), morse_lapack_const(MagmaNoTrans),
                             M2, N2, K,
                             mzone, WORK,  LDWORK,
                                    WORKC, LDWORKC,
                             zone,  A2,    LDA2 );
            }
        }
    }
    else {
        fprintf(stderr, "Not implemented (Backward / Left or Right)");
        return MAGMA_ERR_NOT_SUPPORTED;
    }

    return MAGMA_SUCCESS;
}
#endif /* CHAMELEON_USE_CUBLAS_V2 */

magma_int_t
magma_stsmqr_gpu( magma_side_t side, magma_trans_t trans,
                  magma_int_t M1, magma_int_t N1,
                  magma_int_t M2, magma_int_t N2,
                  magma_int_t K, magma_int_t IB,
                  float *A1, magma_int_t LDA1,
                  float *A2, magma_int_t LDA2,
                  const float *V, magma_int_t LDV,
                  const float *T, magma_int_t LDT,
                        float *WORK,  magma_int_t LDWORK,
                        float *WORKC, magma_int_t LDWORKC,
                  CUstream stream)
{
    int i, i1, i3;
    int NQ, NW;
    int kb;
    int ic = 0;
    int jc = 0;
    int mi = M1;
    int ni = N1;

    /* Check input arguments */
    if ((side != MagmaLeft) && (side != MagmaRight)) {
        return -1;
    }

    /* NQ is the order of Q */
    if (side == MagmaLeft) {
        NQ = M2;
        NW = IB;
    }
    else {
        NQ = N2;
        NW = M1;
    }

    if ((trans != MagmaNoTrans) && (trans != MagmaTrans)) {
        return -2;
    }
    if (M1 < 0) {
        return -3;
    }
    if (N1 < 0) {
        return -4;
    }
    if ( (M2 < 0) ||
         ( (M2 != M1) && (side == MagmaRight) ) ){
        return -5;
    }
    if ( (N2 < 0) ||
         ( (N2 != N1) && (side == MagmaLeft) ) ){
        return -6;
    }
    if ((K < 0) ||
        ( (side == MagmaLeft)  && (K > M1) ) ||
        ( (side == MagmaRight) && (K > N1) ) ) {
        return -7;
    }
    if (IB < 0) {
        return -8;
    }
    if (LDA1 < max(1,M1)){
        return -10;
    }
    if (LDA2 < max(1,M2)){
        return -12;
    }
    if (LDV < max(1,NQ)){
        return -14;
    }
    if (LDT < max(1,IB)){
        return -16;
    }
    if (LDWORK < max(1,NW)){
        return -18;
    }

    /* Quick return */
    if ((M1 == 0) || (N1 == 0) || (M2 == 0) || (N2 == 0) || (K == 0) || (IB == 0))
        return MAGMA_SUCCESS;

    if (((side == MagmaLeft)  && (trans != MagmaNoTrans))
        || ((side == MagmaRight) && (trans == MagmaNoTrans))) {
        i1 = 0;
        i3 = IB;
    }
    else {
        i1 = ((K-1) / IB)*IB;
        i3 = -IB;
    }

    for(i = i1; (i > -1) && (i < K); i += i3) {
        kb = min(IB, K-i);

        if (side == MagmaLeft) {
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
        magma_sparfb_gpu( side, trans, MagmaForward, MagmaColumnwise,
                          mi, ni, M2, N2, kb, 0,
                          A1 + LDA1*jc+ic, LDA1,
                          A2, LDA2,
                          V + LDV*i, LDV,
                          T + LDT*i, LDT,
                          WORK, LDWORK, WORKC, LDWORKC, stream );
    }
    return MAGMA_SUCCESS;
}

static void cl_stsmqr_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum trans;
    int m1;
    int n1;
    int m2;
    int n2;
    int k;
    int ib;
    float *A1;
    int lda1;
    float *A2;
    int lda2;
    float *V;
    int ldv;
    float *T;
    int ldt;
    float *W, *WC;
    int ldwork;
    int ldworkc;
    CUstream stream;

    A1 = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    A2 = (float *)STARPU_MATRIX_GET_PTR(descr[1]);
    V  = (float *)STARPU_MATRIX_GET_PTR(descr[2]);
    T  = (float *)STARPU_MATRIX_GET_PTR(descr[3]);
    W  = (float *)STARPU_MATRIX_GET_PTR(descr[4]); /* 2*ib*nb */

    starpu_codelet_unpack_args(cl_arg, &side, &trans, &m1, &n1, &m2, &n2, &k, &ib,
                               &lda1, &lda2, &ldv, &ldt, &ldwork);

    WC = W + ib * (side == MorseLeft ? n1 : m1);
    ldworkc = (side == MorseLeft) ? m1 : ib;

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    magma_stsmqr_gpu( side, trans, m1, n1, m2, n2, k, ib,
                      A1, lda1, A2, lda2, V, ldv, T, ldt,
                      W, ldwork, WC, ldworkc, stream );

#ifndef STARPU_CUDA_ASYNC
    cudaStreamSynchronize( stream );
#endif
}

#endif

/*
 * Codelet definition
 */
#if defined(CHAMELEON_USE_MAGMA) || defined(CHAMELEON_SIMULATION)
CODELETS(stsmqr, 5, cl_stsmqr_cpu_func, cl_stsmqr_cuda_func, STARPU_CUDA_ASYNC)
#else
CODELETS_CPU(stsmqr, 5, cl_stsmqr_cpu_func)
#endif
