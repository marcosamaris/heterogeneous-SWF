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
 * @file testing_dsymm.c
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

static int check_solution(MORSE_enum transA, MORSE_enum transB, int M, int N,
                          double alpha, double *A, int LDA,
                          double *B, int LDB,
                          double beta, double *Cref, double *Cmorse, int LDC);

int testing_dsymm(int argc, char **argv)
{
    int hres = 0;
    /* Check for number of arguments*/
    if ( argc != 7 ){
        USAGE("SYMM", "alpha beta M N K LDA LDB LDC",
              "   - alpha : alpha coefficient \n"
              "   - beta : beta coefficient \n"
              "   - M : number of rows of matrices A and C \n"
              "   - N : number of columns of matrices B and C \n"
              "   - LDA : leading dimension of matrix A \n"
              "   - LDB : leading dimension of matrix B \n"
              "   - LDC : leading dimension of matrix C\n");
        return -1;
    }

    double alpha = (double) atol(argv[0]);
    double beta  = (double) atol(argv[1]);
    int M     = atoi(argv[2]);
    int N     = atoi(argv[3]);
    int LDA   = atoi(argv[4]);
    int LDB   = atoi(argv[5]);
    int LDC   = atoi(argv[6]);
    int MNmax = max(M, N);

    double eps;
    int info_solution;
    int i, j, s, u;
    int LDAxM = LDA*MNmax;
    int LDBxN = LDB*N;
    int LDCxN = LDC*N;

    double *A      = (double *)malloc(LDAxM*sizeof(double));
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

    printf("\n");
    printf("------ TESTS FOR CHAMELEON DSYMM ROUTINE -------  \n");
    printf("            Size of the Matrix %d by %d\n", M, N);
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf("============\n");
    printf(" The relative machine precision (eps) is to be %e \n",eps);
    printf(" Computational tests pass if scaled residuals are less than 10.\n");

    /*----------------------------------------------------------
    *  TESTING DSYMM
    */

    /* Initialize A */
    MORSE_dplgsy( (double)0., MNmax, A, LDA, 51 );

    /* Initialize B */
    LAPACKE_dlarnv_work(IONE, ISEED, LDBxN, B);

    /* Initialize C */
    LAPACKE_dlarnv_work(IONE, ISEED, LDCxN, C);

    for (s=0; s<2; s++) {
        for (u=0; u<2; u++) {

            /* Initialize  Cinit / Cfinal */
            for ( i = 0; i < M; i++)
                for (  j = 0; j < N; j++)
                    Cinit[LDC*j+i] = C[LDC*j+i];
            for ( i = 0; i < M; i++)
                for (  j = 0; j < N; j++)
                    Cfinal[LDC*j+i] = C[LDC*j+i];

            /* MORSE DSYMM */
            MORSE_dsymm(side[s], uplo[u], M, N, alpha, A, LDA, B, LDB, beta, Cfinal, LDC);

            /* Check the solution */
            info_solution = check_solution(side[s], uplo[u], M, N, alpha, A, LDA, B, LDB, beta, Cinit, Cfinal, LDC);

            if (info_solution == 0) {
                printf("***************************************************\n");
                printf(" ---- TESTING DSYMM (%5s, %5s) ....... PASSED !\n", sidestr[s], uplostr[u]);
                printf("***************************************************\n");
            }
            else {
                printf("************************************************\n");
                printf(" - TESTING DSYMM (%s, %s) ... FAILED !\n", sidestr[s], uplostr[u]);    hres++;
                printf("************************************************\n");
            }
        }
    }

    free(A); free(B); free(C);
    free(Cinit); free(Cfinal);

    return hres;
}

/*--------------------------------------------------------------
 * Check the solution
 */

static int check_solution(MORSE_enum side, MORSE_enum uplo, int M, int N,
                   double alpha, double *A, int LDA,
                   double *B, int LDB,
                   double beta, double *Cref, double *Cmorse, int LDC)
{
    int info_solution, NrowA;
    double Anorm, Bnorm, Cinitnorm, Cmorsenorm, Clapacknorm, Rnorm;
    double eps;
    double beta_const;
    double result;
    double *work = (double *)malloc(max(M, N)* sizeof(double));

    beta_const  = (double)-1.0;

    NrowA = (side == MorseLeft) ? M : N;
    Anorm       = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), NrowA, NrowA, A,       LDA, work);
    Bnorm       = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M,     N,     B,       LDB, work);
    Cinitnorm   = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M,     N,     Cref,    LDC, work);
    Cmorsenorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M,     N,     Cmorse, LDC, work);

    cblas_dsymm(CblasColMajor, (CBLAS_SIDE)side, (CBLAS_UPLO)uplo, M, N, (alpha), A, LDA, B, LDB, (beta), Cref, LDC);

    Clapacknorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cref, LDC, work);

    cblas_daxpy(LDC * N, (beta_const), Cmorse, 1, Cref, 1);

    Rnorm = LAPACKE_dlange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Cref, LDC, work);

    eps = LAPACKE_dlamch_work('e');

    printf("Rnorm %e, Anorm %e, Bnorm %e, Cinitnorm %e, Cmorsenorm %e, Clapacknorm %e\n",Rnorm,Anorm,Bnorm,Cinitnorm,Cmorsenorm,Clapacknorm);

    result = Rnorm / ((Anorm + Bnorm + Cinitnorm) * N * eps);

    printf("============\n");
    printf("Checking the norm of the difference against reference DSYMM \n");
    printf("-- ||Cmorse - Clapack||_oo/((||A||_oo+||B||_oo+||C||_oo).N.eps) = %e \n", result );

    if ( isinf(Clapacknorm) || isinf(Cmorsenorm) || isnan(result) || isinf(result) || (result > 10.0) ) {
        printf("-- The solution is suspicious ! \n");
        info_solution = 1;
    }
    else {
        printf("-- The solution is CORRECT ! \n");
        info_solution= 0 ;
    }
    free(work);
    return info_solution;
}
