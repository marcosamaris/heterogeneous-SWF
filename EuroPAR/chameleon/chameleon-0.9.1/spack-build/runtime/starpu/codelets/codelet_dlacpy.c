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
 * @file codelet_dlacpy.c
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
 * @generated d Tue Sep 26 20:43:02 2017
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

void MORSE_TASK_dlacpy(MORSE_option_t *options,
                       MORSE_enum uplo, int m, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dlacpy;
    void (*callback)(void*) = options->profiling ? cl_dlacpy_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,  &uplo,                sizeof(MORSE_enum),
            STARPU_VALUE,     &m,                        sizeof(int),
            STARPU_VALUE,     &n,                        sizeof(int),
            STARPU_R,             RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,   &lda,                        sizeof(int),
            STARPU_W,             RTBLKADDR(B, double, Bm, Bn),
            STARPU_VALUE,   &ldb,                        sizeof(int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback,
            0);
    }
}


static void cl_dlacpy_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    int M;
    int N;
    double *A;
    int LDA;
    double *B;
    int LDB;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &M, &N, &LDA, &LDB);
    LAPACKE_dlacpy_work(
        LAPACK_COL_MAJOR,
        morse_lapack_const(uplo),
        M, N, A, LDA, B, LDB);
}

/*
 * Codelet definition
 */
CODELETS_CPU(dlacpy, 2, cl_dlacpy_cpu_func)
