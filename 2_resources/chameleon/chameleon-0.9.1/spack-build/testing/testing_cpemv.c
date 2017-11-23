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
 * @file testing_cpemv.c
 *
 *  MORSE testing routines
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.4.0
 * @author Dulceneia Becker
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2011-10-06
 * @generated c Tue Sep 26 20:43:20 2017
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
#include "testing_cauxiliary.h"

#define COMPLEX
#undef REAL

/*--------------------------------------------------------------
 * Check the pemv
 */
static int check_solution(MORSE_enum trans, MORSE_enum storev, 
                          int M, int N, int L,
                          MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA,
                                                    MORSE_Complex32_t *X, int INCX,
                          MORSE_Complex32_t beta,  MORSE_Complex32_t *Y0, int INCY0,
                                                    MORSE_Complex32_t *Y,  int INCY,
                          MORSE_Complex32_t *W, float *Rnorm)
{
    int k;
    float eps = LAPACKE_slamch_work('e');
    float *work;
    MORSE_Complex32_t mzone = -1.0;

    /* Copy x to w */
    if ( trans == MorseNoTrans ) {
        k = N;
    } else {
        k = M;
    }
    
    work = (float *)malloc(k * sizeof(float));
    cblas_ccopy(k, Y0, INCY0, W, 1);
    
    /* w = a A x + b w */
    cblas_cgemv(CblasColMajor, (CBLAS_TRANSPOSE)trans, 
                M, N,
                CBLAS_SADDR(alpha), A,  LDA, 
                                    X,  INCX,
                CBLAS_SADDR(beta),  W,  1);

    /* y - w */
    cblas_caxpy(k, CBLAS_SADDR(mzone), Y, INCY, W, 1);
    
    /* Max Norm */
    *Rnorm = LAPACKE_clange_work(LAPACK_COL_MAJOR, 'm', 1, k, W, 1, work);
    
    if ( (*Rnorm / (M*N)) > eps) {
        return 1;
    } else {
        return 0;
    }
}

/*--------------------------------------------------------------
 * Testing ZPEMV
 */
int testing_cpemv(int argc, char **argv)
{
    int hres = 0;
    /* Check for number of arguments*/
    if ( argc != 1) {
        USAGE("PEMV", "N",
              "   - N      : number of columns\n");
        return -1;
    }

    /* Args */
    int arg_n = atoi(argv[0]);

    /* Local variables */
    MORSE_Complex32_t *A, *X, *Y, *A0, *Y0, *work;
    MORSE_Complex32_t alpha, beta, alpha0, beta0;
    int n    = arg_n;
    int lda  = arg_n;

    int info_solution = 0;
    int i, j, k, t;
    int nbtests = 0;
    int nfails = 0;
    int storev;
    int l = 0;
    int m = n;
    int incx = 1;
    int incy = 1;
    char *cstorev;
    float rnorm;
    float eps = LAPACKE_slamch_work('e');

    /* Allocate Data */
    A    = (MORSE_Complex32_t *)malloc(lda*n*sizeof(MORSE_Complex32_t));
    A0   = (MORSE_Complex32_t *)malloc(lda*n*sizeof(MORSE_Complex32_t));
    X    = (MORSE_Complex32_t *)malloc(lda*n*sizeof(MORSE_Complex32_t));
    Y    = (MORSE_Complex32_t *)malloc(lda*n*sizeof(MORSE_Complex32_t));
    Y0   = (MORSE_Complex32_t *)malloc(    n*sizeof(MORSE_Complex32_t));
    work = (MORSE_Complex32_t *)malloc(  2*n*sizeof(MORSE_Complex32_t));

    LAPACKE_clarnv_work(1, ISEED, 1, &alpha0);
    LAPACKE_clarnv_work(1, ISEED, 1, &beta0 );

    /* Check if unable to allocate memory */
    if ( (!A) || (!X) || (!Y0) || (!work) ) {
        printf("Out of Memory \n ");
        exit(0);
    }
    
     /* Initialize Data */
    MORSE_cplrnt(n, n, A,  lda, 479 );
    MORSE_cplrnt(n, n, X,  lda, 320 );
    MORSE_cplrnt(n, 1, Y0, n,   573 );

    printf("\n");
    printf("------ TESTS FOR CHAMELEON ZPEMV ROUTINE -------  \n");
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf(" The relative machine precision (eps) is %e \n",eps);
    printf(" Computational tests pass if scaled residual is less than eps.\n");
    printf("\n");

    nfails = 0;
    for (i=0; i<6; i++) {
        
        /* m and n cannot be greater than lda (arg_n) */
        switch (i) {
        case 0: l = 0;       m = arg_n;   n = m;        break;
        case 1: l = 0;       m = arg_n;   n = arg_n/2;  break; /**/
        case 2: l = arg_n;   m = l;       n = l;        break;
        case 3: l = arg_n/2; m = l;       n = arg_n;    break;
        case 4: l = arg_n/2; m = arg_n-l; n = l;        break;
        case 5: l = arg_n/3; m = arg_n-l; n = arg_n/2;  break; /**/
        }

        /* Colwise ConjTrans & Rowwise NoTrans */
#ifdef COMPLEX
        for (t=0; t<3; t++) {
#else
        for (t=0; t<2; t++) {
#endif

            /* Swap m and n for transpose cases */
            if ( t == 1 ) {
                k = m; m = n; n = k;
            }

            LAPACKE_clacpy_work( LAPACK_COL_MAJOR, 'A', m, n, 
                                 A, lda, A0, lda);

            if ( trans[t] == MorseNoTrans ) {
                storev = MorseRowwise;
                cstorev = storevstr[0];

                /* zeroed the upper right triangle */
                int64_t i, j;
                for (j=(n-l); j<n; j++) {
                    for (i=0; i<(j-(n-l)); i++) {
                        A0[i+j*lda] = 0.0;
                    }
                }
            }
            else {
                storev = MorseColumnwise;
                cstorev = storevstr[1];

                /* zeroed the lower left triangle */
                int64_t i, j;
                for (j=0; j<(l-1); j++) {
                    for (i=(m-l+1+j); i<m; i++) {
                        A0[i+j*lda] = 0.0;
                    }
                }
            }

            for (j=0; j<3; j++) {

                /* Choose alpha and beta */
                alpha = ( j==1 ) ? 0.0 : alpha0;
                beta  = ( j==2 ) ? 0.0 : beta0;

                /* incx and incy: 1 or lda */
                for (k=0; k<4; k++) {
                    switch (k) {
                    case 0:  incx = 1;    incy = 1;    break;
                    case 1:  incx = 1;    incy = lda;  break;
                    case 2:  incx = lda;  incy = 1;    break;
                    case 3:  incx = lda;  incy = lda;  break;
                    }
                    
                    /* initialize Y with incy */
                    cblas_ccopy(n, Y0, 1, Y, incy);
                    
                    /* ZPEMV */
                    CORE_cpemv( trans[t], storev, m, n, l, 
                                alpha, A, lda, 
                                       X, incx,
                                beta,  Y, incy, 
                                work);
                    
                    /* Check the solution */
                    info_solution = check_solution(trans[t], storev, 
                                                   m, n, l, 
                                                   alpha, A0,  lda,
                                                          X,   incx, 
                                                   beta,  Y0,  1, 
                                                          Y,   incy, 
                                                   work, &rnorm);
                    
                    if ( info_solution != 0 ) {
                        nfails++;
                        printf("Failed: t=%s, s=%s, M=%3d, N=%3d, L=%3d, alpha=%e, incx=%3d, beta=%e, incy=%3d, rnorm=%e\n", 
                               transstr[t], cstorev, m, n, l, crealf(alpha), incx, crealf(beta), incy, rnorm );
                    }
                    nbtests++;
                }
            }
        }
    }

    if ( nfails )
        printf("%d / %d tests failed\n", nfails, nbtests);

    printf("***************************************************\n");
    if (nfails == 0) {
        printf(" ---- TESTING ZPEMV ...... PASSED !\n");
    }
    else {
        printf(" ---- TESTING ZPEMV ... FAILED !\n");    hres++;
    }
    printf("***************************************************\n");

    free( A0 );
    free( A );
    free( X );
    free( Y0 );
    free( Y );

    return hres;
}

