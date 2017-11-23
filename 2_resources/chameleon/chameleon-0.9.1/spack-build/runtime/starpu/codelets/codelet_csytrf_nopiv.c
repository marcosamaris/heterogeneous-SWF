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
 * @file codelet_csytrf_nopiv.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Inria Bordeaux - Sud-Ouest, LaBRI,
 *  University of Bordeaux, Bordeaux INP
 *
 * @version 1.0.0
 * @author Hatem Ltaief
 * @author Jakub Kurzak
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @author Florent Pruvost
 * @author Marc Sergent
 * @date 2011-10-09
 * @generated c Tue Sep 26 20:43:03 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"


void MORSE_TASK_csytrf_nopiv(MORSE_option_t *options,
                             MORSE_enum uplo, int n, int nb,
                             MORSE_desc_t *A, int Am, int An, int lda,
                             int iinfo)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_csytrf_nopiv;
    void (*callback)(void*) = options->profiling ? cl_csytrf_nopiv_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &uplo,                      sizeof(MORSE_enum),
            STARPU_VALUE,    &n,                         sizeof(int),
            STARPU_RW,        RTBLKADDR(A, MORSE_Complex32_t, Am, An),
            STARPU_VALUE,    &lda,                       sizeof(int),
            STARPU_VALUE,    &iinfo,                     sizeof(int),
            //STARPU_SCRATCH,   options->ws_worker,
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_csytrf_nopiv_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_enum uplo;
    int n;
    MORSE_Complex32_t *A;
    int lda;
    int iinfo;
    int info = 0;

    A = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[0]);

    starpu_codelet_unpack_args(cl_arg, &uplo, &n, &lda, &iinfo);
    info = CORE_csytf2_nopiv(uplo, n, A, lda);
}

/*
 * Codelet definition
 */
CODELETS_CPU(csytrf_nopiv, 1, cl_csytrf_nopiv_cpu_func)
