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
 * @file testing_slange.c
 *
 *  MORSE testing routines
 *  MORSE is a software package provided by Inria Bordeaux - Sud-Ouest, LaBRI,
 *  University of Bordeaux, Bordeaux INP
 *
 * @version 2.6.0
 * @comment This file has been automatically generated
 *          from Plasma 2.6.0 for MORSE 1.0.0
 * @author Emmanuel Agullo
 * @author Mathieu Faverge
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

int testing_slange(int argc, char **argv)
{
    int hres = 0;
    /* Check for number of arguments*/
    if ( argc < 3) {
        USAGE("LANGE", "M N LDA",
              "   - M      : number of rows of matrices A and C\n"
              "   - N      : number of columns of matrices B and C\n"
              "   - LDA    : leading dimension of matrix A\n");
        return -1;
    }
    int M = atoi(argv[0]);
    int N = atoi(argv[1]);
    int LDA = atoi(argv[2]);
    int LDAxN = LDA*N;
    int n, u;
    float eps;

    /* Allocate Data */
    float *A    = (float *)malloc(LDAxN*sizeof(float));
    float            *work = (float*) malloc(max(M,N)*sizeof(float));
    float normmorse=0, normlapack, result;

    eps = LAPACKE_slamch_work('e');

    printf("\n");
    printf("------ TESTS FOR CHAMELEON SLANGE ROUTINE -------  \n");
    printf("            Size of the Matrix %d by %d\n", M, N);
    printf("\n");
    printf(" The matrix A is randomly generated for each test.\n");
    printf("============\n");
    printf(" The relative machine precision (eps) is to be %e \n",eps);
    printf(" Computational tests pass if scaled residuals are less than 10.\n");

    /*----------------------------------------------------------
     *  TESTING SLANGE
     */

    /* Initialize A, B, C */
    MORSE_splrnt( M, N, A, LDA, 3436 );

    /* MORSE SLANGE */
    for(n=0; n<4; n++) {
        normmorse  = MORSE_slange(norm[n], M, N, A, LDA);
        normlapack = LAPACKE_slange_work(LAPACK_COL_MAJOR, morse_lapack_const(norm[n]), M, N, A, LDA, work);
        printf("LAPACK %e, CHAMELEON %e\n", normlapack, normmorse);
        result = fabs(normmorse - normlapack) / (normlapack * eps);

        switch(norm[n]) {
        case MorseMaxNorm:
            /* result should be perfectly equal */
            break;
        case MorseInfNorm:
            /* Sum order on the line can differ */
            result = result / (float)N;
            break;
        case MorseOneNorm:
            /* Sum order on the column can differ */
            result = result / (float)M;
            break;
        case MorseFrobeniusNorm:
            /* Sum order on every element can differ */
            result = result / ((float)M * (float)N);
            break;
        }

        printf("***************************************************\n");
        if ( result < 1. ) {
            printf(" ---- TESTING SLANGE (%s)............... PASSED !\n", normstr[n]);
        }
        else {
            printf(" - TESTING SLANGE (%s)... FAILED !\n", normstr[n]);    hres++;
        }
        printf("***************************************************\n");

    }

    #ifdef COMPLEX
        /* MORSE SLANTR */
        for(n=1; n<3; n++) {
            for(u=0; u<2; u++) {
                int d;
                for(d=0; d<2; d++) {
                    normmorse = MORSE_slantr(norm[n], uplo[u], diag[d], M, N, A, LDA);
                    normlapack = LAPACKE_slantr_work(LAPACK_COL_MAJOR, morse_lapack_const(norm[n]), morse_lapack_const(uplo[u]),
                                                     morse_lapack_const(diag[d]), M, N, A, LDA, work);
                    printf("LAPACK %e, CHAMELEON %e\n", normlapack, normmorse);

                    result = fabs(normmorse - normlapack) / (normlapack * eps);
                    switch(norm[n]) {
                    case MorseMaxNorm:
                        /* result should be perfectly equal */
                        break;
                    case MorseInfNorm:
                        /* Sum order on the line can differ */
                        result = result / (float)N;
                        break;
                    case MorseOneNorm:
                        /* Sum order on the column can differ */
                        result = result / (float)M;
                        break;
                    case MorseFrobeniusNorm:
                        /* Sum oreder on every element can differ */
                        result = result / ((float)M * (float)N);
                        break;
                    }

                    printf("***************************************************\n");
                    if ( result < 1. ) {
                        printf(" ---- TESTING SLANTR (%s, %s, %s)......... PASSED !\n",
                               normstr[n], uplostr[u], diagstr[d]);
                    }
                    else {
                        printf(" - TESTING SLANTR (%s, %s, %s)... FAILED !\n",
                               normstr[n], uplostr[u], diagstr[d]);
                    }
                    printf("***************************************************\n");
                }
            }
        }
    #endif

    /* MORSE SLANSY */
    for(n=0; n<4; n++) {
        for(u=0; u<2; u++) {
            normmorse = MORSE_slansy(norm[n], uplo[u], min(M,N), A, LDA);
            normlapack = LAPACKE_slansy_work(LAPACK_COL_MAJOR, morse_lapack_const(norm[n]), morse_lapack_const(uplo[u]), min(M,N), A, LDA, work);
            printf("LAPACK %e, CHAMELEON %e\n", normlapack, normmorse);

            result = fabs(normmorse - normlapack) / (normlapack * eps);
            switch(norm[n]) {
            case MorseMaxNorm:
                /* result should be perfectly equal */
                break;
            case MorseInfNorm:
                /* Sum order on the line can differ */
                result = result / (float)N;
                break;
            case MorseOneNorm:
                /* Sum order on the column can differ */
                result = result / (float)M;
                break;
            case MorseFrobeniusNorm:
                /* Sum oreder on every element can differ */
                result = result / ((float)M * (float)N);
                break;
            }

            printf("***************************************************\n");
            if ( result < 1. ) {
                printf(" ---- TESTING SLANSY (%s, %s)......... PASSED !\n", normstr[n], uplostr[u]);
            }
            else {
                printf(" - TESTING SLANSY (%s, %s)... FAILED !\n", normstr[n], uplostr[u]);
            }
            printf("***************************************************\n");
        }
    }

    #ifdef COMPLEX
        /* MORSE SLANSY */
        {
          int j;
          for (j=0; j<min(M,N); j++) {
            A[j*LDA+j] -= I*cimag(A[j*LDA+j]);
          }
        }

        for(n=0; n<4; n++) {
            for(u=0; u<2; u++) {
                normmorse = MORSE_slansy(norm[n], uplo[u], min(M,N), A, LDA);
                normlapack = LAPACKE_slansy_work(LAPACK_COL_MAJOR, morse_lapack_const(norm[n]), morse_lapack_const(uplo[u]), min(M,N), A, LDA, work);
                printf("LAPACK %e, CHAMELEON %e\n", normlapack, normmorse);

                result = fabs(normmorse - normlapack) / (normlapack * eps);
                switch(norm[n]) {
                case MorseMaxNorm:
                    /* result should be perfectly equal */
                    break;
                case MorseInfNorm:
                    /* Sum order on the line can differ */
                    result = result / (float)N;
                    break;
                case MorseOneNorm:
                    /* Sum order on the column can differ */
                    result = result / (float)M;
                    break;
                case MorseFrobeniusNorm:
                    /* Sum oreder on every element can differ */
                    result = result / ((float)M * (float)N);
                    break;
                }

                printf("***************************************************\n");
                if ( result < 1. ) {
                    printf(" ---- TESTING SLANSY (%s, %s)......... PASSED !\n", normstr[n], uplostr[u]);
                }
                else {
                    printf(" - TESTING SLANSY (%s, %s)... FAILED !\n", normstr[n], uplostr[u]);
                }
                printf("***************************************************\n");
            }
        }
    #endif

    free(A);
    free(work);
    return hres;
}
