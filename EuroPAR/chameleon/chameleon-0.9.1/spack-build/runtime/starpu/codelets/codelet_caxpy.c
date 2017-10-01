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
 * @file codelet_caxpy.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Inria Bordeaux - Sud-Ouest, LaBRI,
 *  University of Bordeaux, Bordeaux INP
 *
 * @version 1.0.0
 * @author Florent Pruvost
 * @date 2014-07-18
 * @generated c Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"

void MORSE_TASK_caxpy(MORSE_option_t *options,
                      int M, MORSE_Complex32_t alpha,
                      MORSE_desc_t *A, int Am, int An, int incA,
                      MORSE_desc_t *B, int Bm, int Bn, int incB)
{
    struct starpu_codelet *codelet = &cl_caxpy;
    void (*callback)(void*) = options->profiling ? cl_caxpy_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( B, Bm, Bn ) ){
                starpu_insert_task(
                        codelet,
                        STARPU_VALUE,    &M,                           sizeof(int),
                        STARPU_VALUE,    alpha,                       sizeof(MORSE_Complex32_t),
                        STARPU_R,        RTBLKADDR(A, MORSE_Complex32_t, Am, An),
                        STARPU_VALUE,    &incA,                        sizeof(int),
                        STARPU_RW,       RTBLKADDR(B, MORSE_Complex32_t, Bm, Bn),
                        STARPU_VALUE,    &incB,                        sizeof(int),
                        STARPU_PRIORITY, options->priority,
                        STARPU_CALLBACK, callback,
                        0);
    }
}


static void cl_caxpy_cpu_func(void *descr[], void *cl_arg)
{
    int M;
    MORSE_Complex32_t alpha;
    MORSE_Complex32_t *A;
    int incA;
    MORSE_Complex32_t *B;
    int incB;
    int m, n;

    A = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &M, &alpha, &incA, &incB);
    cblas_caxpy(M, CBLAS_SADDR(alpha), A, incA, B, incB);
//    printf("\nCBLAS_SADDR(alpha) %e\n",alpha);
//    printf("A\n");
//    for(m = 0; m < M; m++) {
//      printf("%e ",A[m]);
//    }
//    printf("\n");
//    printf("B\n");
//    for(m = 0; m < M; m++) {
//      printf("%e ",B[m]);
//    }
//    printf("\n");
}

/*
 * Codelet definition
 */
CODELETS_CPU(caxpy, 2, cl_caxpy_cpu_func)
