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
 * @file codelet_dgeqrt.c
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
 * @generated d Tue Sep 26 20:43:01 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_dgeqrt computes a QR factorization of a real M-by-N tile A:
 *  A = Q * R.
 *
 *  The tile Q is represented as a product of elementary reflectors
 *
 *    Q = H(1) H(2) . . . H(k), where k = min(M,N).
 *
 *  Each H(i) has the form
 *
 *    H(i) = I - tau * v * v'
 *
 *  where tau is a real scalar, and v is a real vector with
 *  v(1:i-1) = 0 and v(i) = 1; v(i+1:m) is stored on exit in A(i+1:m,i),
 *  and tau in TAU(i).
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
 *         On exit, the elements on and above the diagonal of the array
 *         contain the min(M,N)-by-N upper trapezoidal tile R (R is
 *         upper triangular if M >= N); the elements below the diagonal,
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

void MORSE_TASK_dgeqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dgeqrt;
    void (*callback)(void*) = options->profiling ? cl_dgeqrt_callback : NULL;
    MORSE_starpu_ws_t *h_work = (MORSE_starpu_ws_t*)(options->ws_host);

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( T, Tm, Tn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &m,                 sizeof(int),
            STARPU_VALUE,    &n,                 sizeof(int),
            STARPU_VALUE,    &ib,                sizeof(int),
            STARPU_RW,        RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &lda,               sizeof(int),
            STARPU_W,         RTBLKADDR(T, double, Tm, Tn),
            STARPU_VALUE,    &ldt,               sizeof(int),
            /* max( nb * (ib+1), ib * (ib+nb) ) */
            STARPU_SCRATCH,   options->ws_worker,
            /* ib * (m+3*ib) + max(m,n) */
            STARPU_VALUE,    &h_work,            sizeof(MORSE_starpu_ws_t *),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_dgeqrt_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *h_work;
    int m;
    int n;
    int ib;
    double *A;
    int lda;
    double *T;
    int ldt;
    double *TAU, *WORK;

    A   = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    T   = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    TAU = (double *)STARPU_MATRIX_GET_PTR(descr[2]); /* max(m,n) + n * ib */

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &lda, &ldt, &h_work);

    WORK = TAU + max( m, n );
    CORE_dgeqrt(m, n, ib, A, lda, T, ldt, TAU, WORK);
}


#if defined(CHAMELEON_USE_MAGMA)

#if defined(CHAMELEON_USE_CUBLAS_V2)
magma_int_t
magma_dgemerge_gpu(magma_side_t side, magma_diag_t diag,
                   magma_int_t M, magma_int_t N,
                   double *A, magma_int_t LDA,
                   double *B, magma_int_t LDB,
                   CUstream stream)
{
    int i, j;
    double *cola, *colb;
    cublasHandle_t handle;
    cublasStatus_t stat;

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

    if (M < 0) {
        return -1;
    }
    if (N < 0) {
        return -2;
    }
    if ( (LDA < max(1,M)) && (M > 0) ) {
        return -5;
    }
    if ( (LDB < max(1,M)) && (M > 0) ) {
        return -7;
    }

    if (side == MagmaLeft){
        for(i=0; i<N; i++){
            cola = A + i*LDA;
            colb = B + i*LDB;
//            cublasDcopy(handle, i+1, cola, 1, colb, 1);
            cudaMemcpyAsync(colb , cola,
                            (i+1)*sizeof(double),
                            cudaMemcpyDeviceToDevice, stream);
        }
    }else{
        for(i=0; i<N; i++){
            cola = A + i*LDA;
            colb = B + i*LDB;
//            cublasDcopy(handle, M-i, cola + i, 1, colb + i, 1);
            cudaMemcpyAsync(colb+i , cola+i,
                            (M-i)*sizeof(double),
                            cudaMemcpyDeviceToDevice, stream);
        }
    }

    cublasDestroy(handle);

    return MAGMA_SUCCESS;
}
#else /* CHAMELEON_USE_CUBLAS_V2 */
magma_int_t
magma_dgemerge_gpu(magma_side_t side, magma_diag_t diag,
                   magma_int_t M, magma_int_t N,
                   double *A, magma_int_t LDA,
                   double *B, magma_int_t LDB,
                   CUstream stream)
{
    int i, j;
    double *cola, *colb;

    if (M < 0) {
        return -1;
    }
    if (N < 0) {
        return -2;
    }
    if ( (LDA < max(1,M)) && (M > 0) ) {
        return -5;
    }
    if ( (LDB < max(1,M)) && (M > 0) ) {
        return -7;
    }

    if (side == MagmaLeft){
        for(i=0; i<N; i++){
            cola = A + i*LDA;
            colb = B + i*LDB;
//            cublasDcopy(i+1, cola, 1, colb, 1);
            cudaMemcpyAsync(colb , cola,
                            (i+1)*sizeof(double),
                            cudaMemcpyDeviceToDevice, stream);
        }
    }else{
        for(i=0; i<N; i++){
            cola = A + i*LDA;
            colb = B + i*LDB;
//            cublasDcopy(M-i, cola + i, 1, colb + i, 1);
            cudaMemcpyAsync(colb+i , cola+i,
                            (M-i)*sizeof(double),
                            cudaMemcpyDeviceToDevice, stream);
        }
    }

    return MAGMA_SUCCESS;
}
#endif /* CHAMELEON_USE_CUBLAS_V2 */

magma_int_t
magma_dgeqrt_gpu( magma_int_t m, magma_int_t n, magma_int_t nb,
                  double *da, magma_int_t ldda,
                  double *v,  magma_int_t ldv,
                  double *dt, magma_int_t lddt,
                  double *t,  magma_int_t ldt,
                  double *dd,
                  double *d,  magma_int_t ldd,
                  double *tau,
                  double *hwork,
                  double *dwork)
{
#define da_ref(a_1,a_2) ( da+(a_2)*(ldda) + (a_1))
#define v_ref(a_1,a_2)  ( v+(a_2)*(ldv) + (a_1))
#define dt_ref(a_1,a_2) ( dt+(a_2)*(lddt) + (a_1))
#define t_ref(a_1,a_2)  ( t+(a_2)*(ldt) + (a_1))

    int i, k, ib, lddwork, old_i, old_ib, rows, cols;
    double one=1.;
    CUstream stream;

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );
//    int lwkopt = n * nb;
//    hwork[0] = *((double*) &lwkopt);

    if (m < 0) {
        return -1;
    } else if (n < 0) {
        return -2;
    } else if (ldda < max(1,m)) {
        return -4;
    }

    k = min(m,n);
    if (k == 0) {
        hwork[0] = *((double*) &one);
        return MAGMA_SUCCESS;
    }

    lddwork= k;

    /* lower parts of little T must be zero: memset to 0 for simplicity */
    memset(t_ref(0,0), 0, nb*nb*sizeof(double));
    cudaMemsetAsync(dt_ref(0,0), 0, nb*n*sizeof(double), stream);

    /* copy first panel of A on the host */
//	cublasGetMatrix(m, min(nb,n), sizeof(double),
//                    da_ref(0, 0), ldda,
//                    v, ldv);
    cudaMemcpy( v, da_ref(0,0),
                m*min(nb,n)*sizeof(double),
                cudaMemcpyDeviceToHost);

    /* Use blocked code initially */
    for (i = 0; i < k; i += nb) {

        ib = min(k-i, nb);
        if (i+nb>=n) ib = min(n-i, nb);
        rows = m-i;

        if (i>0){

            /* copy panel of A from device to host */
//        	cublasGetMatrix(m, ib, sizeof(double),
//                            da_ref(0, i), ldda,
//                            v, ldv);
            /* copy panel of A from device to host */
            cudaMemcpy( v, da_ref(0,i),
                        m*ib*sizeof(double),
                        cudaMemcpyDeviceToHost);

            /* Apply H' to A(i:m,i+2*ib:n) from the left */
            cols = n-old_i-2*old_ib;
            if (cols > 0){
                magma_dlarfb_gpu( MagmaLeft, MagmaTrans, MagmaForward, MagmaColumnwise,
                                  m-old_i, cols, old_ib,
                                  da_ref(old_i, old_i), ldda, dt_ref(0,old_i), lddt,
                                  da_ref(old_i, old_i+2*old_ib), ldda,
                                  dwork, cols);
            }

            /* copy the upper diag tile into d_A */
            magma_dgemerge_gpu(MagmaLeft, MagmaUnit, old_ib, old_ib,
                               dd, ldd, da_ref(old_i, old_i), ldda, stream);

        }

        /* Form the triangular factor of the block reflector on the host
         H = H(i) H(i+1) . . . H(i+ib-1) */
        CORE_dgeqrt(rows, ib, ib,
                    (double*) v_ref(i,0), ldv,
                    (double*) t_ref(0,0), ldt,
                    (double*) tau+i,
                    (double*) hwork);

        if ( i + ib < n ){
            /* put 0s in the upper triangular part of a panel (and 1s on the
             diagonal); copy the upper triangular in d */
            CORE_dgesplit(MorseLeft, MorseUnit, min(rows,ib), ib,
                          (double*) v_ref(i,0), ldv,
                          (double*) d, ldd);

            /* copy from host to device a tile diag */
            cublasSetMatrix( min(rows,ib), ib, sizeof(double),
                             d, ldd, dd, ldd );
        }

        /* Send the triangular factor T to the GPU */
        cublasSetMatrix( ib, ib, sizeof(double),
                         t_ref(0,0), ldt, dt_ref(0,i), lddt );

        /* A panel (with zeros in upper tri of its diag) is ready to be used
         in input of dlarfb_gpu: we send the panel to the gpu */
        cublasSetMatrix( rows, ib, sizeof(double),
                         v_ref(i,0), ldv, da_ref(i,i), ldda );

        if (i + ib < n) {

            if (i+2*ib < n){
                cols = ib;
            }
            else{
                cols = n-i-ib;
            }
            /* Apply H' to A(i:m,i+ib:i+2*ib) from the left */
            magma_dlarfb_gpu( MagmaLeft, MagmaTrans, MagmaForward, MagmaColumnwise,
                              rows, cols, ib, da_ref(i,i), ldda, dt_ref(0,i),
                              lddt, da_ref(i,i+ib), ldda, dwork, cols);
            old_i = i;
            old_ib = ib;
            if (i+nb>=k){
                /* Apply H' to A(i:m,i+2*ib:n) from the left */
                cols = n-old_i-2*old_ib;
                if (cols > 0){
                    magma_dlarfb_gpu( MagmaLeft, MagmaTrans, MagmaForward, MagmaColumnwise,
                                      rows, cols, old_ib,
                                      da_ref(old_i, old_i), ldda, dt_ref(0,old_i), lddt,
                                      da_ref(old_i, old_i+2*old_ib), ldda,
                                      dwork, cols);
                }
                /* copy the upper diag tile into d_A */
                magma_dgemerge_gpu(MagmaLeft, MagmaUnit, old_ib, old_ib,
                                   dd, ldd, da_ref(old_i, old_i), ldda, stream);
            }
        }

    }

#undef da_ref
#undef v_ref
#undef dt_ref
#undef t_ref

    return MAGMA_SUCCESS;
} /* magma_dgeqrt_gpu */

static void cl_dgeqrt_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *h_work;
    int m;
    int n;
    int ib;
    double *h_A, *h_T, *h_D, *h_W, *h_TAU;
    double *d_A, *d_T, *d_D, *d_W;
    int lda, ldt;

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &lda, &ldt, &h_work);

    /* Gather pointer to data on device */
    d_A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    d_T = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    d_W = (double *)STARPU_MATRIX_GET_PTR(descr[2]); /* ib*n + ib * ib*/
    d_D = d_W + ib*n;

    /* scratch data on host */
    /* m*ib + ib*ib + max(m,n) + ib*ib + ib*ib */
    h_A = (double*)RUNTIME_starpu_ws_getlocal(h_work);

    /* Gather pointer to scratch data on host */
    h_T   = h_A   + m*ib;
    h_TAU = h_T   + ib*ib;
    h_W   = h_TAU + max(m,n);
    h_D   = h_W   + ib*ib;

    magma_dgeqrt_gpu( m, n, ib,
                      d_A, lda, h_A, m,
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
CODELETS(dgeqrt, 3, cl_dgeqrt_cpu_func, cl_dgeqrt_cuda_func, 0)
#else
CODELETS_CPU(dgeqrt, 3, cl_dgeqrt_cpu_func)
#endif
