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
 * @generated d Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef TIMING_DAUXILIARY_H
#define TIMING_DAUXILIARY_H

int    d_check_orthogonality   (int M, int N, int LDQ, double *Q);
int    d_check_QRfactorization (int M, int N, double *A1, double *A2, int LDA, double *Q);
int    d_check_LLTfactorization(int N, double *A1, double *A2, int LDA, int uplo);
double d_check_gemm(MORSE_enum transA, MORSE_enum transB, int M, int N, int K,
                   double alpha, double *A, int LDA,
                   double *B, int LDB,
                   double beta, double *Cmorse,
                   double *Cref, int LDC,
                   double *Cinitnorm, double *Cmorsenorm, double *Clapacknorm );

double d_check_trsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum trans, MORSE_enum diag,
           int M, int NRHS, double alpha,
           double *A, int LDA,
           double *Bmorse, double *Bref, int LDB,
           double *Binitnorm, double *Bmorsenorm, double *Blapacknorm );

double d_check_solution(int M, int N, int NRHS,
                      double *A1, int LDA,
                      double *B1, double *B2, int LDB,
                      double *anorm, double *bnorm, double *xnorm);

int dcheck_inverse(int N, double *A1, double *A2,
                         int LDA, MORSE_enum uplo, double *rnorm, double *anorm, double *ainvnorm);


#endif /* TIMING_DAUXILIARY_H */
