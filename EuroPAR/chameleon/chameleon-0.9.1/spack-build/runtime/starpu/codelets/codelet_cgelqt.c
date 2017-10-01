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
 * @file codelet_cgelqt.c
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
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated c Tue Sep 26 20:43:01 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_cgelqt - computes a LQ factorization of a complex M-by-N tile A: A = L * Q.
 *
 *  The tile Q is represented as a product of elementary reflectors
 *
 *    Q = H(k)' . . . H(2)' H(1)', where k = min(M,N).
 *
 *  Each H(i) has the form
 *
 *    H(i) = I - tau * v * v'
 *
 *  where tau is a complex scalar, and v is a complex vector with
 *  v(1:i-1) = 0 and v(i) = 1; conjg(v(i+1:n)) is stored on exit in
 *  A(i,i+1:n), and tau in TAU(i).
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the tile A.  M >= 0.
 *
 * @param[in] N
 *         The number of columns of the tile A.  N >= 0.
 *
 * @param[in] IB
 *         The inner-blocking size.  IB >= 0.
 *
 * @param[in,out] A
 *         On entry, the M-by-N tile A.
 *         On exit, the elements on and below the diagonal of the array
 *         contain the M-by-min(M,N) lower trapezoidal tile L (L is
 *         lower triangular if M <= N); the elements above the diagonal,
 *         with the array TAU, represent the unitary tile Q as a
 *         product of elementary reflectors (see Further Details).
 *
 * @param[in] LDA
 *         The leading dimension of the array A.  LDA >= max(1,M).
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

void MORSE_TASK_cgelqt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_cgelqt;
    void (*callback)(void*) = options->profiling ? cl_cgelqt_callback : NULL;
    MORSE_starpu_ws_t *h_work = (MORSE_starpu_ws_t*)(options->ws_host);

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( T, Tm, Tn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &m,                 sizeof(int),
            STARPU_VALUE,    &n,                 sizeof(int),
            STARPU_VALUE,    &ib,                sizeof(int),
            STARPU_RW,        RTBLKADDR(A, MORSE_Complex32_t, Am, An),
            STARPU_VALUE,    &lda,               sizeof(int),
            STARPU_W,         RTBLKADDR(T, MORSE_Complex32_t, Tm, Tn),
            STARPU_VALUE,    &ldt,               sizeof(int),
            /* max( nb * (ib+1), ib * (ib+nb) ) */
            STARPU_SCRATCH,   options->ws_worker,
            /* /\* ib*n + 3*ib*ib + max(m,n) *\/ */
            STARPU_VALUE,    &h_work,            sizeof(MORSE_starpu_ws_t *),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_cgelqt_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *h_work;
    int m;
    int n;
    int ib;
    MORSE_Complex32_t *A;
    int lda;
    MORSE_Complex32_t *T;
    int ldt;
    MORSE_Complex32_t *TAU, *WORK;

    A   = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[0]);
    T   = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[1]);
    TAU = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[2]); /* max(m,n) + ib*n */

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &lda, &ldt, &h_work);

    WORK = TAU + max( m, n );
    CORE_cgelqt(m, n, ib, A, lda, T, ldt, TAU, WORK);
}

#if defined(CHAMELEON_USE_MAGMA)
magma_int_t
magma_cgelqt_gpu( magma_int_t m, magma_int_t n, magma_int_t nb,
                  magmaFloatComplex *da, magma_int_t ldda,
                  magmaFloatComplex *v,  magma_int_t ldv,
                  magmaFloatComplex *dt, magma_int_t lddt,
                  magmaFloatComplex *t,  magma_int_t ldt,
                  magmaFloatComplex *dd,
                  magmaFloatComplex *d,  magma_int_t ldd,
                  magmaFloatComplex *tau,
                  magmaFloatComplex *hwork,
                  magmaFloatComplex *dwork)
{
#define da_ref(a_1,a_2) ( da+(a_2)*(ldda) + (a_1))
#define v_ref(a_1,a_2)  ( v+(a_2)*(ldv) + (a_1))
#define dt_ref(a_1,a_2) ( dt+(a_2)*(lddt) + (a_1))
#define t_ref(a_1,a_2)  ( t+(a_2)*(ldt) + (a_1))

    int i, k, ib, lddwork, old_i, old_ib, rows, cols;
    float _Complex one=1.;
    CUstream stream;

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    if (m < 0) {
        return -1;
    } else if (n < 0) {
        return -2;
    } else if (ldda < max(1,m)) {
        return -4;
    }

    k = min(m,n);
    if (k == 0) {
        hwork[0] = *((magmaFloatComplex*) &one);
        return MAGMA_SUCCESS;
    }

    lddwork= m;

    /* lower parts of little T must be zero: memset to 0 for simplicity */
    memset(t_ref(0,0), 0, nb*n*sizeof(magmaFloatComplex));
    cudaMemset(dt_ref(0,0), 0, nb*n*sizeof(magmaFloatComplex));

    /* copy first panel of A on the host */
    cublasGetMatrix(min(m, nb), n, sizeof(magmaFloatComplex),
                    da_ref(0, 0), ldda,
                    v, ldv);

    /* Use blocked code initially */
    for (i = 0; i < k; i += nb) {

        ib = min(k-i, nb);
        if (i+nb >= m) ib = min(m-i, nb);
        cols = n-i;

        if (i > 0){

            /* copy panel of A from device to host */
            cublasGetMatrix(ib, n, sizeof(magmaFloatComplex),
                            da_ref(i, 0), ldda,
                            v, ldv);

            /* Apply H' to A(i+2*ib:m, i:n) from the right */
            rows = m-old_i-2*old_ib;
            if (rows > 0){
                magma_clarfb_gpu( MagmaRight, MagmaNoTrans, MagmaForward, MagmaRowwise,
                                  rows, n-old_i, old_ib,
                                  da_ref(old_i, old_i), ldda, dt_ref(0,old_i), lddt,
                                  da_ref(old_i+2*old_ib, old_i), ldda,
                                  dwork, lddwork);
            }

            /* copy the lower diag tile into d_A */
            magma_cgemerge_gpu(MagmaRight, MagmaUnit, old_ib, old_ib,
                               dd, ldd, da_ref(old_i, old_i), ldda, stream);

        }

        /* Form the triangular factor of the block reflector on the host
         H = H'(i+ib-1) . . . H(i+1) H(i) */
        CORE_cgelqt(ib, cols, ib,
                    (float _Complex*) v_ref(0,i), ldv,
                    (float _Complex*) t_ref(0,0), ldt,
                    (float _Complex*) tau+i,
                    (float _Complex*) hwork);

        if ( i + ib < m ){
            /* put 0s in the lower triangular part of a panel (and 1s on the
             diagonal); copy the lower triangular in d */
            CORE_cgesplit(MorseRight, MorseUnit, ib, min(cols,ib),
                          (float _Complex*) v_ref(0,i), ldv,
                          (float _Complex*) d, ldd);

            /* copy from host to device a tile diag */
            cublasSetMatrix( ib, min(cols,ib), sizeof(magmaFloatComplex),
                             d, ldd, dd, ldd );
        }

        /* Send the triangular factor T to the GPU */
        cublasSetMatrix( ib, ib, sizeof(magmaFloatComplex),
                         t_ref(0,0), ldt, dt_ref(0,i), lddt );

        /* A panel (with zeros in lower tri of its diag) is ready to be used
         in input of clarfb_gpu: we send the panel to the gpu */
        cublasSetMatrix( ib, cols, sizeof(magmaFloatComplex),
                         v_ref(0,i), ldv, da_ref(i,i), ldda );

        if (i + ib < m) {

            if (i+2*ib < m){
                rows = ib;
            }
            else{
                rows = m-i-ib;
            }
            /* Apply H' to A(i+ib:i+2*ib, i:n) from the right */
            magma_clarfb_gpu( MagmaRight, MagmaNoTrans, MagmaForward, MagmaRowwise,
                              rows, cols, ib, da_ref(i,i), ldda, dt_ref(0,i),
                              lddt, da_ref(i+ib,i), ldda, dwork, lddwork);
            old_i = i;
            old_ib = ib;
            if (i+nb >= k){
                /* Apply H' to A(i+2*ib:m, i:n) from the right */
                rows = m-old_i-2*old_ib;
                if (rows > 0){
                    magma_clarfb_gpu( MagmaRight, MagmaNoTrans, MagmaForward, MagmaRowwise,
                                      rows, cols, old_ib,
                                      da_ref(old_i, old_i), ldda, dt_ref(0,old_i), lddt,
                                      da_ref(old_i+2*old_ib, old_i), ldda,
                                      dwork, lddwork);
                }
                /* copy the upper diag tile into d_A */
                magma_cgemerge_gpu(MagmaRight, MagmaUnit, old_ib, old_ib,
                                   dd, ldd, da_ref(old_i, old_i), ldda, stream);
            }
        }

    }

#undef da_ref
#undef v_ref
#undef dt_ref
#undef t_ref

    return MAGMA_SUCCESS;
} /* magma_cgelqt_gpu */

static void cl_cgelqt_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *h_work;
    int m;
    int n;
    int ib;
    cuFloatComplex *h_A, *h_T, *h_D, *h_W, *h_TAU;
    cuFloatComplex *d_A, *d_T, *d_D, *d_W;
    int lda, ldt;

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &lda, &ldt, &h_work);

    /* Gather pointer to data on device */
    d_A = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[0]);
    d_T = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[1]);
    d_W = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[2]); /* m*ib + ib*ib*/
    d_D = d_W + m*ib;

    /* scratch data on host */
    /* ib*n + ib*ib + max(m,n) + ib*ib + ib*ib */
    h_A = (cuFloatComplex*)RUNTIME_starpu_ws_getlocal(h_work);

    /* Gather pointer to scratch data on host */
    h_T   = h_A   + ib*n;
    h_TAU = h_T   + ib*ib;
    h_W   = h_TAU + max(m,n);
    h_D   = h_W   + ib*ib;

    magma_cgelqt_gpu( m, n, ib,
                      d_A, lda, h_A, ib,
                      d_T, ldt, h_T, ib,
                      d_D, h_D, ib, h_TAU,
                      h_W, d_W);

    cudaThreadSynchronize();
}

#endif

/*
 * Codelet definition
 */
#if defined(CHAMELEON_USE_MAGMA) || defined(CHAMELEON_SIMULATION)
CODELETS(cgelqt, 3, cl_cgelqt_cpu_func, cl_cgelqt_cuda_func, 0)
#else
CODELETS_CPU(cgelqt, 3, cl_cgelqt_cpu_func)
#endif
