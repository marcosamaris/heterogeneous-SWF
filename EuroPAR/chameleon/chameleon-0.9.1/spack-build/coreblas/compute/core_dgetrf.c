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
 * @file core_dgetrf.c
 *
 *  PLASMA core_blas kernel
 *  PLASMA is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:00 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "coreblas/include/coreblas.h"


int CORE_dgetrf(int m, int n,
                 double *A, int lda,
                 int *IPIV, int *info)
{
    *info = LAPACKE_dgetrf_work(LAPACK_COL_MAJOR, m, n, A, lda, IPIV );
    return MORSE_SUCCESS;
}


