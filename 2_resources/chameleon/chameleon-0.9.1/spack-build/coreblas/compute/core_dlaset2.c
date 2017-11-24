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
 * @file core_dlaset2.c
 *
 *  PLASMA core_blas kernel
 *  PLASMA is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Hatem Ltaief
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated d Tue Sep 26 20:43:02 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "coreblas/include/coreblas.h"


/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 *  CORE_dlaset2 - Sets the elements of the matrix A to alpha.
 *  Not LAPACK compliant! Read below.
 *
 *******************************************************************************
 *
 * @param[in] uplo
 *          Specifies which elements of the matrix are to be set
 *          = MorseUpper: STRICT Upper part of A is set to alpha;
 *          = MorseLower: STRICT Lower part of A is set to alpha;
 *          = MorseUpperLower: ALL elements of A are set to alpha.
 *          Not LAPACK Compliant.
 *
 * @param[in] M
 *          The number of rows of the matrix A.  M >= 0.
 *
 * @param[in] N
 *         The number of columns of the matrix A.  N >= 0.
 *
 * @param[in] alpha
 *         The constant to which the elements are to be set.
 *
 * @param[in,out] A
 *         On entry, the M-by-N tile A.
 *         On exit, A has been set to alpha accordingly.
 *
 * @param[in] LDA
 *         The leading dimension of the array A.  LDA >= max(1,M).
 *
 **/

void CORE_dlaset2(MORSE_enum uplo, int M, int N,
                  double alpha, double *A, int LDA)
{
    if (uplo == MorseUpper) {
        LAPACKE_dlaset_work(
            LAPACK_COL_MAJOR,
            morse_lapack_const(uplo),
            M, N-1, alpha, alpha, A+LDA, LDA);
    }
    else if (uplo == MorseLower) {
        LAPACKE_dlaset_work(
            LAPACK_COL_MAJOR,
            morse_lapack_const(uplo),
            M-1, N, alpha, alpha, A+1, LDA);
    }
    else {
        LAPACKE_dlaset_work(
            LAPACK_COL_MAJOR,
            morse_lapack_const(uplo),
            M, N, alpha, alpha, A, LDA);
    }
}

