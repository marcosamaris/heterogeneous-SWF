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
 *  @file codelet_cpotrf.c
 *
 *  MAGMA codelets kernel
 *  MAGMA is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver,
 *  and INRIA Bordeaux Sud-Ouest
 *
 *  @version 2.3.1
 *  @author Mathieu Faverge
 *  @author Cedric Augonnet
 *  @date 2011-06-01
 *  @generated c Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"

CHAMELEON_CL_CB(casum,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      M*N);
CHAMELEON_CL_CB(caxpy,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[1]), 0,                                      M);
CHAMELEON_CL_CB(cgeadd,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      M*N);
CHAMELEON_CL_CB(cgelqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      (4./3.)*M*N*K);
CHAMELEON_CL_CB(cgemm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), starpu_matrix_get_ny(task->handles[0]),     2. *M*N*K); /* If A^t, computation is wrong */
CHAMELEON_CL_CB(cgeqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      (4./3.)*M*M*N);
CHAMELEON_CL_CB(cgessm,        starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_nx(task->handles[2]),     2. *M*N*K);
CHAMELEON_CL_CB(cgessq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), 0,                                      4.*M*N);
CHAMELEON_CL_CB(cgetrf,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
CHAMELEON_CL_CB(cgetrf_incpiv, starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
CHAMELEON_CL_CB(cgetrf_nopiv,  starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
#if defined(PRECISION_z) || defined(PRECISION_c)
CHAMELEON_CL_CB(chemm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), 0,                                          2.*M*M *N);
CHAMELEON_CL_CB(cher2k,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                     ( 1.+2.*M*N)*M);
CHAMELEON_CL_CB(cherk,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                     ( 1.+   M)*M*N);
#endif
CHAMELEON_CL_CB(clacpy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(clange,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(claset,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(claset2,       starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(clauum,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (1./3.)*M* M*M);
#if defined(PRECISION_z) || defined(PRECISION_c)
CHAMELEON_CL_CB(cplghe,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(csytrf_nopiv,  starpu_matrix_get_nx(task->handles[0]), 0, 0,                                                                           (1./3.)*M* M*M);
#endif
CHAMELEON_CL_CB(cplgsy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(cplrnt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(cplssq,                                             1,                                      1, 0,                                                4);
CHAMELEON_CL_CB(cplssq2,                                            1,                                      1, 0,                                                1);
CHAMELEON_CL_CB(cpotrf,        starpu_matrix_get_nx(task->handles[0]), 0, 0,                                                                           (1./3.)*M* M*M);
CHAMELEON_CL_CB(cssssm,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), M*M*(2.*M+starpu_matrix_get_nx(task->handles[2])));
CHAMELEON_CL_CB(csymm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), 0,                                           2.*M*M *N);
CHAMELEON_CL_CB(csyr2k,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      ( 1.+2.*M*N)*M);
CHAMELEON_CL_CB(csyrk,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      ( 1.+   M)*M*N);
CHAMELEON_CL_CB(ctrasm,       starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                               0.5*M*(M+1));
CHAMELEON_CL_CB(ctrmm,         starpu_matrix_get_nx(task->handles[1]), starpu_matrix_get_ny(task->handles[1]), 0,                                               M*M*N);
CHAMELEON_CL_CB(ctrsm,         starpu_matrix_get_nx(task->handles[1]), starpu_matrix_get_ny(task->handles[1]), 0,                                               M*M*N);
CHAMELEON_CL_CB(ctrtri,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (1./3.)*M *M*M);
CHAMELEON_CL_CB(ctslqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(ctsmlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (4.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(ctsmqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (4.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(ctsqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(ctstrf,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),         M* M*M);
CHAMELEON_CL_CB(cttlqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     1. *M* M*M);
CHAMELEON_CL_CB(cttmlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(cttmqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(cttqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     1. *M* M*M);
CHAMELEON_CL_CB(cunmlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(cunmqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
