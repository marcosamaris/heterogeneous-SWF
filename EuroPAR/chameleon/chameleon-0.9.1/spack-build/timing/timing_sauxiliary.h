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
 * @generated s Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef TIMING_SAUXILIARY_H
#define TIMING_SAUXILIARY_H

int    s_check_orthogonality   (int M, int N, int LDQ, float *Q);
int    s_check_QRfactorization (int M, int N, float *A1, float *A2, int LDA, float *Q);
int    s_check_LLTfactorization(int N, float *A1, float *A2, int LDA, int uplo);
float s_check_gemm(MORSE_enum transA, MORSE_enum transB, int M, int N, int K,
                   float alpha, float *A, int LDA,
                   float *B, int LDB,
                   float beta, float *Cmorse,
                   float *Cref, int LDC,
                   float *Cinitnorm, float *Cmorsenorm, float *Clapacknorm );

float s_check_trsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum trans, MORSE_enum diag,
           int M, int NRHS, float alpha,
           float *A, int LDA,
           float *Bmorse, float *Bref, int LDB,
           float *Binitnorm, float *Bmorsenorm, float *Blapacknorm );

float s_check_solution(int M, int N, int NRHS,
                      float *A1, int LDA,
                      float *B1, float *B2, int LDB,
                      float *anorm, float *bnorm, float *xnorm);

int scheck_inverse(int N, float *A1, float *A2,
                         int LDA, MORSE_enum uplo, float *rnorm, float *anorm, float *ainvnorm);


#endif /* TIMING_SAUXILIARY_H */
