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
 * @file codelet_csyr2k.c
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
 * @generated c Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void MORSE_TASK_csyr2k(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       MORSE_Complex32_t alpha, MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb,
                       MORSE_Complex32_t beta, MORSE_desc_t *C, int Cm, int Cn, int ldc)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_csyr2k;
    void (*callback)(void*) = options->profiling ? cl_csyr2k_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ||
         morse_desc_islocal( C, Cm, Cn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,      &uplo,                sizeof(MORSE_enum),
            STARPU_VALUE,     &trans,                sizeof(MORSE_enum),
            STARPU_VALUE,         &n,                        sizeof(int),
            STARPU_VALUE,         &k,                        sizeof(int),
            STARPU_VALUE,     &alpha,         sizeof(MORSE_Complex32_t),
            STARPU_R,                 RTBLKADDR(A, MORSE_Complex32_t, Am, An),
            STARPU_VALUE,       &lda,                        sizeof(int),
            STARPU_R,                 RTBLKADDR(B, MORSE_Complex32_t, Bm, Bn),
            STARPU_VALUE,       &ldb,                        sizeof(int),
            STARPU_VALUE,      &beta,         sizeof(MORSE_Complex32_t),
            STARPU_RW,                 RTBLKADDR(C, MORSE_Complex32_t, Cm, Cn),
            STARPU_VALUE,       &ldc,                        sizeof(int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback,
            0);
    }
}


static void cl_csyr2k_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum trans;
    int n;
    int k;
    MORSE_Complex32_t alpha;
    MORSE_Complex32_t *A;
    int lda;
    MORSE_Complex32_t *B;
    int ldb;
    MORSE_Complex32_t beta;
    MORSE_Complex32_t *C;
    int ldc;

    A = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &trans, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);
    cblas_csyr2k(CblasColMajor, (CBLAS_UPLO)uplo, (CBLAS_TRANSPOSE)trans,
                 n, k, CBLAS_SADDR(alpha), A, lda, B, ldb, CBLAS_SADDR(beta), C, ldc);
}

#ifdef CHAMELEON_USE_CUDA
#if defined(CHAMELEON_USE_CUBLAS_V2)
static void cl_csyr2k_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum trans;
    int n;
    int k;
    cuFloatComplex alpha;
    const cuFloatComplex *A;
    int lda;
    const cuFloatComplex *B;
    int ldb;
    cuFloatComplex beta;
    cuFloatComplex *C;
    int ldc;
    CUstream stream;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasFillMode_t cublasUplo;
    cublasOperation_t cublasTrans;

    A = (const cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (const cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &trans, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);

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
        fprintf(stderr, "Error in cl_csyr2k_cuda_func: bad uplo parameter %d\n", uplo);
    }
    if (trans == MorseNoTrans){
        cublasTrans = CUBLAS_OP_N;
    }else if(trans == MorseTrans){
        cublasTrans = CUBLAS_OP_T;
    }else if(trans == MorseConjTrans){
        cublasTrans = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in cl_csyr2k_cuda_func: bad trans parameter %d\n", trans);
    }

    stat = cublasCsyr2k( handle, cublasUplo, cublasTrans,
        n, k, (const cuFloatComplex *) &alpha, A, lda, B, ldb,
        (const cuFloatComplex *) &beta, C, ldc);
    if (stat != CUBLAS_STATUS_SUCCESS){
        printf ("cublasCsyr2k failed");
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
static void cl_csyr2k_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum trans;
    int n;
    int k;
    cuFloatComplex alpha;
    cuFloatComplex *A;
    int lda;
    cuFloatComplex *B;
    int ldb;
    cuFloatComplex beta;
    cuFloatComplex *C;
    int ldc;
    CUstream stream;

    A = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &trans, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    cublasCsyr2k( morse_lapack_const(uplo), morse_lapack_const(trans),
                 n, k, alpha, A, lda, B, ldb, beta, C, ldc);

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
CODELETS(csyr2k, 3, cl_csyr2k_cpu_func, cl_csyr2k_cuda_func, STARPU_CUDA_ASYNC)
