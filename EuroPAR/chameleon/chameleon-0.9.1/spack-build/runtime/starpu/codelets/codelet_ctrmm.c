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
 * @file codelet_ctrmm.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Julien Langou
 * @author Henricus Bouwmeester
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated c Tue Sep 26 20:43:01 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void MORSE_TASK_ctrmm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      MORSE_Complex32_t alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_ctrmm;
    void (*callback)(void*) = options->profiling ? cl_ctrmm_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,      &side,                sizeof(MORSE_enum),
            STARPU_VALUE,      &uplo,                sizeof(MORSE_enum),
            STARPU_VALUE,    &transA,                sizeof(MORSE_enum),
            STARPU_VALUE,      &diag,                sizeof(MORSE_enum),
            STARPU_VALUE,         &m,                        sizeof(int),
            STARPU_VALUE,         &n,                        sizeof(int),
            STARPU_VALUE,     &alpha,         sizeof(MORSE_Complex32_t),
            STARPU_R,                 RTBLKADDR(A, MORSE_Complex32_t, Am, An),
            STARPU_VALUE,       &lda,                        sizeof(int),
            STARPU_RW,                 RTBLKADDR(B, MORSE_Complex32_t, Bm, Bn),
            STARPU_VALUE,       &ldb,                        sizeof(int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback,
            0);
    }
}


static void cl_ctrmm_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    MORSE_enum transA;
    MORSE_enum diag;
    int M;
    int N;
    MORSE_Complex32_t alpha;
    MORSE_Complex32_t *A;
    int LDA;
    MORSE_Complex32_t *B;
    int LDB;

    A = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &transA, &diag, &M, &N, &alpha, &LDA, &LDB);
    cblas_ctrmm(
        CblasColMajor,
        (CBLAS_SIDE)side, (CBLAS_UPLO)uplo,
        (CBLAS_TRANSPOSE)transA, (CBLAS_DIAG)diag,
        M, N,
        CBLAS_SADDR(alpha), A, LDA,
        B, LDB);
}

#ifdef CHAMELEON_USE_CUDA
#if defined(CHAMELEON_USE_CUBLAS_V2)
static void cl_ctrmm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    MORSE_enum transA;
    MORSE_enum diag;
    int M;
    int N;
    cuFloatComplex alpha;
    const cuFloatComplex *A;
    int LDA;
    cuFloatComplex *B;
    int LDB;
    CUstream stream;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasSideMode_t cublasSide;
    cublasFillMode_t cublasUplo;
    cublasOperation_t cublasTransA;
    cublasDiagType_t cublasDiag;

    A = (const cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &transA, &diag, &M, &N, &alpha, &LDA, &LDB);

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
        fprintf(stderr, "Error in cl_ctrmm_cuda_func: bad side parameter %d\n", side);
    }
    if (uplo == MorseUpper){
        cublasUplo = CUBLAS_FILL_MODE_UPPER;
    }else if(uplo == MorseLower){
        cublasUplo = CUBLAS_FILL_MODE_LOWER;
    }else if(uplo == MorseUpperLower){
        cublasUplo = 0;
    }else{
        fprintf(stderr, "Error in cl_ctrmm_cuda_func: bad uplo parameter %d\n", uplo);
    }
    if (transA == MorseNoTrans){
        cublasTransA = CUBLAS_OP_N;
    }else if(transA == MorseTrans){
        cublasTransA = CUBLAS_OP_T;
    }else if(transA == MorseConjTrans){
        cublasTransA = CUBLAS_OP_C;
    }else{
        fprintf(stderr, "Error in cl_ctrmm_cuda_func: bad transA parameter %d\n", transA);
    }
    if (diag == MorseNonUnit){
        cublasDiag = CUBLAS_DIAG_NON_UNIT;
    }else if(diag == MorseUnit){
        cublasDiag = CUBLAS_DIAG_UNIT;
    }else{
        fprintf(stderr, "Error in cl_ctrmm_cuda_func: bad diag parameter %d\n", diag);
    }

    stat = cublasCtrmm( handle,
        cublasSide, cublasUplo, cublasTransA, cublasDiag,
        M, N,
        (const cuFloatComplex *) &alpha, A, LDA,
        B, LDB, B, LDB);
    if (stat != CUBLAS_STATUS_SUCCESS){
        printf ("cublasCtrmm failed");
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
static void cl_ctrmm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    MORSE_enum transA;
    MORSE_enum diag;
    int M;
    int N;
    cuFloatComplex alpha;
    cuFloatComplex *A;
    int LDA;
    cuFloatComplex *B;
    int LDB;
    CUstream stream;

    A = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &transA, &diag, &M, &N, &alpha, &LDA, &LDB);

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    cublasCtrmm(
        morse_lapack_const(side), morse_lapack_const(uplo),
        morse_lapack_const(transA), morse_lapack_const(diag),
        M, N,
        alpha, A, LDA,
        B, LDB);

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
CODELETS(ctrmm, 2, cl_ctrmm_cpu_func, cl_ctrmm_cuda_func, STARPU_CUDA_ASYNC)
