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
 * @file codelet_dplgsy.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Piotr Luszczek
 * @author Pierre Lemarinier
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:03 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"



void MORSE_TASK_dplgsy( MORSE_option_t *options,
                        double bump, int m, int n, MORSE_desc_t *A, int Am, int An, int lda,
                        int bigM, int m0, int n0, unsigned long long int seed )
{

    struct starpu_codelet *codelet = &cl_dplgsy;
    void (*callback)(void*) = options->profiling ? cl_dplgsy_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE, &bump,       sizeof(double),
            STARPU_VALUE,    &m,                      sizeof(int),
            STARPU_VALUE,    &n,                      sizeof(int),
            STARPU_W,         RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,  &lda,                      sizeof(int),
            STARPU_VALUE, &bigM,                      sizeof(int),
            STARPU_VALUE,   &m0,                      sizeof(int),
            STARPU_VALUE,   &n0,                      sizeof(int),
            STARPU_VALUE, &seed,   sizeof(unsigned long long int),
            STARPU_PRIORITY,    options->priority,
            STARPU_CALLBACK,    callback,
            0);
    }
}


static void cl_dplgsy_cpu_func(void *descr[], void *cl_arg)
{
    double bump;
    int m;
    int n;
    double *A;
    int lda;
    int bigM;
    int m0;
    int n0;
    unsigned long long int seed;

    A = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    starpu_codelet_unpack_args(cl_arg, &bump, &m, &n, &lda, &bigM, &m0, &n0, &seed );
    CORE_dplgsy( bump, m, n, A, lda, bigM, m0, n0, seed );
}

/*
 * Codelet definition
 */
CODELETS_CPU(dplgsy, 1, cl_dplgsy_cpu_func)