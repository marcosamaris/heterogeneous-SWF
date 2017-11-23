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
 * @file testing_ssyrk.c
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
 * @generated s Tue Sep 26 20:43:20 2017
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

static int check_solution(MORSE_enum uplo, MORSE_enum trans, int N, int K,
                          float alpha, float *A, int LDA,
                          float beta,  float *Cref, float *Cmorse, int LDC);


int testing_ssyrk(int argc, char **argv)
{
    int hres = 0;
    /* Check for number of arguments*/
    if ( argc != 6){
        USAGE("SYRK", "alpha beta M N LDA LDC",
              "   - alpha : alpha coefficient\n"
              "   - beta : beta coefficient\n"
              "   - N : number of columns and rows of matrix C and number of row of matrix A\n"
              "   - K : number of columns of matrix A\n"
              "   - LDA : leading dimension of matrix A\n"
              "   - LDC : leading dimension of matrix C\n");
        return -1;
    }

    float alpha = (float) atol(argv[0]);
    float beta  = (float) atol(argv[1]);
    int N     = atoi(argv[2]);
    int K     = atoi(argv[3]);
    int LDA   = atoi(argv[4]);
    int LDC   = atoi(argv[5]);
    int NKmax = max(N, K);

    float eps;
    int info_solution;
    int u, t;
    size_t LDAxK = LDA*NKmax;
    size_t LDCxN = LDC*N;

    float *A      = (float *)malloc(LDAxK*sizeof(float));
    float *C      = (float *)malloc(LDCxN*sizeof(float));
    float *Cinit  = (float *)malloc(LDCxN*sizeof(float));
    float *Cfinal = (float *)malloc(LDCxN*sizeof(float));

    /* Check if unable to allocate memory */
    if ( (!A) || (!Cinit) || (!Cfinal) ){
        printf("Out of Memory \n ");
        return -2;
    }

    eps = LAPACKE_slamch_work('e');

    printf("\n");
    printf("------ TESTS FOR CHAMELEON SSYRK ROUTINE -------  \n");
    printf("            Size of the Matrix A %d by %d\n", N, K);
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf("============\n");
    printf(" The relative machine precision (eps) is to be %e \n",eps);
    printf(" Computational tests pass if scaled residuals are less than 10.\n");

    /*----------------------------------------------------------
    *  TESTING SSYRK
    */

    /* Initialize A */
    LAPACKE_slarnv_work(IONE, ISEED, LDAxK, A);

    /* Initialize C */
    MORSE_splgsy( (float)0., N, C, LDC, 51 );

    for (u=0; u<2; u++) {
        for (t=0; t<2; t++) {
            memcpy(Cinit,  C, LDCxN*sizeof(float));
            memcpy(Cfinal, C, LDCxN*sizeof(float));

            /* MORSE SSYRK */
            MORSE_ssyrk(uplo[u], trans[t], N, K, alpha, A, LDA, beta, Cfinal, LDC);

            /* Check the solution */
            info_solution = check_solution(uplo[u], trans[t], N, K,
                                           alpha, A, LDA, beta, Cinit, Cfinal, LDC);

            if (info_solution == 0) {
                printf("***************************************************\n");
                printf(" ---- TESTING SSYRK (%5s, %s) ........... PASSED !\n", uplostr[u], transstr[t]);
                printf("***************************************************\n");
            }
            else {
                printf("************************************************\n");
                printf(" - TESTING SSYRK (%5s, %s) ... FAILED !\n", uplostr[u], transstr[t]);    hres++;
                printf("************************************************\n");
            }
        }
    }

    free(A); free(C);
    free(Cinit); free(Cfinal);

    return hres;
}

/*--------------------------------------------------------------
 * Check the solution
 */

static int check_solution(MORSE_enum uplo, MORSE_enum trans, int N, int K,
                          float alpha, float *A, int LDA,
                          float beta,  float *Cref, float *Cmorse, int LDC)
{
    int info_solution;
    float Anorm, Cinitnorm, Cmorsenorm, Clapacknorm, Rnorm;
    float eps;
    float beta_const;
    float result;
    float *work = (float *)malloc(max(N, K)* sizeof(float));

    beta_const  = -1.0;
    Anorm       = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm),
                                (trans == MorseNoTrans) ? N : K,
                                (trans == MorseNoTrans) ? K : N, A, LDA, work);
    Cinitnorm   = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, N, Cref,    LDC, work);
    Cmorsenorm = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, N, Cmorse, LDC, work);

    cblas_ssyrk(CblasColMajor, (CBLAS_UPLO)uplo, (CBLAS_TRANSPOSE)trans,
                N, K, (alpha), A, LDA, (beta), Cref, LDC);

    Clapacknorm = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, N, Cref, LDC, work);

    cblas_saxpy(LDC*N, (beta_const), Cmorse, 1, Cref, 1);

    Rnorm = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), N, N, Cref, LDC, work);

    eps = LAPACKE_slamch_work('e');

    printf("Rnorm %e, Anorm %e, Cinitnorm %e, Cmorsenorm %e, Clapacknorm %e\n",
           Rnorm, Anorm, Cinitnorm, Cmorsenorm, Clapacknorm);

    result = Rnorm / ((Anorm + Cinitnorm) * N * eps);

    printf("============\n");
    printf("Checking the norm of the difference against reference SSYRK \n");
    printf("-- ||Cmorse - Clapack||_oo/((||A||_oo+||C||_oo).N.eps) = %e \n", result);

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
