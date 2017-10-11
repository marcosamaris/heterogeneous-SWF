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
 * @file codelet_dgetrf.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:01 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

void MORSE_TASK_dgetrf(MORSE_option_t *options,
                       int m, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       int *IPIV,
                       MORSE_bool check_info, int iinfo)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dgetrf;
    void (*callback)(void*) = options->profiling ? cl_dgetrf_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,             &m,                        sizeof(int),
            STARPU_VALUE,             &n,                        sizeof(int),
            STARPU_RW,                     RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,           &lda,                        sizeof(int),
            STARPU_VALUE,                  &IPIV,                      sizeof(int*),
            STARPU_VALUE,    &check_info,                sizeof(MORSE_bool),
            STARPU_VALUE,         &iinfo,                        sizeof(int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback,
            0);
    }
}


static void cl_dgetrf_cpu_func(void *descr[], void *cl_arg)
{
    int m;
    int n;
    double *A;
    int lda;
    int *IPIV;
    MORSE_bool check_info;
    int iinfo;
    int info = 0;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    starpu_codelet_unpack_args(cl_arg, &m, &n, &lda, &IPIV, &check_info, &iinfo);
    info = LAPACKE_dgetrf_work(LAPACK_COL_MAJOR, m, n, A, lda, IPIV );
}
/*
 * Codelet definition
 */
CODELETS_CPU(dgetrf, 1, cl_dgetrf_cpu_func)