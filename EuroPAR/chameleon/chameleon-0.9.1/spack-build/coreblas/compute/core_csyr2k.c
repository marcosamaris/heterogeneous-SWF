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
 * @file core_csyr2k.c
 *
 *  PLASMA core_blas kernel
 *  PLASMA is a software package provided by Univ. of Tennessee,
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
 * @generated c Tue Sep 26 20:43:03 2017
 *
 **/
#include "coreblas/include/coreblas.h"

/***************************************************************************//**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 **/

void CORE_csyr2k(MORSE_enum uplo, MORSE_enum trans,
                 int N, int K,
                 MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                 const MORSE_Complex32_t *B, int LDB,
                 MORSE_Complex32_t beta, MORSE_Complex32_t *C, int LDC)
{
    cblas_csyr2k(
        CblasColMajor,
        (CBLAS_UPLO)uplo, (CBLAS_TRANSPOSE)trans,
        N, K,
        CBLAS_SADDR(alpha), A, LDA, B, LDB,
        CBLAS_SADDR(beta), C, LDC);
}


