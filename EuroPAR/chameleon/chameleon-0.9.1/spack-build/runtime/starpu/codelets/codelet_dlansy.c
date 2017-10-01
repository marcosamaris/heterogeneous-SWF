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
 * @file codelet_dlansy.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Inria Bordeaux - Sud-Ouest, LaBRI,
 *  University of Bordeaux, Bordeaux INP
 *
 * @version 2.6.0
 * @comment This file has been automatically generated
 *          from Plasma 2.6.0 for MORSE 1.0.0
 * @author Julien Langou
 * @author Henricus Bouwmeester
 * @author Mathieu Faverge
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:02 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

void MORSE_TASK_dlansy(MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn)
{
    (void)NB;
    struct starpu_codelet *codelet = &cl_dlansy;
    void (*callback)(void*) = options->profiling ? cl_dlange_callback : NULL;
    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ){
        starpu_insert_task(codelet,
            STARPU_VALUE,    &norm,              sizeof(MORSE_enum),
            STARPU_VALUE,    &uplo,              sizeof(MORSE_enum),
            STARPU_VALUE,    &N,                 sizeof(int),
            STARPU_R,        RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &LDA,               sizeof(int),
            STARPU_SCRATCH,  options->ws_worker,
            STARPU_W,        RTBLKADDR(B, double, Bm, Bn),
            STARPU_PRIORITY, options->priority,
            STARPU_CALLBACK, callback,
            0);
    }
}

static void cl_dlansy_cpu_func(void *descr[], void *cl_arg)
{
    double *normA;
    MORSE_enum norm;
    MORSE_enum uplo;
    int N;
    double *A;
    int LDA;
    double *work;

    A     = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    work  = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    normA = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &norm, &uplo, &N, &LDA);
    CORE_dlansy( norm, uplo, N, A, LDA, work, normA);
}

/*
 * Codelet definition
 */
CODELETS_CPU(dlansy, 3, cl_dlansy_cpu_func)
