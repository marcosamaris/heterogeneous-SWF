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
 *  @file codelet_dpotrf.c
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
 *  @generated d Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

CHAMELEON_CL_CB(dasum,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      M*N);
CHAMELEON_CL_CB(daxpy,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[1]), 0,                                      M);
CHAMELEON_CL_CB(dgeadd,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      M*N);
CHAMELEON_CL_CB(dgelqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      (4./3.)*M*N*K);
CHAMELEON_CL_CB(dgemm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), starpu_matrix_get_ny(task->handles[0]),     2. *M*N*K); /* If A^t, computation is wrong */
CHAMELEON_CL_CB(dgeqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      (4./3.)*M*M*N);
CHAMELEON_CL_CB(dgessm,        starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_nx(task->handles[2]),     2. *M*N*K);
CHAMELEON_CL_CB(dgessq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), 0,                                      4.*M*N);
CHAMELEON_CL_CB(dgetrf,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
CHAMELEON_CL_CB(dgetrf_incpiv, starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
CHAMELEON_CL_CB(dgetrf_nopiv,  starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
#if defined(PRECISION_z) || defined(PRECISION_c)
CHAMELEON_CL_CB(dsymm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), 0,                                          2.*M*M *N);
CHAMELEON_CL_CB(dsyr2k,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                     ( 1.+2.*M*N)*M);
CHAMELEON_CL_CB(dsyrk,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                     ( 1.+   M)*M*N);
#endif
CHAMELEON_CL_CB(dlacpy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(dlange,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(dlaset,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(dlaset2,       starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(dlauum,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (1./3.)*M* M*M);
#if defined(PRECISION_z) || defined(PRECISION_c)
CHAMELEON_CL_CB(dplgsy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(dsytrf_nopiv,  starpu_matrix_get_nx(task->handles[0]), 0, 0,                                                                           (1./3.)*M* M*M);
#endif
CHAMELEON_CL_CB(dplgsy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(dplrnt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(dplssq,                                             1,                                      1, 0,                                                4);
CHAMELEON_CL_CB(dplssq2,                                            1,                                      1, 0,                                                1);
CHAMELEON_CL_CB(dpotrf,        starpu_matrix_get_nx(task->handles[0]), 0, 0,                                                                           (1./3.)*M* M*M);
CHAMELEON_CL_CB(dssssm,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), M*M*(2.*M+starpu_matrix_get_nx(task->handles[2])));
CHAMELEON_CL_CB(dsymm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), 0,                                           2.*M*M *N);
CHAMELEON_CL_CB(dsyr2k,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      ( 1.+2.*M*N)*M);
CHAMELEON_CL_CB(dsyrk,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      ( 1.+   M)*M*N);
CHAMELEON_CL_CB(dtrasm,       starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                               0.5*M*(M+1));
CHAMELEON_CL_CB(dtrmm,         starpu_matrix_get_nx(task->handles[1]), starpu_matrix_get_ny(task->handles[1]), 0,                                               M*M*N);
CHAMELEON_CL_CB(dtrsm,         starpu_matrix_get_nx(task->handles[1]), starpu_matrix_get_ny(task->handles[1]), 0,                                               M*M*N);
CHAMELEON_CL_CB(dtrtri,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (1./3.)*M *M*M);
CHAMELEON_CL_CB(dtslqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(dtsmlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (4.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(dtsmqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (4.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(dtsqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(dtstrf,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),         M* M*M);
CHAMELEON_CL_CB(dttlqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     1. *M* M*M);
CHAMELEON_CL_CB(dttmlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(dttmqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(dttqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     1. *M* M*M);
CHAMELEON_CL_CB(dormlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(dormqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
