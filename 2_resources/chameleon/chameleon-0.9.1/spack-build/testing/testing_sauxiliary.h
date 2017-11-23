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
 * @file testing_sauxiliary.h
 *
 *  MORSE testing routines
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 0.9.0
 * @author Mathieu Faverge
 * @author Cédric Castagnède
 * @date 2010-11-15
 * @generated s Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef TESTING_SAUXILIARY_H
#define TESTING_SAUXILIARY_H

//#include "testing.h"

#define USAGE(name, args, details)                                             \
  printf(" Proper Usage is : ./ztesting ncores ngpus " name " " args " with\n" \
         "   - ncores : number of cores \n"                                    \
         "   - ngpus  : number of GPUs\n"                                      \
         "   - name   : name of function to test\n"                            \
         details);

#ifdef WIN32
#include <float.h>
#define isnan _isnan
#endif

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

extern int IONE;
extern int ISEED[4];

extern int format[6];
extern int trans[3];
extern int uplo[2];
extern int side[2];
extern int diag[2];
extern int itype[3];
extern int storev[2];
extern int norm[4];

extern char *formatstr[6];
extern char *transstr[3];
extern char *uplostr[2];
extern char *sidestr[2];
extern char *diagstr[2];
extern char *itypestr[3];
extern char *storevstr[2];
extern char *normstr[4];

extern void *formatmap[6];

int map_CM  (int m, int n, int mb, int nb, int i, int j);
int map_CCRB(int m, int n, int mb, int nb, int i, int j);
int map_CRRB(int m, int n, int mb, int nb, int i, int j);
int map_RCRB(int m, int n, int mb, int nb, int i, int j);
int map_RRRB(int m, int n, int mb, int nb, int i, int j);
int map_RM  (int m, int n, int mb, int nb, int i, int j);

int testing_sgemm(int argc, char **argv);
int testing_ssymm(int argc, char **argv);
int testing_ssymm(int argc, char **argv);
int testing_ssyrk(int argc, char **argv);
int testing_slange(int argc, char **argv);
int testing_ssyrk(int argc, char **argv);
int testing_ssyr2k(int argc, char **argv);
int testing_ssyr2k(int argc, char **argv);
int testing_strmm(int argc, char **argv);
int testing_strsm(int argc, char **argv);
int testing_spemv(int argc, char **argv);

int testing_sposv(int argc, char **argv);
int testing_sgels(int argc, char **argv);
int testing_sgesv(int argc, char **argv);
int testing_sgesv_incpiv(int argc, char **argv);

int testing_spotri(int argc, char **argv);
int testing_sgetri(int argc, char **argv);

int testing_sgeev(int argc, char **argv);
int testing_sgesvd(int argc, char **argv);
int testing_ssyev(int argc, char **argv);
int testing_ssyevd(int argc, char **argv);
int testing_shegv(int argc, char **argv);
int testing_ssygst(int argc, char **argv);

int testing_sgecfi(int argc, char **argv);
int testing_sgetmi(int argc, char **argv);

#ifdef DOUBLE
int testing_dsposv(int argc, char **argv);
int testing_dsgesv(int argc, char **argv);
int testing_dsungesv(int argc, char **argv);
#endif

#endif /* TESTINGS_H */
