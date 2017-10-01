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
 * @file codelet_sgessq.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Inria Bordeaux - Sud-Ouest, LaBRI,
 *  University of Bordeaux, Bordeaux INP
 *
 * @version 2.6.0
 * @comment This file has been automatically generated
 *          from Plasma 2.6.0 for MORSE 1.0.0
 * @author Mathieu Faverge
 * @date 2010-11-15
 * @generated s Tue Sep 26 20:43:01 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_s.h"

void MORSE_TASK_sgessq( MORSE_option_t *options,
                        int m, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn )
{
    struct starpu_codelet *codelet = &cl_sgessq;
    void (*callback)(void*) = options->profiling ? cl_sgessq_callback : NULL;
    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( SCALESUMSQ, SCALESUMSQm, SCALESUMSQn ) ){
        starpu_insert_task(codelet,
            STARPU_VALUE,    &m,                          sizeof(int),
            STARPU_VALUE,    &n,                          sizeof(int),
            STARPU_R,        RTBLKADDR(A, float, Am, An),
            STARPU_VALUE,    &lda,                        sizeof(int),
            STARPU_RW,       RTBLKADDR(SCALESUMSQ, float, SCALESUMSQm, SCALESUMSQn),
            STARPU_PRIORITY, options->priority,
            STARPU_CALLBACK, callback,
            0);
    }
}


static void cl_sgessq_cpu_func(void *descr[], void *cl_arg)
{
    int m;
    int n;
    float *A;
    int lda;
    float *SCALESUMSQ;

    A          = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    SCALESUMSQ = (float *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &m, &n, &lda);
    CORE_sgessq( m, n, A, lda, &SCALESUMSQ[0], &SCALESUMSQ[1] );
}
/*
 * Codelet definition
 */
CODELETS_CPU(sgessq, 2, cl_sgessq_cpu_func)
