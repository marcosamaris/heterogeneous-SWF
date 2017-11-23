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
 * @file codelet_dgemm.c
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
 * @generated d Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void MORSE_TASK_dgemm(MORSE_option_t *options,
                      MORSE_enum transA, int transB,
                      int m, int n, int k, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                                               MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta,  MORSE_desc_t *C, int Cm, int Cn, int ldc)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dgemm;
    void (*callback)(void*) = options->profiling ? cl_dgemm_callback : NULL;
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
            STARPU_VALUE,    &alpha,             sizeof(double),
            STARPU_R,         RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &lda,               sizeof(int),
            STARPU_R,         RTBLKADDR(B, double, Bm, Bn),
            STARPU_VALUE,    &ldb,               sizeof(int),
            STARPU_VALUE,    &beta,              sizeof(double),
            STARPU_RW,        RTBLKADDR(C, double, Cm, Cn),
            STARPU_VALUE,    &ldc,               sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
#if defined(CHAMELEON_USE_MPI)
            STARPU_EXECUTE_ON_NODE, execution_rank,
#endif
            0);
    }
}



static void cl_dgemm_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum transA;
    MORSE_enum transB;
    int m;
    int n;
    int k;
    double alpha;
    double *A;
    int lda;
    double *B;
    int ldb;
    double beta;
    double *C;
    int ldc;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &transA, &transB, &m, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);
    cblas_dgemm(
        CblasColMajor,
        (CBLAS_TRANSPOSE)transA, (CBLAS_TRANSPOSE)transB,
        m, n, k,
        (alpha), A, lda,
        B, ldb,
        (beta), C, ldc);
}

#ifdef CHAMELEON_USE_CUDA
#if defined(CHAMELEON_USE_CUBLAS_V2)
static void cl_dgemm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum transA;
    MORSE_enum transB;
    int m;
    int n;
    int k;
    double alpha;
    const double *A;
    int lda;
    const double *B;
    int ldb;
    double beta;
    double *C;
    int ldc;
    CUstream stream;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasOperation_t cublasTransA;
    cublasOperation_t cublasTransB;

    A = (const double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (const double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
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
        fprintf(stderr, "Error in cl_dgemm_cuda_func: bad transA parameter %d\n", transA);
    }
    if (transB == MorseNoTrans){
        cublasTransB = CUBLAS_OP_N;
    }else if(transB == MorseTrans){
        cublasTransB = CUBLAS_OP_T;
    }else if(transB == MorseTrans){
        cublasTransB = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in cl_dgemm_cuda_func: bad transB parameter %d\n", transB);
    }

    stat = cublasDgemm(handle,
        cublasTransA, cublasTransB,
        m, n, k,
        (const double *) &alpha, A, lda,
        B, ldb,
        (const double *) &beta,  C, ldc);
    if (stat != CUBLAS_STATUS_SUCCESS){
        printf ("cublasDgemm failed");
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
static void cl_dgemm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum transA;
    MORSE_enum transB;
    int m;
    int n;
    int k;
    double alpha;
    double *A;
    int lda;
    double *B;
    int ldb;
    double beta;
    double *C;
    int ldc;
    CUstream stream;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &transA, &transB, &m, &n, &k, &alpha, &lda, &ldb, &beta, &ldc);

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    cublasDgemm(
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
CODELETS(dgemm, 3, cl_dgemm_cpu_func, cl_dgemm_cuda_func, STARPU_CUDA_ASYNC);
