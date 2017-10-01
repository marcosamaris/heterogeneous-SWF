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
 * @file codelet_dtrtri.c
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
 * @generated d Tue Sep 26 20:43:04 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void MORSE_TASK_dtrtri(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum diag,
                       int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       int iinfo)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dtrtri;
    void (*callback)(void*) = options->profiling ? cl_dtrtri_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &uplo,              sizeof(MORSE_enum),
            STARPU_VALUE,    &diag,              sizeof(MORSE_enum),
            STARPU_VALUE,    &n,                 sizeof(int),
            STARPU_RW,        RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &lda,               sizeof(int),
            STARPU_VALUE,    &iinfo,             sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_dtrtri_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum diag;
    int N;
    double *A;
    int LDA;
    int iinfo;

    int info = 0;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &diag, &N, &LDA, &iinfo);
    info = LAPACKE_dtrtri_work(
        LAPACK_COL_MAJOR,
        morse_lapack_const(uplo), morse_lapack_const(diag),
        N, A, LDA);
}

#if defined(CHAMELEON_USE_MAGMA)
static void cl_dtrtri_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    MORSE_enum diag;
    int N;
    double *A;
    int LDA;
    int iinfo;

    int ret;
    int info = 0;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &diag, &N, &LDA, &iinfo);
    ret = magma_dtrtri_gpu( uplo, diag,
			    N, A, LDA, &info);
     if (ret != MAGMA_SUCCESS) {
        fprintf(stderr, "Error in MAGMA: %d\n", ret);
        exit(-1);
    }

    cudaThreadSynchronize();
    return;
}
#endif

/*
 * Codelet definition
 */
#if defined(CHAMELEON_USE_MAGMA) || defined(CHAMELEON_SIMULATION)
CODELETS(dtrtri, 1, cl_dtrtri_cpu_func, cl_dtrtri_cuda_func, 0)
#else
CODELETS_CPU(dtrtri, 1, cl_dtrtri_cpu_func)
#endif
