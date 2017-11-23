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
 * @file codelet_dtrsm.c
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

void MORSE_TASK_dtrsm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dtrsm;
    void (*callback)(void*) = options->profiling ? cl_dtrsm_callback : NULL;
    int sizeA = m*m;
    int sizeB = m*n;
    int execution_rank = B->get_rankof( B, Bm, Bn );
    int rank_changed=0;

    // force execution on the rank owning the largest data (tile)
    int threshold;
    char* env = getenv("MORSE_COMM_FACTOR_THRESHOLD");
    if (env != NULL)
        threshold = (unsigned)atoi(env);
    else
        threshold = 10;
    if ( sizeA > threshold*sizeB ){
        execution_rank = A->get_rankof( A, Am, An );
        rank_changed=1;
    }

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ||
         rank_changed
       )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &side,               sizeof(MORSE_enum),
            STARPU_VALUE,    &uplo,               sizeof(MORSE_enum),
            STARPU_VALUE,    &transA,             sizeof(MORSE_enum),
            STARPU_VALUE,    &diag,               sizeof(MORSE_enum),
            STARPU_VALUE,    &m,                  sizeof(int),
            STARPU_VALUE,    &n,                  sizeof(int),
            STARPU_VALUE,    &alpha,              sizeof(double),
            STARPU_R,         RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &lda,                sizeof(int),
            STARPU_RW,        RTBLKADDR(B, double, Bm, Bn),
            STARPU_VALUE,    &ldb,                sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
#if defined(CHAMELEON_USE_MPI)
            STARPU_EXECUTE_ON_NODE, execution_rank,
#endif
            0);
    }
}


static void cl_dtrsm_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    MORSE_enum transA;
    MORSE_enum diag;
    int m;
    int n;
    double alpha;
    double *A;
    int lda;
    double *B;
    int ldb;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &transA, &diag, &m, &n, &alpha, &lda, &ldb);
    cblas_dtrsm(
        CblasColMajor,
        (CBLAS_SIDE)side, (CBLAS_UPLO)uplo,
        (CBLAS_TRANSPOSE)transA, (CBLAS_DIAG)diag,
        m, n,
        (alpha), A, lda,
        B, ldb);
}

#ifdef CHAMELEON_USE_CUDA
#if defined(CHAMELEON_USE_CUBLAS_V2)
static void cl_dtrsm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    MORSE_enum transA;
    MORSE_enum diag;
    int m;
    int n;
    double alpha;
    const double *A;
    int lda;
    double *B;
    int ldb;
    CUstream stream;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasSideMode_t cublasSide;
    cublasFillMode_t cublasUplo;
    cublasOperation_t cublasTransA;
    cublasDiagType_t cublasDiag;

    A = (const double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &transA, &diag, &m, &n, &alpha, &lda, &ldb);

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

    if (side == MorseLeft){
        cublasSide = CUBLAS_SIDE_LEFT;
    }else if (side == MorseRight){
        cublasSide = CUBLAS_SIDE_RIGHT;
    }else{
        fprintf(stderr, "Error in cl_dtrsm_cuda_func: bad side parameter %d\n", side);
    }
    if (uplo == MorseUpper){
        cublasUplo = CUBLAS_FILL_MODE_UPPER;
    }else if(uplo == MorseLower){
        cublasUplo = CUBLAS_FILL_MODE_LOWER;
    }else if(uplo == MorseUpperLower){
        cublasUplo = 0;
    }else{
        fprintf(stderr, "Error in cl_dtrsm_cuda_func: bad uplo parameter %d\n", uplo);
    }
    if (transA == MorseNoTrans){
        cublasTransA = CUBLAS_OP_N;
    }else if(transA == MorseTrans){
        cublasTransA = CUBLAS_OP_T;
    }else if(transA == MorseTrans){
        cublasTransA = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in cl_dtrsm_cuda_func: bad transA parameter %d\n", transA);
    }
    if (diag == MorseNonUnit){
        cublasDiag = CUBLAS_DIAG_NON_UNIT;
    }else if(diag == MorseUnit){
        cublasDiag = CUBLAS_DIAG_UNIT;
    }else{
        fprintf(stderr, "Error in cl_dtrsm_cuda_func: bad diag parameter %d\n", diag);
    }

    stat = cublasDtrsm( handle,
        cublasSide, cublasUplo, cublasTransA, cublasDiag,
        m, n,
        (const double *) &alpha, A, lda,
        B, ldb);
    if (stat != CUBLAS_STATUS_SUCCESS){
        printf ("cublasDtrsm failed");
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
static void cl_dtrsm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    MORSE_enum transA;
    MORSE_enum diag;
    int m;
    int n;
    double alpha;
    double *A;
    int lda;
    double *B;
    int ldb;
    CUstream stream;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &transA, &diag, &m, &n, &alpha, &lda, &ldb);

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    cublasDtrsm(
        morse_lapack_const(side), morse_lapack_const(uplo),
        morse_lapack_const(transA), morse_lapack_const(diag),
        m, n,
        alpha, A, lda,
        B, ldb);

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
CODELETS(dtrsm, 2, cl_dtrsm_cpu_func, cl_dtrsm_cuda_func, STARPU_CUDA_ASYNC)
