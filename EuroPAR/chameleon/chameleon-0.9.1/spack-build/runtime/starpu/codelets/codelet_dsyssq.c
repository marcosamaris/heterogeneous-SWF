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
 * @file codelet_dsyssq.c
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
 * @generated d Tue Sep 26 20:43:03 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

void MORSE_TASK_dsyssq( MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn )
{
    struct starpu_codelet *codelet = &cl_dsyssq;
    void (*callback)(void*) = options->profiling ? cl_dgessq_callback : NULL;
    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( SCALESUMSQ, SCALESUMSQm, SCALESUMSQn ) ){
        starpu_insert_task(codelet,
            STARPU_VALUE,    &uplo,                       sizeof(MORSE_enum),
            STARPU_VALUE,    &n,                          sizeof(int),
            STARPU_R,        RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &lda,                        sizeof(int),
            STARPU_RW,       RTBLKADDR(SCALESUMSQ, double, SCALESUMSQm, SCALESUMSQn),
            STARPU_PRIORITY, options->priority,
            STARPU_CALLBACK, callback,
            0);
    }
}


static void cl_dsyssq_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    int n;
    double *A;
    int lda;
    double *SCALESUMSQ;

    A          = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    SCALESUMSQ = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &uplo, &n, &lda);
    CORE_dsyssq( uplo, n, A, lda, &SCALESUMSQ[0], &SCALESUMSQ[1] );
}
/*
 * Codelet definition
 */
CODELETS_CPU(dsyssq, 2, cl_dsyssq_cpu_func)
