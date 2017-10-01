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
 *  @file codelet_spotrf.c
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
 *  @generated s Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_s.h"

CHAMELEON_CL_CB(sasum,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      M*N);
CHAMELEON_CL_CB(saxpy,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[1]), 0,                                      M);
CHAMELEON_CL_CB(sgeadd,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      M*N);
CHAMELEON_CL_CB(sgelqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      (4./3.)*M*N*K);
CHAMELEON_CL_CB(sgemm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), starpu_matrix_get_ny(task->handles[0]),     2. *M*N*K); /* If A^t, computation is wrong */
CHAMELEON_CL_CB(sgeqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      (4./3.)*M*M*N);
CHAMELEON_CL_CB(sgessm,        starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_nx(task->handles[2]),     2. *M*N*K);
CHAMELEON_CL_CB(sgessq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), 0,                                      4.*M*N);
CHAMELEON_CL_CB(sgetrf,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
CHAMELEON_CL_CB(sgetrf_incpiv, starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
CHAMELEON_CL_CB(sgetrf_nopiv,  starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2./3.)*M*N*K);
#if defined(PRECISION_z) || defined(PRECISION_c)
CHAMELEON_CL_CB(ssymm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), 0,                                          2.*M*M *N);
CHAMELEON_CL_CB(ssyr2k,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                     ( 1.+2.*M*N)*M);
CHAMELEON_CL_CB(ssyrk,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                     ( 1.+   M)*M*N);
#endif
CHAMELEON_CL_CB(slacpy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(slange,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(slaset,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(slaset2,       starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(slauum,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (1./3.)*M* M*M);
#if defined(PRECISION_z) || defined(PRECISION_c)
CHAMELEON_CL_CB(splgsy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(ssytrf_nopiv,  starpu_matrix_get_nx(task->handles[0]), 0, 0,                                                                           (1./3.)*M* M*M);
#endif
CHAMELEON_CL_CB(splgsy,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(splrnt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                                M*N);
CHAMELEON_CL_CB(splssq,                                             1,                                      1, 0,                                                4);
CHAMELEON_CL_CB(splssq2,                                            1,                                      1, 0,                                                1);
CHAMELEON_CL_CB(spotrf,        starpu_matrix_get_nx(task->handles[0]), 0, 0,                                                                           (1./3.)*M* M*M);
CHAMELEON_CL_CB(sssssm,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), M*M*(2.*M+starpu_matrix_get_nx(task->handles[2])));
CHAMELEON_CL_CB(ssymm,         starpu_matrix_get_nx(task->handles[2]), starpu_matrix_get_ny(task->handles[2]), 0,                                           2.*M*M *N);
CHAMELEON_CL_CB(ssyr2k,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      ( 1.+2.*M*N)*M);
CHAMELEON_CL_CB(ssyrk,         starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                      ( 1.+   M)*M*N);
CHAMELEON_CL_CB(strasm,       starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_ny(task->handles[0]), 0,                                               0.5*M*(M+1));
CHAMELEON_CL_CB(strmm,         starpu_matrix_get_nx(task->handles[1]), starpu_matrix_get_ny(task->handles[1]), 0,                                               M*M*N);
CHAMELEON_CL_CB(strsm,         starpu_matrix_get_nx(task->handles[1]), starpu_matrix_get_ny(task->handles[1]), 0,                                               M*M*N);
CHAMELEON_CL_CB(strtri,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (1./3.)*M *M*M);
CHAMELEON_CL_CB(stslqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(stsmlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (4.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(stsmqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (4.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(stsqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(ststrf,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),         M* M*M);
CHAMELEON_CL_CB(sttlqt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     1. *M* M*M);
CHAMELEON_CL_CB(sttmlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(sttmqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), (2.0*M+starpu_matrix_get_nx(task->handles[3]))*M*M);
CHAMELEON_CL_CB(sttqrt,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     1. *M* M*M);
CHAMELEON_CL_CB(sormlq,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
CHAMELEON_CL_CB(sormqr,        starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]), starpu_matrix_get_nx(task->handles[0]),     2. *M* M*M);
