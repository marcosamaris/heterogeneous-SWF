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
 * @file codelet_sgemm.c
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
 * @generated s Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_s.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void MORSE_TASK_sgemm(MORSE_option_t *options,
                      MORSE_enum transA, int transB,
                      int m, int n, int k, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                                               MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      float beta,  MORSE_desc_t *C, int Cm, int Cn, int ldc)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_sgemm;
    void (*callback)(void*) = options->profiling ? cl_sgemm_callback : NULL;
    int sizeA = m*k;
    int sizeB = k*n;
    int sizeC = m*n;
    int execution_rank = C->get_rankof( C, Cm, Cn );
    int rank_changed=0;

    // force execution on the rank owning the largest data (tile)
    int threshold;
    char* env = getenv("MORSE_COMM_FACTOR_THRESHOLD");
    if (env != NULL)
        threshold = (unsigned)atoi(env);
    else
        threshold = 10;
    if ( sizeA > threshold*sizeC ){
        execution_rank = A->get_rankof( A, Am, An );
        rank_changed = 1;
    }else if( sizeB > threshold*sizeC ){
        execution_rank = B->get_rankof( B, Bm, Bn );
        rank_changed = 1;
    }

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ||
         morse_desc_islocal( C, Cm, Cn ) ||
         rank_changed
       )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &transA,            sizeof(MORSE_enum),
            STARPU_VALUE,    &transB,            sizeof(MORSE_enum),
            STARPU_VALUE,    &m,                 sizeof(int),
            STARPU_VALUE,    &n,                 sizeof(int),
            STARPU_VALUE,    &k,                 sizeof(int),
            STARPU_VALUE,    &alpha,             sizeof(float),
            STARPU_R,         RTBLKADDR(A, float, Am, An),
            STARPU_VALUE,    &lda,               sizeof(int),
            STARPU_R,         RTBLKADDR(B, float, Bm, Bn),
            STARPU_VALUE,    &ldb,               sizeof(int),
            STARPU_VALUE,    &beta,              sizeof(float),
            STARPU_RW,        RTBLKADDR(C, float, Cm, Cn),
            STARPU_VALUE,    &ldc,               sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
#if defined(CHAMELEON_USE_MPI)
            STARPU_EXECUTE_ON_NODE, execution_rank,
#endif
            0);
    }
}



static void cl_sgemm_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum transA;
    MORSE_enum transB;
    int m;
    int n;
    int k;
    float alpha;
    float *A;
    int lda;
    float *B;
    int ldb;
    float beta;
    float *C;
    int ldc;

    A = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (float *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (float *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &transA, &transB, &m, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);
    cblas_sgemm(
        CblasColMajor,
        (CBLAS_TRANSPOSE)transA, (CBLAS_TRANSPOSE)transB,
        m, n, k,
        (alpha), A, lda,
        B, ldb,
        (beta), C, ldc);
}

#ifdef CHAMELEON_USE_CUDA
#if defined(CHAMELEON_USE_CUBLAS_V2)
static void cl_sgemm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum transA;
    MORSE_enum transB;
    int m;
    int n;
    int k;
    float alpha;
    const float *A;
    int lda;
    const float *B;
    int ldb;
    float beta;
    float *C;
    int ldc;
    CUstream stream;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasOperation_t cublasTransA;
    cublasOperation_t cublasTransB;

    A = (const float *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (const float *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (float *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &transA, &transB, &m, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);

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

    if (transA == MorseNoTrans){
        cublasTransA = CUBLAS_OP_N;
    }else if(transA == MorseTrans){
        cublasTransA = CUBLAS_OP_T;
    }else if(transA == MorseTrans){
        cublasTransA = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in cl_sgemm_cuda_func: bad transA parameter %d\n", transA);
    }
    if (transB == MorseNoTrans){
        cublasTransB = CUBLAS_OP_N;
    }else if(transB == MorseTrans){
        cublasTransB = CUBLAS_OP_T;
    }else if(transB == MorseTrans){
        cublasTransB = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in cl_sgemm_cuda_func: bad transB parameter %d\n", transB);
    }

    stat = cublasSgemm(handle,
        cublasTransA, cublasTransB,
        m, n, k,
        (const float *) &alpha, A, lda,
        B, ldb,
        (const float *) &beta,  C, ldc);
    if (stat != CUBLAS_STATUS_SUCCESS){
        printf ("cublasSgemm failed");
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
static void cl_sgemm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum transA;
    MORSE_enum transB;
    int m;
    int n;
    int k;
    float alpha;
    float *A;
    int lda;
    float *B;
    int ldb;
    float beta;
    float *C;
    int ldc;
    CUstream stream;

    A = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (float *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (float *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &transA, &transB, &m, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    cublasSgemm(
        morse_lapack_const(transA), morse_lapack_const(transB),
        m, n, k,
        alpha, A, lda,
               B, ldb,
        beta,  C, ldc);

    assert( CUBLAS_STATUS_SUCCESS == cublasGetError() );

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
CODELETS(sgemm, 3, cl_sgemm_cpu_func, cl_sgemm_cuda_func, STARPU_CUDA_ASYNC);
