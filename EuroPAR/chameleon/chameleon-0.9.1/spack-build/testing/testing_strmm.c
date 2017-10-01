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
 * @file testing_strmm.c
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

#undef COMPLEX
#define REAL

static int check_solution(MORSE_enum side, MORSE_enum uplo, MORSE_enum trans, MORSE_enum diag,
                          int M, int N, float alpha,
                          float *A, int LDA,
                          float *Bref, float *Bmorse, int LDB);

int testing_strmm(int argc, char **argv)
{
    int hres = 0;
    /* Check for number of arguments*/
    if ( argc != 5 ) {
        USAGE("TRMM", "alpha M N LDA LDB",
              "   - alpha  : alpha coefficient\n"
              "   - M      : number of rows of matrices B\n"
              "   - N      : number of columns of matrices B\n"
              "   - LDA    : leading dimension of matrix A\n"
              "   - LDB    : leading dimension of matrix B\n");
        return -1;
    }

    float alpha = (float) atol(argv[0]);
    int M     = atoi(argv[1]);
    int N     = atoi(argv[2]);
    int LDA   = atoi(argv[3]);
    int LDB   = atoi(argv[4]);

    float eps;
    int info_solution;
    int s, u, t, d, i;
    int LDAxM = LDA*max(M,N);
    int LDBxN = LDB*max(M,N);

    float *A      = (float *)malloc(LDAxM*sizeof(float));
    float *B      = (float *)malloc(LDBxN*sizeof(float));
    float *Binit  = (float *)malloc(LDBxN*sizeof(float));
    float *Bfinal = (float *)malloc(LDBxN*sizeof(float));

    /* Check if unable to allocate memory */
    if ( (!A) || (!B) || (!Binit) || (!Bfinal)){
        printf("Out of Memory \n ");
        return -2;
    }

    eps = LAPACKE_slamch_work('e');

    printf("\n");
    printf("------ TESTS FOR CHAMELEON STRMM ROUTINE -------  \n");
    printf("            Size of the Matrix B : %d by %d\n", M, N);
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf("============\n");
    printf(" The relative machine precision (eps) is to be %e \n",eps);
    printf(" Computational tests pass if scaled residuals are less than 10.\n");

    /*----------------------------------------------------------
     *  TESTING STRMM
     */

    /* Initialize A, B, C */
    LAPACKE_slarnv_work(IONE, ISEED, LDAxM, A);
    LAPACKE_slarnv_work(IONE, ISEED, LDBxN, B);
    for(i=0;i<max(M,N);i++)
      A[LDA*i+i] = A[LDA*i+i] + 2.0;

    for (s=0; s<2; s++) {
        for (u=0; u<2; u++) {
#ifdef COMPLEX
            for (t=0; t<3; t++) {
#else
            for (t=0; t<2; t++) {
#endif
                for (d=0; d<2; d++) {

                    memcpy(Binit,  B, LDBxN*sizeof(float));
                    memcpy(Bfinal, B, LDBxN*sizeof(float));

                    /* MORSE STRMM */
                    MORSE_strmm(side[s], uplo[u], trans[t], diag[d],
                                 M, N, alpha, A, LDA, Bfinal, LDB);

                    /* Check the solution */
                    info_solution = check_solution(side[s], uplo[u], trans[t], diag[d],
                                                   M, N, alpha, A, LDA, Binit, Bfinal, LDB);

                    printf("***************************************************\n");
                    if (info_solution == 0) {
                        printf(" ---- TESTING STRMM (%s, %s, %s, %s) ...... PASSED !\n",
                               sidestr[s], uplostr[u], transstr[t], diagstr[d]);
                    }
                    else {
                        printf(" ---- TESTING STRMM (%s, %s, %s, %s) ... FAILED !\n",
                               sidestr[s], uplostr[u], transstr[t], diagstr[d]);    hres++;
                    }
                    printf("***************************************************\n");
                }
            }
        }
    }

    free(A); free(B);
    free(Binit); free(Bfinal);

    return hres;
}

/*--------------------------------------------------------------
 * Check the solution
 */
static int check_solution(MORSE_enum side, MORSE_enum uplo, MORSE_enum trans, MORSE_enum diag,
                          int M, int N, float alpha,
                          float *A, int LDA,
                          float *Bref, float *Bmorse, int LDB)
{
    int info_solution;
    float Anorm, Binitnorm, Bmorsenorm, Blapacknorm, Rnorm, result;
    float eps;
    float mzone = (float)-1.0;

    float *work = (float *)malloc(max(M, N)* sizeof(float));
    int Am, An;

    if (side == MorseLeft) {
        Am = M; An = M;
    } else {
        Am = N; An = N;
    }

    Anorm       = LAPACKE_slantr_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), morse_lapack_const(uplo), morse_lapack_const(diag),
                                Am, An, A, LDA, work);
    Binitnorm   = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Bref,    LDB, work);
    Bmorsenorm = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Bmorse, LDB, work);

    cblas_strmm(CblasColMajor, (CBLAS_SIDE)side, (CBLAS_UPLO)uplo, (CBLAS_TRANSPOSE)trans,
                (CBLAS_DIAG)diag, M, N, (alpha), A, LDA, Bref, LDB);

    Blapacknorm = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Bref, LDB, work);

    cblas_saxpy(LDB * N, (mzone), Bmorse, 1, Bref, 1);

    Rnorm = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(MorseInfNorm), M, N, Bref, LDB, work);

    eps = LAPACKE_slamch_work('e');

    printf("Rnorm %e, Anorm %e, Binitnorm %e, Bmorsenorm %e, Blapacknorm %e\n",
           Rnorm, Anorm, Binitnorm, Bmorsenorm, Blapacknorm);

    result = Rnorm / ((Anorm + Blapacknorm) * max(M,N) * eps);

    printf("============\n");
    printf("Checking the norm of the difference against reference STRMM \n");
    printf("-- ||Cmorse - Clapack||_oo/((||A||_oo+||B||_oo).N.eps) = %e \n", result);

    if ( isinf(Blapacknorm) || isinf(Bmorsenorm) || isnan(result) || isinf(result) || (result > 10.0) ) {
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
