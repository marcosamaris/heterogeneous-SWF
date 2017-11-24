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
 * @file codelet_spotrf.c
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
 * @generated s Tue Sep 26 20:43:03 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_s.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void MORSE_TASK_spotrf(MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       int iinfo)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_spotrf;
    void (*callback)(void*) = options->profiling ? cl_spotrf_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &uplo,                      sizeof(MORSE_enum),
            STARPU_VALUE,    &n,                         sizeof(int),
            STARPU_RW,        RTBLKADDR(A, float, Am, An),
            STARPU_VALUE,    &lda,                       sizeof(int),
            STARPU_VALUE,    &iinfo,                     sizeof(int),
            //STARPU_SCRATCH,   options->ws_worker,
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_spotrf_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    int n;
    float *A;
    int lda;
    int iinfo;
    int info = 0;

    A = (float *)STARPU_MATRIX_GET_PTR(descr[0]);

    starpu_codelet_unpack_args(cl_arg, &uplo, &n, &lda, &iinfo);
    info = LAPACKE_spotrf_work(
        LAPACK_COL_MAJOR,
        morse_lapack_const(uplo),
        n, A, lda);
}

#ifdef CHAMELEON_USE_MAGMA
static void cl_spotrf_cuda_func(void *descr[], void *cl_arg)
{
    cudaStream_t stream[2], currentt_stream;
    MORSE_enum uplo;
    int n;
    float *A;
    /* float *hA; */
    int lda;
    int iinfo;

    int ret;
    int info = 0;

    A  = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &n, &lda, &iinfo);

    /* /\* */
    /*  *  hwork => nb*nb */
    /*  *\/ */
    /* hA = (float *)STARPU_MATRIX_GET_PTR(descr[1]); */

//     stream[0] = starpu_cuda_get_local_stream();
//     if ( cudaStreamCreate( stream+1 ) != CUDA_SUCCESS ){
//         fprintf(stderr, "Error while creating stream in codelet_spotrf\n");
//         exit(-1);
//     }

    ret = magma_spotrf_gpu(
        uplo,
        n, A, lda, &info);
/*	hA, stream );*/
     if (ret != MAGMA_SUCCESS) {
        fprintf(stderr, "Error in MAGMA: %d\n", ret);
        exit(-1);
    }

    cudaThreadSynchronize();
//     cudaStreamDestroy( stream[1] );

    return;
}
#endif

/*
 * Codelet definition
 */
#if defined CHAMELEON_USE_MAGMA || defined(CHAMELEON_SIMULATION)
CODELETS(spotrf, 1, cl_spotrf_cpu_func, cl_spotrf_cuda_func, 0)
#else
CODELETS_CPU(spotrf, 1, cl_spotrf_cpu_func)
#endif