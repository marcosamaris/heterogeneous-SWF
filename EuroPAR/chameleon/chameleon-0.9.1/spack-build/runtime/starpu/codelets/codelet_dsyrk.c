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
 * @file codelet_dsyrk.c
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
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void MORSE_TASK_dsyrk(MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dsyrk;
    void (*callback)(void*) = options->profiling ? cl_dsyrk_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( C, Cm, Cn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,      &uplo,                sizeof(MORSE_enum),
            STARPU_VALUE,     &trans,                sizeof(MORSE_enum),
            STARPU_VALUE,         &n,                        sizeof(int),
            STARPU_VALUE,         &k,                        sizeof(int),
            STARPU_VALUE,     &alpha,         sizeof(double),
            STARPU_R,                 RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,       &lda,                        sizeof(int),
            STARPU_VALUE,      &beta,         sizeof(double),
            STARPU_RW,                 RTBLKADDR(C, double, Cm, Cn),
            STARPU_VALUE,       &ldc,                        sizeof(int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback,
            0);
    }
}


static void cl_dsyrk_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum trans;
    int n;
    int k;
    double alpha;
    double *A;
    int lda;
    double beta;
    double *C;
    int ldc;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &trans, &n, &k, &alpha, &lda, &beta, &ldc);
    cblas_dsyrk(
        CblasColMajor,
        (CBLAS_UPLO)uplo, (CBLAS_TRANSPOSE)trans,
        n, k,
        (alpha), A, lda,
        (beta), C, ldc);
}

#ifdef CHAMELEON_USE_CUDA
#if defined(CHAMELEON_USE_CUBLAS_V2)
static void cl_dsyrk_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum trans;
    int n;
    int k;
    double alpha;
    const double *A;
    int lda;
    double beta;
    double *C;
    int ldc;
    CUstream stream;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasFillMode_t cublasUplo;
    cublasOperation_t cublasTrans;

    A = (const double *)STARPU_MATRIX_GET_PTR(descr[0]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &trans, &n, &k, &alpha, &lda, &beta, &ldc);

    stat = cublasCreate(&handle);
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("CUBLAS initialization failed\n");
        assert( stat == CUBLAS_STATUS_SUCCESS );
    }

    stream = starpu_cuda_get_local_stream();
    stat = cublasSetStream(handle, stream);
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("cublasSetStream failed\n");
        assert( stat == CUBLAS_STATUS_SUCCESS );
    }

    if (uplo == MorseUpper){
        cublasUplo = CUBLAS_FILL_MODE_UPPER;
    }else if(uplo == MorseLower){
        cublasUplo = CUBLAS_FILL_MODE_LOWER;
    }else if(uplo == MorseUpperLower){
        cublasUplo = 0;
    }else{
        fprintf(stderr, "Error in cl_dsyrk_cuda_func: bad uplo parameter %d\n", uplo);
    }
    if (trans == MorseNoTrans){
        cublasTrans = CUBLAS_OP_N;
    }else if(trans == MorseTrans){
        cublasTrans = CUBLAS_OP_T;
    }else if(trans == MorseTrans){
        cublasTrans = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in cl_dsyrk_cuda_func: bad trans parameter %d\n", trans);
    }

    stat = cublasDsyrk(handle,
        cublasUplo, cublasTrans,
        n, k,
        (const double *) &alpha, A, lda,
        (const double *) &beta, C, ldc);
    if (stat != CUBLAS_STATUS_SUCCESS){
        printf ("cublasDsyrk failed");
        cublasDestroy(handle);
        assert( stat == CUBLAS_STATUS_SUCCESS );
    }

    cublasDestroy(handle);

#ifndef STARPU_CUDA_ASYNC
    cudaStreamSynchronize( stream );
#endif

    return;
}
#else /* CHAMELEON_USE_CUBLAS_V2 */
static void cl_dsyrk_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum trans;
    int n;
    int k;
    double alpha;
    double *A;
    int lda;
    double beta;
    double *C;
    int ldc;
    CUstream stream;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &trans, &n, &k, &alpha, &lda, &beta, &ldc);

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    cublasDsyrk(
        morse_lapack_const(uplo), morse_lapack_const(trans),
        n, k,
        alpha, A, lda,
        beta, C, ldc);

#ifndef STARPU_CUDA_ASYNC
    cudaStreamSynchronize( stream );
#endif

    return;
}
#endif /* CHAMELEON_USE_CUBLAS_V2 */
#endif /* CHAMELEON_USE_CUDA */

/*
 * Codelet definition
 */
CODELETS(dsyrk, 2, cl_dsyrk_cpu_func, cl_dsyrk_cuda_func, STARPU_CUDA_ASYNC)
