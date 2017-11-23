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
 * @file codelet_dsymm.c
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

void MORSE_TASK_dsymm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dsymm;
    void (*callback)(void*) = options->profiling ? cl_dsymm_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ||
         morse_desc_islocal( C, Cm, Cn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &side,                sizeof(MORSE_enum),
            STARPU_VALUE,    &uplo,                sizeof(MORSE_enum),
            STARPU_VALUE,       &m,                        sizeof(int),
            STARPU_VALUE,       &n,                        sizeof(int),
            STARPU_VALUE,   &alpha,         sizeof(double),
            STARPU_R,               RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,     &lda,                        sizeof(int),
            STARPU_R,               RTBLKADDR(B, double, Bm, Bn),
            STARPU_VALUE,     &ldb,                        sizeof(int),
            STARPU_VALUE,    &beta,         sizeof(double),
            STARPU_RW,               RTBLKADDR(C, double, Cm, Cn),
            STARPU_VALUE,     &ldc,                        sizeof(int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback,
            0);
    }
}


static void cl_dsymm_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    int M;
    int N;
    double alpha;
    double *A;
    int LDA;
    double *B;
    int LDB;
    double beta;
    double *C;
    int LDC;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &M, &N, &alpha, &LDA, &LDB, &beta, &LDC);
    cblas_dsymm(
        CblasColMajor,
        (CBLAS_SIDE)side, (CBLAS_UPLO)uplo,
        M, N,
        (alpha), A, LDA,
        B, LDB,
        (beta), C, LDC);
}

#ifdef CHAMELEON_USE_CUDA
#if defined(CHAMELEON_USE_CUBLAS_V2)
static void cl_dsymm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    int M;
    int N;
    double alpha;
    const double *A;
    int LDA;
    const double *B;
    int LDB;
    double beta;
    double *C;
    int LDC;
    CUstream stream;
    cublasHandle_t handle;
    cublasStatus_t stat;
    cublasSideMode_t cublasSide;
    cublasFillMode_t cublasUplo;

    A = (const double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (const double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &M, &N, &alpha, &LDA, &LDB, &beta, &LDC);

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
        fprintf(stderr, "Error in cl_dsymm_cuda_func: bad side parameter %d\n", side);
    }
    if (uplo == MorseUpper){
        cublasUplo = CUBLAS_FILL_MODE_UPPER;
    }else if(uplo == MorseLower){
        cublasUplo = CUBLAS_FILL_MODE_LOWER;
    }else if(uplo == MorseUpperLower){
        cublasUplo = 0;
    }else{
        fprintf(stderr, "Error in cl_dsymm_cuda_func: bad uplo parameter %d\n", uplo);
    }

    stat = cublasDsymm(handle,
        cublasSide, cublasUplo,
        M, N,
        (const double *) &alpha, A, LDA,
        B, LDB,
        (const double *) &beta, C, LDC);
    if (stat != CUBLAS_STATUS_SUCCESS){
        printf ("cublasDsymm failed");
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
static void cl_dsymm_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum side;
    MORSE_enum uplo;
    int M;
    int N;
    double alpha;
    double *A;
    int LDA;
    double *B;
    int LDB;
    double beta;
    double *C;
    int LDC;
    CUstream stream;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    C = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &side, &uplo, &M, &N, &alpha, &LDA, &LDB, &beta, &LDC);

    stream = starpu_cuda_get_local_stream();
    cublasSetKernelStream( stream );

    cublasDsymm(
        morse_lapack_const(side), morse_lapack_const(uplo),
        M, N,
        alpha, A, LDA,
        B, LDB,
        beta, C, LDC);

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
CODELETS(dsymm, 3, cl_dsymm_cpu_func, cl_dsymm_cuda_func, STARPU_CUDA_ASYNC)
