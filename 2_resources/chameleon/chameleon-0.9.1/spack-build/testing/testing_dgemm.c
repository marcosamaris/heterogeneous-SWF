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
 * @file testing_dgemm.c
 *
 *  MORSE testing routines
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
 * @generated d Tue Sep 26 20:43:20 2017
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
#include "testing_dauxiliary.h"
#if defined(CHAMELEON_USE_MPI)
#include <mpi.h>
#endif

#undef COMPLEX
#define REAL

static int check_solution(MORSE_enum transA, MORSE_enum transB, int M, int N, int K,
                          double alpha, double *A, int LDA,
                          double *B, int LDB,
                          double beta, double *Cref, double *Cmorse, int LDC);

int testing_dgemm(int argc, char **argv)
{
    int hres = 0;
    /* Check for number of arguments*/
    if ( argc < 8) {
        USAGE("GEMM", "alpha beta M N K LDA LDB LDC",
              "   - alpha  : alpha coefficient\n"
              "   - beta   : beta coefficient\n"
              "   - M      : number of rows of matrices A and C\n"
              "   - N      : number of columns of matrices B and C\n"
              "   - K      : number of columns of matrix A / number of rows of matrix B\n"
              "   - LDA    : leading dimension of matrix A\n"
              "   - LDB    : leading dimension of matrix B\n"
              "   - LDC    : leading dimension of matrix C\n");
        return -1;
    }

    double alpha = (double) atol(argv[0]);
    double beta = (double) atol(argv[1]);
    int M     = atoi(argv[2]);
    int N     = atoi(argv[3]);
    int K     = atoi(argv[4]);
    int LDA   = atoi(argv[5]);
    int LDB   = atoi(argv[6]);
    int LDC   = atoi(argv[7]);

    double eps;
    int info_solution;
    int i, j, ta, tb;
    int LDAxK = LDA*max(M,K);
    int LDBxN = LDB*max(K,N);
    int LDCxN = LDC*N;

    double *A      = (double *)malloc(LDAxK*sizeof(double));
    double *B      = (double *)malloc(LDBxN*sizeof(double));
    double *C      = (double *)malloc(LDCxN*sizeof(double));
    double *Cinit  = (double *)malloc(LDCxN*sizeof(double));
    double *Cfinal = (double *)malloc(LDCxN*sizeof(double));

    /* Check if unable to allocate memory */
    if ((!A)||(!B)||(!Cinit)||(!Cfinal)){
        printf("Out of Memory \n ");
        return -2;
    }

    eps = LAPACKE_dlamch_work('e');

    if (MORSE_My_Mpi_Rank() == 0){
        printf("\n");
        printf("------ TESTS FOR CHAMELEON DGEMM ROUTINE -------  \n");
        printf("            Size of the Matrix %d by %d\n", M, N);
        printf("\n");
        printf(" The matrix A is randomly generated for each test.\n");
        printf("============\n");
        printf(" The relative machine precision (eps) is to be %e \n",eps);
        printf(" Computational tests pass if scaled residuals are less than 10.\n");
    }

    /*----------------------------------------------------------
     *  TESTING DGEMM
     */

    /* Initialize A, B, C */
    LAPACKE_dlarnv_work(IONE, ISEED, LDAxK, A);
    LAPACKE_dlarnv_work(IONE, ISEED, LDBxN, B);
    LAPACKE_dlarnv_work(IONE, ISEED, LDCxN, C);

#ifdef COMPLEX
    for (ta=0; ta<3; ta++) {
        for (tb=0; tb<3; tb++) {
#else
    for (ta=0; ta<2; ta++) {
        for (tb=0; tb<2; tb++) {
#endif
            for ( i = 0; i < M; i++)
                for (  j = 0; j < N; j++)
                    Cinit[LDC*j+i] = C[LDC*j+i];
            for ( i = 0; i < M; i++)
                for (  j = 0; j < N; j++)
                    Cfinal[LDC*j+i] = C[LDC*j+i];

            /* MORSE DGEMM */
            MORSE_dgemm(trans[ta], trans[tb], M, N, K, alpha, A, LDA, B, LDB, beta, Cfinal, LDC);

            /* Check the solution */
            info_solution = check_solution(trans[ta], trans[tb], M, N, K,
                                           alpha, A, LDA, B, LDB, beta, Cinit, Cfinal, LDC);
            if (MORSE_My_Mpi_Rank() == 0){
                if (info_solution == 0) {
                    printf("***************************************************\n");
                    printf(" ---- TESTING DGEMM (%s, %s) ............... PASSED !\n", transstr[ta], transstr[tb]);
                    printf("***************************************************\n");
                }
                else {
                    printf("************************************************\n");
                    printf(" - TESTING DGEMM (%s, %s) ... FAILED !\n", transstr[ta], transstr[tb]);    hres++;
                    printf("************************************************\n");
                }
            }
        }
    }
#ifdef _UNUSED_
    }}
#endif
    free(A); free(B); free(C);
    free(Cinit); free(Cfinal);

    return hres;
}

/*--------------------------------------------------------------
 * Check the solution
 */

static int check_solution(MORSE_enum transA, MORSE_enum transB, int M, int N, int K,
                          double alpha, double *A, int LDA,
                          double *B, int LDB,
                          double beta, double *Cref, double *Cmorse, int LDC)
{
    int info_solution;
    double Anorm, Bnorm, Cinitnorm, Cmorsenorm, Clapacknorm, Rnorm, result;
    double eps;
    double beta_const;

    double *work = (double *)malloc(max(K,max(M, N))* sizeof(double));
    int Am, An, Bm, Bn;

    beta_const  = -1.0;

    if (transA == MorseNoTrans) {
        Am = M; An = K;
    } else {
        Am = K; An = M;
    }
    if (transB == MorseNoTrans) {
        Bm = K; Bn = N;
    } else {
        Bm = N; Bn = K;
    }

    Anorm       = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), Am, An, A,       LDA, work);
    Bnorm       = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), Bm, Bn, B,       LDB, work);
    Cinitnorm   = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M,  N,  Cref,    LDC, work);
    Cmorsenorm  = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M,  N,  Cmorse, LDC, work);

    cblas_dgemm(CblasColMajor, (CBLAS_TRANSPOSE)transA, (CBLAS_TRANSPOSE)transB, M, N, K, 
                (alpha), A, LDA, B, LDB, (beta), Cref, LDC);

    Clapacknorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cref, LDC, work);

    cblas_daxpy(LDC * N, (beta_const), Cmorse, 1, Cref, 1);

    Rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cref, LDC, work);

    eps = LAPACKE_dlamch_work('e');
    if (MORSE_My_Mpi_Rank() == 0)
        printf("Rnorm %e, Anorm %e, Bnorm %e, Cinitnorm %e, Cmorsenorm %e, Clapacknorm %e\n",
               Rnorm, Anorm, Bnorm, Cinitnorm, Cmorsenorm, Clapacknorm);

    result = Rnorm / ((Anorm + Bnorm + Cinitnorm) * N * eps);
    if (MORSE_My_Mpi_Rank() == 0){
        printf("============\n");
        printf("Checking the norm of the difference against reference DGEMM \n");
        printf("-- ||Cmorse - Clapack||_oo/((||A||_oo+||B||_oo+||C||_oo).N.eps) = %e \n",
               result);
    }

    if (  isnan(Rnorm) || isinf(Rnorm) || isnan(result) || isinf(result) || (result > 10.0) ) {
         if (MORSE_My_Mpi_Rank() == 0)
             printf("-- The solution is suspicious ! \n");
         info_solution = 1;
    }
    else {
    	 //printf("MORSE_My_Mpi_Rank() : %d\n",MORSE_My_Mpi_Rank());
         if (MORSE_My_Mpi_Rank() == 0)
             printf("-- The solution is CORRECT ! \n");
         info_solution= 0 ;
    }

    free(work);

    return info_solution;
}
