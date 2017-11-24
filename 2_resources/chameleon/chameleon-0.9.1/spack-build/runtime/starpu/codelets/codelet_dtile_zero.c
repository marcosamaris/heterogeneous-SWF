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
 * @file codelet_dtile_zero.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 0.9.0
 * @author Hatem Ltaief
 * @author Mathieu Faverge
 * @author Jakub Kurzak
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

/*****************************************************************************
 *
 **/
void MORSE_TASK_dtile_zero(MORSE_option_t *options,
                           int X1, int X2, int Y1, int Y2,
                           MORSE_desc_t *A, int Am, int An, int lda)
{
    struct starpu_codelet *codelet;
    codelet = &cl_dtile_zero;
    void (*callback)(void*) = options->profiling ? cl_dlacpy_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE, &X1,  sizeof(int),
            STARPU_VALUE, &X2,  sizeof(int),
            STARPU_VALUE, &Y1,  sizeof(int),
            STARPU_VALUE, &Y2,  sizeof(int),
            STARPU_RW,     RTBLKADDR(A, double, Am, An),
            STARPU_VALUE, &lda, sizeof(int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback, NULL,
            0);
    }
}

/*****************************************************************************
 *
 **/
static void cl_dtile_zero_cpu_func(void *descr[], void *cl_arg)
{
    int X1;
    int X2;
    int Y1;
    int Y2;
    double *A;
    int lda;

    int x, y;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    starpu_codelet_unpack_args(cl_arg, &X1, &X2, &Y1, &Y2, &lda);

    for (x = X1; x < X2; x++)
        for (y = Y1; y < Y2; y++)
            A[lda*x+y] = 0.0;

}

/*
 * Codelet definition
 */
CODELETS_CPU(dtile_zero, 1, cl_dtile_zero_cpu_func)