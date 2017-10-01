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
 * @generated d Tue Sep 26 20:43:00 2017
 *
 **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <morse.h>
#include <coreblas/include/cblas.h>
#include <coreblas/include/lapacke.h>
#include <coreblas/include/coreblas.h>
#include "timing_dauxiliary.h"

/*-------------------------------------------------------------------
 * Check the orthogonality of Q
 */

int d_check_orthogonality(int M, int N, int LDQ, double *Q)
{
    double alpha, beta;
    double normQ;
    int info_ortho;
    int i;
    int minMN = min(M, N);
    double eps;
    double *work = (double *)malloc(minMN*sizeof(double));

    eps = LAPACKE_dlamch_work('e');
    alpha = 1.0;
    beta  = -1.0;

    /* Build the idendity matrix USE DLASET?*/
    double *Id = (double *) malloc(minMN*minMN*sizeof(double));
    memset((void*)Id, 0, minMN*minMN*sizeof(double));
    for (i = 0; i < minMN; i++)
        Id[i*minMN+i] = (double)1.0;

    /* Perform Id - Q'Q */
    if (M >= N)
        cblas_dsyrk(CblasColMajor, CblasUpper, CblasTrans, N, M, alpha, Q, LDQ, beta, Id, N);
    else
        cblas_dsyrk(CblasColMajor, CblasUpper, CblasNoTrans, M, N, alpha, Q, LDQ, beta, Id, M);

    normQ = LAPACKE_dlansy_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), 'u', minMN, Id, minMN, work);

    printf("============\n");
    printf("Checking the orthogonality of Q \n");
    printf("||Id-Q'*Q||_oo / (N*eps) = %e \n",normQ/(minMN*eps));

    if ( isnan(normQ / (minMN * eps)) || (normQ / (minMN * eps) > 10.0) ) {
        printf("-- Orthogonality is suspicious ! \n");
        info_ortho=1;
    }
    else {
        printf("-- Orthogonality is CORRECT ! \n");
        info_ortho=0;
    }

    free(work); free(Id);

    return info_ortho;
}

/*------------------------------------------------------------
 *  Check the factorization QR
 */

int d_check_QRfactorization(int M, int N, double *A1, double *A2, int LDA, double *Q)
{
    double Anorm, Rnorm;
    double alpha, beta;
    int info_factorization;
    int i,j;
    double eps;

    eps = LAPACKE_dlamch_work('e');

    double *Ql       = (double *)malloc(M*N*sizeof(double));
    double *Residual = (double *)malloc(M*N*sizeof(double));
    double *work              = (double *)malloc(max(M,N)*sizeof(double));

    alpha=1.0;
    beta=0.0;

    if (M >= N) {
        /* Extract the R */
        double *R = (double *)malloc(N*N*sizeof(double));
        memset((void*)R, 0, N*N*sizeof(double));
        LAPACKE_dlacpy_work(LAPACK_COL_MAJOR,'u', M, N, A2, LDA, R, N);

        /* Perform Ql=Q*R */
        memset((void*)Ql, 0, M*N*sizeof(double));
        cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, M, N, N, (alpha), Q, LDA, R, N, (beta), Ql, M);
        free(R);
    }
    else {
        /* Extract the L */
        double *L = (double *)malloc(M*M*sizeof(double));
        memset((void*)L, 0, M*M*sizeof(double));
        LAPACKE_dlacpy_work(LAPACK_COL_MAJOR,'l', M, N, A2, LDA, L, M);

    /* Perform Ql=LQ */
        memset((void*)Ql, 0, M*N*sizeof(double));
        cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, M, N, M, (alpha), L, M, Q, LDA, (beta), Ql, M);
        free(L);
    }

    /* Compute the Residual */
    for (i = 0; i < M; i++)
        for (j = 0 ; j < N; j++)
            Residual[j*M+i] = A1[j*LDA+i]-Ql[j*M+i];

    Rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Residual, M, work);
    Anorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, A2, LDA, work);

    if (M >= N) {
        printf("============\n");
        printf("Checking the QR Factorization \n");
        printf("-- ||A-QR||_oo/(||A||_oo.N.eps) = %e \n",Rnorm/(Anorm*N*eps));
    }
    else {
        printf("============\n");
        printf("Checking the LQ Factorization \n");
        printf("-- ||A-LQ||_oo/(||A||_oo.N.eps) = %e \n",Rnorm/(Anorm*N*eps));
    }

    if (isnan(Rnorm / (Anorm * N *eps)) || (Rnorm / (Anorm * N * eps) > 10.0) ) {
        printf("-- Factorization is suspicious ! \n");
        info_factorization = 1;
    }
    else {
        printf("-- Factorization is CORRECT ! \n");
        info_factorization = 0;
    }

    free(work); free(Ql); free(Residual);

    return info_factorization;
}

/*------------------------------------------------------------------------
 *  Check the factorization of the matrix A2
 */

int d_check_LLTfactorization(int N, double *A1, double *A2, int LDA, int uplo)
{
    double Anorm, Rnorm;
    double alpha;
    int info_factorization;
    int i,j;
    double eps;

    eps = LAPACKE_dlamch_work('e');

    double *Residual = (double *)malloc(N*N*sizeof(double));
    double *L1       = (double *)malloc(N*N*sizeof(double));
    double *L2       = (double *)malloc(N*N*sizeof(double));
    double *work              = (double *)malloc(N*sizeof(double));

    memset((void*)L1, 0, N*N*sizeof(double));
    memset((void*)L2, 0, N*N*sizeof(double));

    alpha= 1.0;

    LAPACKE_dlacpy_work(LAPACK_COL_MAJOR,' ', N, N, A1, LDA, Residual, N);

    /* Dealing with L'L or U'U  */
    if (uplo == MorseUpper){
        LAPACKE_dlacpy_work(LAPACK_COL_MAJOR,'u', N, N, A2, LDA, L1, N);
        LAPACKE_dlacpy_work(LAPACK_COL_MAJOR,'u', N, N, A2, LDA, L2, N);
        cblas_dtrmm(CblasColMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit, N, N, (alpha), L1, N, L2, N);
    }
    else{
        LAPACKE_dlacpy_work(LAPACK_COL_MAJOR,'l', N, N, A2, LDA, L1, N);
        LAPACKE_dlacpy_work(LAPACK_COL_MAJOR,'l', N, N, A2, LDA, L2, N);
        cblas_dtrmm(CblasColMajor, CblasRight, CblasLower, CblasTrans, CblasNonUnit, N, N, (alpha), L1, N, L2, N);
    }

    /* Compute the Residual || A -L'L|| */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
           Residual[j*N+i] = L2[j*N+i] - Residual[j*N+i];

    Rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, N, Residual, N, work);
    Anorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, N, A1, LDA, work);

    printf("============\n");
    printf("Checking the Cholesky Factorization \n");
    printf("-- ||L'L-A||_oo/(||A||_oo.N.eps) = %e \n",Rnorm/(Anorm*N*eps));

    if ( isnan(Rnorm/(Anorm*N*eps)) || (Rnorm/(Anorm*N*eps) > 10.0) ){
        printf("-- Factorization is suspicious ! \n");
        info_factorization = 1;
    }
    else{
        printf("-- Factorization is CORRECT ! \n");
        info_factorization = 0;
    }

    free(Residual); free(L1); free(L2); free(work);

    return info_factorization;
}

/*--------------------------------------------------------------
 * Check the gemm
 */
double d_check_gemm(MORSE_enum transA, MORSE_enum transB, int M, int N, int K,
                   double alpha, double *A, int LDA,
                   double *B, int LDB,
                   double beta, double *Cmorse,
                   double *Cref, int LDC,
                   double *Cinitnorm, double *Cmorsenorm, double *Clapacknorm )
{
    double beta_const = -1.0;
    double Rnorm;
    double *work = (double *)malloc(max(K,max(M, N))* sizeof(double));

    *Cinitnorm   = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cref,    LDC, work);
    *Cmorsenorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cmorse, LDC, work);

    cblas_dgemm(CblasColMajor, (CBLAS_TRANSPOSE)transA, (CBLAS_TRANSPOSE)transB, M, N, K,
                (alpha), A, LDA, B, LDB, (beta), Cref, LDC);

    *Clapacknorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cref, LDC, work);

    cblas_daxpy(LDC * N, (beta_const), Cmorse, 1, Cref, 1);

    Rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cref, LDC, work);

    free(work);

    return Rnorm;
}

/*--------------------------------------------------------------
 * Check the trsm
 */
double d_check_trsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum trans, MORSE_enum diag,
                   int M, int NRHS, double alpha,
                   double *A, int LDA,
                   double *Bmorse, double *Bref, int LDB,
                   double *Binitnorm, double *Bmorsenorm, double *Blapacknorm )
{
    double beta_const = -1.0;
    double Rnorm;
    double *work = (double *)malloc(max(M, NRHS)* sizeof(double));
    /*double eps = LAPACKE_dlamch_work('e');*/

    *Binitnorm   = LAPACKE_dlange_work(LAPACK_COL_MAJOR, 'i', M, NRHS, Bref,    LDB, work);
    *Bmorsenorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, 'i', M, NRHS, Bmorse, LDB, work);

    cblas_dtrsm(CblasColMajor, (CBLAS_SIDE)side, (CBLAS_UPLO)uplo,
                (CBLAS_TRANSPOSE)trans, (CBLAS_DIAG)diag, M, NRHS,
                (alpha), A, LDA, Bref, LDB);

    *Blapacknorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, 'i', M, NRHS, Bref, LDB, work);

    cblas_daxpy(LDB * NRHS, (beta_const), Bmorse, 1, Bref, 1);

    Rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, 'i', M, NRHS, Bref, LDB, work);
    Rnorm = Rnorm / *Blapacknorm;
    /* max(M,NRHS) * eps);*/

    free(work);

    return Rnorm;
}

/*--------------------------------------------------------------
 * Check the solution
 */

double d_check_solution(int M, int N, int NRHS, double *A, int LDA,
                      double *B,  double *X, int LDB,
                      double *anorm, double *bnorm, double *xnorm )
{
/*     int info_solution; */
    double Rnorm = -1.00;
    double zone  =  1.0;
    double mzone = -1.0;
    double *work = (double *)malloc(max(M, N)* sizeof(double));

    *anorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N,    A, LDA, work);
    *xnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, NRHS, X, LDB, work);
    *bnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, NRHS, B, LDB, work);

    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, M, NRHS, N, (zone), A, LDA, X, LDB, (mzone), B, LDB);

    Rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, NRHS, B, LDB, work);

    free(work);

    return Rnorm;
}

/*------------------------------------------------------------------------
 *  *  Check the accuracy of the computed inverse
 *   */

int dcheck_inverse(int N, double *A1, double *A2, int LDA,
                        MORSE_enum uplo, double *rnorm, double *anorm, double *ainvnorm )
{
    int info_inverse;
    int i, j;
    double result;
    double alpha, beta, zone;
    double *workz = (double *)malloc(N*N*sizeof(double));
    double *workd = (double *)malloc(N*sizeof(double));
    double eps;

    eps = LAPACKE_dlamch_work('e');

    alpha = -1.0;
    beta  = 0.0;
    zone = 1.0;

    /* Rebuild the other part of the inverse matrix */
    if(uplo == MorseUpper){
       for(j=0; j<N; j++)
          for(i=0; i<j; i++)
             *(A2+j+i*LDA) = *(A2+i+j*LDA);
       cblas_dsymm(CblasColMajor, CblasLeft, CblasUpper, N, N, (alpha), A2, LDA, A1, LDA, (beta), workz, N);

    }
    else {
       for(j=0; j<N; j++)
          for(i=j; i<N; i++)
             *(A2+j+i*LDA) = *(A2+i+j*LDA);
       cblas_dsymm(CblasColMajor, CblasLeft, CblasLower, N, N, (alpha), A2, LDA, A1, LDA, (beta), workz, N);
    }

    /* Add the identity matrix to workz */
     for(i=0; i<N; i++)
        *(workz+i+i*N) = *(workz+i+i*N) + zone;


    *rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseOneNorm), N, N,    workz, N, workd);
    *anorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseOneNorm), N, N, A1, LDA, workd);
    *ainvnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseOneNorm), N, N, A2, LDA, workd);


      result = *rnorm / ( ((*anorm) * (*ainvnorm))*N*eps ) ;

    if (  isnan(*ainvnorm) || isinf(*ainvnorm) || isnan(result) || isinf(result) || (result > 60.0) ) {
        info_inverse = 1;
     }
    else{
        info_inverse = 0;
    }

    free(workz);
    free(workd);

    return info_inverse;
}
