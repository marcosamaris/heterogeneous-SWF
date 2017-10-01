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
 * @file codelet_cgeadd.c
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
 * @generated c Tue Sep 26 20:43:01 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_cgeadd adds to matrices together.
 *
 *       B <- alpha * A  + B
 *
 *******************************************************************************
 *
 * @param[in] M
 *          Number of rows of the matrices A and B.
 *
 * @param[in] N
 *          Number of columns of the matrices A and B.
 *
 * @param[in] alpha
 *          Scalar factor of A.
 *
 * @param[in] A
 *          Matrix of size LDA-by-N.
 *
 * @param[in] LDA
 *          Leading dimension of the array A. LDA >= max(1,M)
 *
 * @param[in,out] B
 *          Matrix of size LDB-by-N.
 *
 * @param[in] LDB
 *          Leading dimension of the array B. LDB >= max(1,M)
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *
 ******************************************************************************/

void MORSE_TASK_cgeadd(MORSE_option_t *options,
                       int m, int n, MORSE_Complex32_t alpha,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb)
{
    struct starpu_codelet *codelet = &cl_cgeadd;
    void (*callback)(void*) = options->profiling ? cl_cgeadd_callback : NULL;

    if ( morse_desc_islocal( A, Am, An ) ||
	 morse_desc_islocal( B, Bm, Bn ) )
    {
	starpu_insert_task(
            codelet,
            STARPU_VALUE,    &m,                  sizeof(int),
            STARPU_VALUE,    &n,                  sizeof(int),
            STARPU_VALUE,    &alpha,              sizeof(MORSE_Complex32_t),
            STARPU_R,         RTBLKADDR(A, MORSE_Complex32_t, Am, An),
            STARPU_VALUE,    &lda,                sizeof(int),
            STARPU_RW,        RTBLKADDR(B, MORSE_Complex32_t, Bm, Bn),
            STARPU_VALUE,    &ldb,                sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_cgeadd_cpu_func(void *descr[], void *cl_arg)
{
    int M;
    int N;
    MORSE_Complex32_t alpha;
    MORSE_Complex32_t *A;
    int LDA;
    MORSE_Complex32_t *B;
    int LDB;

    A = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[0]);
    B = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[1]);
    starpu_codelet_unpack_args(cl_arg, &M, &N, &alpha, &LDA, &LDB);
    CORE_cgeadd(M, N, alpha, A, LDA, B, LDB);
    return;
}

/*
 * Codelet definition
 */
CODELETS_CPU(cgeadd, 2, cl_cgeadd_cpu_func)
