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
 * @file codelet_dtstrf.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Hatem Ltaief
 * @author Jakub Kurzak
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:04 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"
#include "coreblas/include/cblas.h"
#include <math.h>

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_dtstrf computes an LU factorization of a real matrix formed
 *  by an upper triangular NB-by-N tile U on top of a M-by-N tile A
 *  using partial pivoting with row interchanges.
 *
 *  This is the right-looking Level 2.5 BLAS version of the algorithm.
 *
 *******************************************************************************
 *
 * @param[in] M
 *         The number of rows of the tile A.  M >= 0.
 *
 * @param[in] N
 *         The number of columns of the tile A.  N >= 0.
 *
 * @param[in] IB
 *         The inner-blocking size.  IB >= 0.
 *
 * @param[in] NB
 *
 * @param[in,out] U
 *         On entry, the NB-by-N upper triangular tile.
 *         On exit, the new factor U from the factorization
 *
 * @param[in] LDU
 *         The leading dimension of the array U.  LDU >= max(1,NB).
 *
 * @param[in,out] A
 *         On entry, the M-by-N tile to be factored.
 *         On exit, the factor L from the factorization
 *
 * @param[in] LDA
 *         The leading dimension of the array A.  LDA >= max(1,M).
 *
 * @param[in,out] L
 *         On entry, the IB-by-N lower triangular tile.
 *         On exit, the interchanged rows form the tile A in case of pivoting.
 *
 * @param[in] LDL
 *         The leading dimension of the array L.  LDL >= max(1,IB).
 *
 * @param[out] IPIV
 *         The pivot indices; for 1 <= i <= min(M,N), row i of the
 *         tile U was interchanged with row IPIV(i) of the tile A.
 *
 * @param[in,out] WORK
 *
 * @param[in] LDWORK
 *         The dimension of the array WORK.
 *
 * @param[out] INFO
 *
 *******************************************************************************
 *
 * @return
 *         \retval MORSE_SUCCESS successful exit
 *         \retval <0 if INFO = -k, the k-th argument had an illegal value
 *         \retval >0 if INFO = k, U(k,k) is exactly zero. The factorization
 *              has been completed, but the factor U is exactly
 *              singular, and division by zero will occur if it is used
 *              to solve a system of equations.
 *
 ******************************************************************************/

void MORSE_TASK_dtstrf(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *U, int Um, int Un, int ldu,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       int *IPIV,
                       MORSE_bool check_info, int iinfo)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_dtstrf;
    void (*callback)(void*) = options->profiling ? cl_dtstrf_callback : NULL;
    MORSE_starpu_ws_t *d_work = (MORSE_starpu_ws_t*)(options->ws_host);

    if ( morse_desc_islocal( U, Um, Un ) ||
         morse_desc_islocal( A, Am, An ) ||
         morse_desc_islocal( L, Lm, Ln ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &m,                         sizeof(int),
            STARPU_VALUE,    &n,                         sizeof(int),
            STARPU_VALUE,    &ib,                        sizeof(int),
            STARPU_VALUE,    &nb,                        sizeof(int),
            STARPU_RW,        RTBLKADDR(U, double, Um, Un),
            STARPU_VALUE,    &ldu,                       sizeof(int),
            STARPU_RW,        RTBLKADDR(A, double, Am, An),
            STARPU_VALUE,    &lda,                       sizeof(int),
            STARPU_W,         RTBLKADDR(L, double, Lm, Ln),
            STARPU_VALUE,    &ldl,                       sizeof(int),
            STARPU_VALUE,    &IPIV,                      sizeof(int*),
            STARPU_SCRATCH,   options->ws_worker,
            STARPU_VALUE,    &d_work,                    sizeof(MORSE_starpu_ws_t *),
            STARPU_VALUE,    &nb,                        sizeof(int),
            STARPU_VALUE,    &check_info,                sizeof(MORSE_bool),
            STARPU_VALUE,    &iinfo,                     sizeof(int),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_dtstrf_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *d_work;
    int m;
    int n;
    int ib;
    int nb;
    double *U;
    int ldu;
    double *A;
    int lda;
    double *L;
    int ldl;
    int *IPIV;
    double *WORK;
    int ldwork;
    MORSE_bool check_info;
    int iinfo;

    int info = 0;

    U = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    A = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    L = (double *)STARPU_MATRIX_GET_PTR(descr[2]);
    WORK = (double *)STARPU_MATRIX_GET_PTR(descr[3]);

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &nb, &ldu, &lda, &ldl, &IPIV, &d_work, &ldwork, &check_info, &iinfo);

    CORE_dtstrf(m, n, ib, nb, U, ldu, A, lda, L, ldl, IPIV, WORK, ldwork, &info);

#if defined(CHAMELEON_USE_MAGMA)
    /*
     * L stores the following if enough place:
     *      L1     L2    L3     ...
     *      L1^-1  L2^-1 L3^-1  ...
     */
    /* Compute L-1 in lower rectangle of L */
    if ( ldl >= 2*ib )
    {
        int i, sb;
        for (i=0; i<n; i+=ib) {
            sb = min( ib, n-i );
            CORE_dlacpy(MorseUpperLower, sb, sb, L+(i*ldl), ldl, L+(i*ldl)+ib, ldl );

            CORE_dtrtri( MorseLower, MorseUnit, sb, L+(i*ldl)+ib, ldl, &info );
            if (info != 0 ) {
                fprintf(stderr, "ERROR, trtri returned with info = %d\n", info);
            }
        }
    }
#endif
}


/*
 * Codelet GPU
 */
/* TODO/WARNING: tstrf is not working on GPU for now */
#if defined(CHAMELEON_USE_MAGMA) && 0
static void cl_dtstrf_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *d_work;
    int m;
    int n;
    int ib;
    int nb;
    double *hU, *dU;
    int ldu;
    double *hA, *dA;
    int lda;
    double *hL, *dL;
    int ldl;
    int *ipiv;
    double *hw2, *hw, *dw;
    int ldwork;
    MORSE_bool check_info;
    int iinfo;
    int info;

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &nb, &ldu, &lda, &ldl, &ipiv,
			       &d_work, &ldwork, &check_info, &iinfo);

    dU = (double *)STARPU_MATRIX_GET_PTR(descr[0]);
    dA = (double *)STARPU_MATRIX_GET_PTR(descr[1]);
    dL = (double *)STARPU_MATRIX_GET_PTR(descr[2]);

    /*
     *  hwork => 2*nb*(2*ib+2nb)
     *  dwork => 2*ib*nb
     */
    hw2 = (double *)STARPU_MATRIX_GET_PTR(descr[3]);
    dw  = (double*)RUNTIME_starpu_ws_getlocal(d_work);

    hU = hw2;
    hA = hU + ldu * nb;
    hL = hA + lda * nb;
    hw = hL + ldl * nb;

    /* Download first panel from A and U */
    cublasGetMatrix( nb, n,  sizeof(double), dU, ldu, hU, ldu );
    cublasGetMatrix( m,  ib, sizeof(double), dA, lda, hA, lda );

    /* Initialize L to 0 */
    memset(hL, 0, ldl*nb*sizeof(double));

    magma_dtstrf_gpu( MagmaColMajor, m, n, ib, nb,
                      hU, ldu, dU, ldu,
                      hA, lda, dA, lda,
                      hL, ldl, dL, ldl,
                      ipiv,
                      hw, ldwork, dw, lda,
                      &info );

    cudaThreadSynchronize();
}
#endif

/*
 * Codelet definition
 */
#if (defined(CHAMELEON_USE_MAGMA) && 0) || defined(CHAMELEON_SIMULATION)
CODELETS(dtstrf, 4, cl_dtstrf_cpu_func, cl_dtstrf_cuda_func, 0)
#else
CODELETS_CPU(dtstrf, 4, cl_dtstrf_cpu_func)
#endif

