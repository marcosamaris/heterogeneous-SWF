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
 * @file testing_sposv.c
 *
 *  MORSE testing routines
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Bilel Hadri, Hatem Ltaief
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated s Tue Sep 26 20:43:21 2017
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
#include "testing_sauxiliary.h"

enum blas_order_type {
            blas_rowmajor = 101,
            blas_colmajor = 102 };

enum blas_cmach_type {
            blas_base      = 151,
            blas_t         = 152,
            blas_rnd       = 153,
            blas_ieee      = 154,
            blas_emin      = 155,
            blas_emax      = 156,
            blas_eps       = 157,
            blas_prec      = 158,
            blas_underflow = 159,
            blas_overflow  = 160,
            blas_sfmin     = 161};

enum blas_norm_type {
            blas_one_norm       = 171,
            blas_real_one_norm  = 172,
            blas_two_norm       = 173,
            blas_frobenius_norm = 174,
            blas_inf_norm       = 175,
            blas_real_inf_norm  = 176,
            blas_max_norm       = 177,
            blas_real_max_norm  = 178 };

static void
BLAS_error(char *rname, int err, int val, int x) {
  fprintf( stderr, "%s %d %d %d\n", rname, err, val, x );
  abort();
}

static
void
BLAS_sge_norm(enum blas_order_type order, enum blas_norm_type norm,
  int m, int n, const float *a, int lda, float *res) {
  int i, j; float anorm, v;
  char rname[] = "BLAS_sge_norm";

  if (order != blas_colmajor) BLAS_error( rname, -1, order, 0 );

  if (norm == blas_frobenius_norm) {
    anorm = 0.0f;
    for (j = n; j; --j) {
      for (i = m; i; --i) {
        v = a[0];
        anorm += v * v;
        a++;
      }
      a += lda - m;
    }
    anorm = sqrt( anorm );
  } else if (norm == blas_inf_norm) {
    anorm = 0.0f;
    for (i = 0; i < m; ++i) {
      v = 0.0f;
      for (j = 0; j < n; ++j) {
        v += fabsf( a[i + j * lda] );
      }
      if (v > anorm)
        anorm = v;
    }
  } else {
    BLAS_error( rname, -2, norm, 0 );
    return;
  }

  if (res) *res = anorm;
}

static
float
BLAS_spow_di(float x, int n) {
  float rv = 1.0;

  if (n < 0) {
    n = -n;
    x = 1.0 / x;
  }

  for (; n; n >>= 1, x *= x) {
    if (n & 1)
      rv *= x;
  }

  return rv;
}

static
float
BLAS_sfpinfo(enum blas_cmach_type cmach) {
  float eps = 1.0, r = 1.0, o = 1.0, b = 2.0;
  int t = 53, l = 1024, m = -1021;
  char rname[] = "BLAS_sfpinfo";

  if ((sizeof eps) == sizeof(float)) {
    t = 24;
    l = 128;
    m = -125;
  } else {
    t = 53; 
    l = 1024;
    m = -1021;
  }

  /* for (i = 0; i < t; ++i) eps *= half; */
  eps = BLAS_spow_di( b, -t );
  /* for (i = 0; i >= m; --i) r *= half; */
  r = BLAS_spow_di( b, m-1 );

  o -= eps;
  /* for (i = 0; i < l; ++i) o *= b; */
  o = (o * BLAS_spow_di( b, l-1 )) * b;

  switch (cmach) {
    case blas_eps: return eps;
    case blas_sfmin: return r;
    default:
      BLAS_error( rname, -1, cmach, 0 );
      break;
  }
  return 0.0;
}

static int check_factorization(int, float*, float*, int, int , float);
static int check_solution(int, int, float*, int, float*, float*, int, float);

int testing_sposv(int argc, char **argv)
{
    int hres = 0;

    /* Check for number of arguments*/
    if (argc != 4){
        USAGE("POSV", "N LDA NRHS LDB",
              "   - N    : the size of the matrix\n"
              "   - LDA  : leading dimension of the matrix A\n"
              "   - NRHS : number of RHS\n"
              "   - LDB  : leading dimension of the RHS B\n");
        return -1;
    }

    int N     = atoi(argv[0]);
    int LDA   = atoi(argv[1]);
    int NRHS  = atoi(argv[2]);
    int LDB   = atoi(argv[3]);
    float eps;
    int uplo;
    int info_solution, info_factorization;
    int trans1, trans2;

    float *A1   = (float *)malloc(LDA*N*sizeof(float));
    float *A2   = (float *)malloc(LDA*N*sizeof(float));
    float *B1   = (float *)malloc(LDB*NRHS*sizeof(float));
    float *B2   = (float *)malloc(LDB*NRHS*sizeof(float));

    /* Check if unable to allocate memory */
    if ((!A1)||(!A2)||(!B1)||(!B2)){
        printf("Out of Memory \n ");
        return -2;
    }

    eps = BLAS_sfpinfo( blas_eps );

    uplo = MorseUpper;
    trans1 = uplo == MorseUpper ? MorseTrans : MorseNoTrans;
    trans2 = uplo == MorseUpper ? MorseNoTrans : MorseTrans;
    
    /*-------------------------------------------------------------
    *  TESTING SPOSV
    */

    /* Initialize A1 and A2 for Symmetric Positif Matrix */
    MORSE_splgsy( (float)N, N, A1, LDA, 51 );
    MORSE_slacpy( MorseUpperLower, N, N, A1, LDA, A2, LDA );

    /* Initialize B1 and B2 */
    MORSE_splrnt( N, NRHS, B1, LDB, 371 );
    MORSE_slacpy( MorseUpperLower, N, NRHS, B1, LDB, B2, LDB );

    printf("\n");
    printf("------ TESTS FOR CHAMELEON SPOSV ROUTINE -------  \n");
    printf("            Size of the Matrix %d by %d\n", N, N);
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf("============\n");
    printf(" The relative machine precision (eps) is to be %e \n", eps);
    printf(" Computational tests pass if scaled residuals are less than 60.\n");

    /* MORSE SPOSV */
    MORSE_sposv(uplo, N, NRHS, A2, LDA, B2, LDB);

    /* Check the factorization and the solution */
    info_factorization = check_factorization( N, A1, A2, LDA, uplo, eps);
    info_solution = check_solution(N, NRHS, A1, LDA, B1, B2, LDB, eps);

    if ( (info_solution == 0) && (info_factorization == 0) ) {
        printf("***************************************************\n");
        printf(" ---- TESTING SPOSV ...................... PASSED !\n");
        printf("***************************************************\n");
    }
    else {
        printf("***************************************************\n");
        printf(" - TESTING SPOSV ... FAILED !\n");    hres++;
        printf("***************************************************\n");
    }

    /*-------------------------------------------------------------
    *  TESTING SPOTRF + SPOTRS
    */

    /* Initialize A1 and A2 for Symmetric Positif Matrix */
    MORSE_splgsy( (float)N, N, A1, LDA, 51 );
    MORSE_slacpy( MorseUpperLower, N, N, A1, LDA, A2, LDA );

    /* Initialize B1 and B2 */
    MORSE_splrnt( N, NRHS, B1, LDB, 371 );
    MORSE_slacpy( MorseUpperLower, N, NRHS, B1, LDB, B2, LDB );

    /* Morse routines */
    MORSE_spotrf(uplo, N, A2, LDA);
    MORSE_spotrs(uplo, N, NRHS, A2, LDA, B2, LDB);

    printf("\n");
    printf("------ TESTS FOR CHAMELEON SPOTRF + SPOTRS ROUTINE -------  \n");
    printf("            Size of the Matrix %d by %d\n", N, N);
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf("============\n");
    printf(" The relative machine precision (eps) is to be %e \n", eps);
    printf(" Computational tests pass if scaled residuals are less than 60.\n");

    /* Check the factorization and the solution */
    info_factorization = check_factorization( N, A1, A2, LDA, uplo, eps);
    info_solution = check_solution(N, NRHS, A1, LDA, B1, B2, LDB, eps);

    if ((info_solution == 0)&(info_factorization == 0)){
        printf("***************************************************\n");
        printf(" ---- TESTING SPOTRF + SPOTRS ............ PASSED !\n");
        printf("***************************************************\n");
    }
    else{
        printf("****************************************************\n");
        printf(" - TESTING SPOTRF + SPOTRS ... FAILED !\n");
        printf("****************************************************\n");
    }

    /*-------------------------------------------------------------
    *  TESTING SPOTRF + ZPTRSM + STRSM
    */

    /* Initialize A1 and A2 for Symmetric Positif Matrix */
    MORSE_splgsy( (float)N, N, A1, LDA, 51 );
    MORSE_slacpy( MorseUpperLower, N, N, A1, LDA, A2, LDA );

    /* Initialize B1 and B2 */
    MORSE_splrnt( N, NRHS, B1, LDB, 371 );
    MORSE_slacpy( MorseUpperLower, N, NRHS, B1, LDB, B2, LDB );

    /* MORSE routines */
    MORSE_spotrf(uplo, N, A2, LDA);
    MORSE_strsm(MorseLeft, uplo, trans1, MorseNonUnit, 
                 N, NRHS, 1.0, A2, LDA, B2, LDB);
    MORSE_strsm(MorseLeft, uplo, trans2, MorseNonUnit, 
                 N, NRHS, 1.0, A2, LDA, B2, LDB);

    printf("\n");
    printf("------ TESTS FOR CHAMELEON SPOTRF + STRSM + STRSM  ROUTINE -------  \n");
    printf("            Size of the Matrix %d by %d\n", N, N);
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf("============\n");
    printf(" The relative machine precision (eps) is to be %e \n", eps);
    printf(" Computational tests pass if scaled residuals are less than 60.\n");

    /* Check the factorization and the solution */
    info_factorization = check_factorization( N, A1, A2, LDA, uplo, eps);
    info_solution = check_solution(N, NRHS, A1, LDA, B1, B2, LDB, eps);

    if ((info_solution == 0)&(info_factorization == 0)){
        printf("***************************************************\n");
        printf(" ---- TESTING SPOTRF + STRSM + STRSM ..... PASSED !\n");
        printf("***************************************************\n");
    }
    else{
        printf("***************************************************\n");
        printf(" - TESTING SPOTRF + STRSM + STRSM ... FAILED !\n");
        printf("***************************************************\n");
    }

    free(A1); free(A2); free(B1); free(B2); 

    return hres;
}


/*------------------------------------------------------------------------
 *  Check the factorization of the matrix A2
 */
static int check_factorization(int N, float *A1, float *A2, int LDA, int uplo, float eps)
{
    float Anorm, Rnorm;
    float alpha;
    int info_factorization;
    int i,j;

    float *Residual = (float *)malloc(N*N*sizeof(float));
    float *L1       = (float *)malloc(N*N*sizeof(float));
    float *L2       = (float *)malloc(N*N*sizeof(float));
    float *work              = (float *)malloc(N*sizeof(float));

    memset((void*)L1, 0, N*N*sizeof(float));
    memset((void*)L2, 0, N*N*sizeof(float));

    alpha= 1.0;

    LAPACKE_slacpy_work(LAPACK_COL_MAJOR,' ', N, N, A1, LDA, Residual, N);

    /* Dealing with L'L or U'U  */
    if (uplo == MorseUpper){
        LAPACKE_slacpy_work(LAPACK_COL_MAJOR,'u', N, N, A2, LDA, L1, N);
        LAPACKE_slacpy_work(LAPACK_COL_MAJOR,'u', N, N, A2, LDA, L2, N);
        cblas_strmm(CblasColMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit, N, N, (alpha), L1, N, L2, N);
    }
    else{
        LAPACKE_slacpy_work(LAPACK_COL_MAJOR,'l', N, N, A2, LDA, L1, N);
        LAPACKE_slacpy_work(LAPACK_COL_MAJOR,'l', N, N, A2, LDA, L2, N);
        cblas_strmm(CblasColMajor, CblasRight, CblasLower, CblasTrans, CblasNonUnit, N, N, (alpha), L1, N, L2, N);
    }

    /* Compute the Residual || A -L'L|| */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
           Residual[j*N+i] = L2[j*N+i] - Residual[j*N+i];

    BLAS_sge_norm( blas_colmajor, blas_inf_norm, N, N, Residual, N, &Rnorm );
    BLAS_sge_norm( blas_colmajor, blas_inf_norm, N, N, A1, LDA, &Anorm );

    printf("============\n");
    printf("Checking the Cholesky Factorization \n");
    printf("-- ||L'L-A||_oo/(||A||_oo.N.eps) = %e \n",Rnorm/(Anorm*N*eps));

    if ( isnan(Rnorm/(Anorm*N*eps)) || isinf(Rnorm/(Anorm*N*eps)) || (Rnorm/(Anorm*N*eps) > 60.0) ){
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


/*------------------------------------------------------------------------
 *  Check the accuracy of the solution of the linear system
 */

static int check_solution(int N, int NRHS, float *A1, int LDA, float *B1, float *B2, int LDB, float eps )
{
    int info_solution;
    float Rnorm, Anorm, Xnorm, Bnorm, result;
    float alpha, beta;
    float *work = (float *)malloc(N*sizeof(float));

    alpha = 1.0;
    beta  = -1.0;

    BLAS_sge_norm( blas_colmajor, blas_inf_norm, N, NRHS, B2, LDB, &Xnorm );
    BLAS_sge_norm( blas_colmajor, blas_inf_norm, N, N,    A1, LDA, &Anorm );
    BLAS_sge_norm( blas_colmajor, blas_inf_norm, N, NRHS, B1, LDB, &Bnorm );

    cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, N, NRHS, N, (alpha), A1, LDA, B2, LDB, (beta), B1, LDB);
    BLAS_sge_norm( blas_colmajor, blas_inf_norm, N, NRHS, B1, LDB, &Rnorm );

    if (getenv("MORSE_TESTING_VERBOSE"))
      printf( "||A||_oo=%f\n||X||_oo=%f\n||B||_oo=%f\n||A X - B||_oo=%e\n", Anorm, Xnorm, Bnorm, Rnorm );

    result = Rnorm / ( (Anorm*Xnorm+Bnorm)*N*eps ) ;
    printf("============\n");
    printf("Checking the Residual of the solution \n");
    printf("-- ||Ax-B||_oo/((||A||_oo||x||_oo+||B||_oo).N.eps) = %e \n", result);

    if (  isnan(Xnorm) || isinf(Xnorm) || isnan(result) || isinf(result) || (result > 60.0) ) {
        printf("-- The solution is suspicious ! \n");
        info_solution = 1;
     }
    else{
        printf("-- The solution is CORRECT ! \n");
        info_solution = 0;
    }

    free(work);

    return info_solution;
}