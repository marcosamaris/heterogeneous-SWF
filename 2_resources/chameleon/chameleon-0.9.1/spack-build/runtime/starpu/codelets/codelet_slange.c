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
 * @file codelet_slange.c
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
 * @generated s Tue Sep 26 20:43:02 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_s.h"

void MORSE_TASK_slange(MORSE_option_t *options,
                       MORSE_enum norm, int M, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn)
{
    (void)NB;
    struct starpu_codelet *codelet = &cl_slange;
    void (*callback)(void*) = options->profiling ? cl_slange_callback : NULL;
    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ){
        starpu_insert_task(codelet,
                           STARPU_VALUE,    &norm,              sizeof(MORSE_enum),
                           STARPU_VALUE,    &M,                 sizeof(int),
                           STARPU_VALUE,    &N,                 sizeof(int),
                           STARPU_R,        RTBLKADDR(A, float, Am, An),
                           STARPU_VALUE,    &LDA,               sizeof(int),
                           STARPU_SCRATCH,  options->ws_worker,
                           STARPU_W,        RTBLKADDR(B, float, Bm, Bn),
                           STARPU_PRIORITY, options->priority,
                           STARPU_CALLBACK, callback,
                           0);
    }
}

static void cl_slange_cpu_func(void *descr[], void *cl_arg)
{
    float *normA;
    MORSE_enum norm;
    int M;
    int N;
    float *A;
    int LDA;
    float *work;

    A     = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    work  = (float *)STARPU_MATRIX_GET_PTR(descr[1]);
    normA = (float *)STARPU_MATRIX_GET_PTR(descr[2]);
    starpu_codelet_unpack_args(cl_arg, &norm, &M, &N, &LDA);
    CORE_slange( norm, M, N, A, LDA, work, normA);
}

/*
 * Codelet definition
 */
CODELETS_CPU(slange, 3, cl_slange_cpu_func)

void MORSE_TASK_slange_max(MORSE_option_t *options,
                           MORSE_desc_t *A, int Am, int An,
                           MORSE_desc_t *B, int Bm, int Bn)
{
    struct starpu_codelet *codelet = &cl_slange_max;
    void (*callback)(void*) = options->profiling ? cl_slange_callback : NULL;
    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ){
        starpu_insert_task(codelet,
                           STARPU_R,        RTBLKADDR(A, float, Am, An),
                           STARPU_RW,       RTBLKADDR(B, float, Bm, Bn),
                           STARPU_PRIORITY, options->priority,
                           STARPU_CALLBACK, callback,
                           0);
    }
}

static void cl_slange_max_cpu_func(void *descr[], void *cl_arg)
{
    float *A;
    float *normA;

    A     = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
    normA = (float *)STARPU_MATRIX_GET_PTR(descr[1]);

    if ( *A > *normA )
        *normA = *A;
}

/*
 * Codelet definition
 */
CODELETS_CPU(slange_max, 2, cl_slange_max_cpu_func)
