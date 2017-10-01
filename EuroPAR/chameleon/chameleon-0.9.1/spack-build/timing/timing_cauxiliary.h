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
 * @generated c Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef TIMING_CAUXILIARY_H
#define TIMING_CAUXILIARY_H

int    c_check_orthogonality   (int M, int N, int LDQ, MORSE_Complex32_t *Q);
int    c_check_QRfactorization (int M, int N, MORSE_Complex32_t *A1, MORSE_Complex32_t *A2, int LDA, MORSE_Complex32_t *Q);
int    c_check_LLTfactorization(int N, MORSE_Complex32_t *A1, MORSE_Complex32_t *A2, int LDA, int uplo);
float c_check_gemm(MORSE_enum transA, MORSE_enum transB, int M, int N, int K,
                   MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA,
                   MORSE_Complex32_t *B, int LDB,
                   MORSE_Complex32_t beta, MORSE_Complex32_t *Cmorse,
                   MORSE_Complex32_t *Cref, int LDC,
                   float *Cinitnorm, float *Cmorsenorm, float *Clapacknorm );

float c_check_trsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum trans, MORSE_enum diag,
           int M, int NRHS, MORSE_Complex32_t alpha,
           MORSE_Complex32_t *A, int LDA,
           MORSE_Complex32_t *Bmorse, MORSE_Complex32_t *Bref, int LDB,
           float *Binitnorm, float *Bmorsenorm, float *Blapacknorm );

float c_check_solution(int M, int N, int NRHS,
                      MORSE_Complex32_t *A1, int LDA,
                      MORSE_Complex32_t *B1, MORSE_Complex32_t *B2, int LDB,
                      float *anorm, float *bnorm, float *xnorm);

int ccheck_inverse(int N, MORSE_Complex32_t *A1, MORSE_Complex32_t *A2,
                         int LDA, MORSE_enum uplo, float *rnorm, float *anorm, float *ainvnorm);


#endif /* TIMING_CAUXILIARY_H */
