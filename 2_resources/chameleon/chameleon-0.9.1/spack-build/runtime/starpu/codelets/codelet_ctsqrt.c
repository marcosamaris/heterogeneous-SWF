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
 * @file codelet_ctsqrt.c
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Hatem Ltaief
 * @author Jakub Kurzak
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated c Tue Sep 26 20:43:04 2017
 *
 **/
#include "coreblas/include/lapacke.h"
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_c.h"
#undef REAL
#define COMPLEX

/**
 *
 * @ingroup CORE_MORSE_Complex64_t
 *
 * CORE_ctsqrt computes a QR factorization of a rectangular matrix
 * formed by coupling a complex N-by-N upper triangular tile A1
 * on top of a complex M-by-N tile A2:
 *
 *    | A1 | = Q * R
 *    | A2 |
 *
 *******************************************************************************
 *
 * @param[in] M
 *         The number of columns of the tile A2. M >= 0.
 *
 * @param[in] N
 *         The number of rows of the tile A1.
 *         The number of columns of the tiles A1 and A2. N >= 0.
 *
 * @param[in] IB
 *         The inner-blocking size.  IB >= 0.
 *
 * @param[in,out] A1
 *         On entry, the N-by-N tile A1.
 *         On exit, the elements on and above the diagonal of the array
 *         contain the N-by-N upper trapezoidal tile R;
 *         the elements below the diagonal are not referenced.
 *
 * @param[in] LDA1
 *         The leading dimension of the array A1. LDA1 >= max(1,N).
 *
 * @param[in,out] A2
 *         On entry, the M-by-N tile A2.
 *         On exit, all the elements with the array TAU, represent
 *         the unitary tile Q as a product of elementary reflectors
 *         (see Further Details).
 *
 * @param[in] LDA2
 *         The leading dimension of the tile A2. LDA2 >= max(1,M).
 *
 * @param[out] T
 *         The IB-by-N triangular factor T of the block reflector.
 *         T is upper triangular by block (economic storage);
 *         The rest of the array is not referenced.
 *
 * @param[in] LDT
 *         The leading dimension of the array T. LDT >= IB.
 *
 * @param[out] TAU
 *         The scalar factors of the elementary reflectors (see Further
 *         Details).
 *
 * @param[out] WORK
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *          \retval <0 if -i, the i-th argument had an illegal value
 *
 ******************************************************************************/

void MORSE_TASK_ctsqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt)
{
    (void)nb;
    struct starpu_codelet *codelet = &cl_ctsqrt;
    void (*callback)(void*) = options->profiling ? cl_ctsqrt_callback : NULL;
    MORSE_starpu_ws_t *h_work = (MORSE_starpu_ws_t*)(options->ws_host);

    if ( morse_desc_islocal( A1, A1m, A1n ) ||
         morse_desc_islocal( A2, A2m, A2n ) ||
         morse_desc_islocal( T,  Tm,  Tn  ) )
    {
        starpu_insert_task(
            codelet,
            STARPU_VALUE,    &m,                 sizeof(int),
            STARPU_VALUE,    &n,                 sizeof(int),
            STARPU_VALUE,    &ib,                sizeof(int),
            STARPU_RW,        RTBLKADDR(A1, MORSE_Complex32_t, A1m, A1n),
            STARPU_VALUE,    &lda1,              sizeof(int),
            STARPU_RW,        RTBLKADDR(A2, MORSE_Complex32_t, A2m, A2n),
            STARPU_VALUE,    &lda2,              sizeof(int),
            STARPU_W,         RTBLKADDR(T,  MORSE_Complex32_t, Tm,  Tn ),
            STARPU_VALUE,    &ldt,               sizeof(int),
            /* max( nb * (ib+1), ib * (ib+nb) ) */
            STARPU_SCRATCH,   options->ws_worker,
            /* 2 * ib * (nb+ib) + nb */
            STARPU_VALUE,    &h_work,            sizeof(MORSE_starpu_ws_t *),
            STARPU_PRIORITY,  options->priority,
            STARPU_CALLBACK,  callback,
            0);
    }
}


static void cl_ctsqrt_cpu_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *h_work;
    int m;
    int n;
    int ib;
    MORSE_Complex32_t *A1;
    int lda1;
    MORSE_Complex32_t *A2;
    int lda2;
    MORSE_Complex32_t *T;
    int ldt;
    MORSE_Complex32_t *TAU, *WORK;

    A1 = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[0]);
    A2 = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[1]);
    T  = (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[2]);
    TAU= (MORSE_Complex32_t *)STARPU_MATRIX_GET_PTR(descr[3]); /* nb + ib*nb */

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &lda1, &lda2, &ldt, &h_work);

    WORK = TAU + max( m, n );
    CORE_ctsqrt(m, n, ib, A1, lda1, A2, lda2, T, ldt, TAU, WORK);
}


#if defined(CHAMELEON_USE_MAGMA)

magma_int_t
magma_ctsqrt2_gpu( magma_int_t m, magma_int_t n, magma_int_t nb,
                   magmaFloatComplex *da1, magma_int_t ldda1,
                   magmaFloatComplex *da2, magma_int_t ldda2,
                   magmaFloatComplex *a2,  magma_int_t lda2,
                   magmaFloatComplex *dt,  magma_int_t lddt,
                   magmaFloatComplex *t,  magma_int_t ldt,
                   magmaFloatComplex *dd,
                   magmaFloatComplex *d,  magma_int_t ldd,
                   magmaFloatComplex *tau,
                   magmaFloatComplex *hwork,
                   magmaFloatComplex *dwork,
                   CUstream stream)
{
#define da1_ref(a_1,a_2) ( da1+(a_2)*ldda1 + (a_1))
#define da2_ref(a_1,a_2) ( da2+(a_2)*ldda2 + (a_1))
#define a2_ref(a_1,a_2) ( a2+(a_2)*lda2 + (a_1))
#define t_ref(a_1,a_2) ( t+(a_2)*ldt + (a_1))
#define dt_ref(a_1,a_2) ( dt+(a_2)*lddt + (a_1))
#define d_ref(a_1,a_2) ( d+(a_2)*ldd + (a_1))

	int i, k, lddwork, old_i, old_ib, rows, cols;
	int ib;
	float _Complex one=1.;
//	int lwkopt = n * nb;
//	hwork[0] = *((magmaFloatComplex*) &lwkopt);

	if (m < 0) {
		return -1;
	} else if (n < 0) {
		return -2;
	} else if (ldda2 < max(1,m)) {
		return -4;
	}

	k = min(m,n);
	if (k == 0) {
		hwork[0] = *((magmaFloatComplex*) &one);
		return MAGMA_SUCCESS;
	}

	lddwork= nb;

	/* lower parts of little T must be zero: memset all to 0 for simplicity */
	memset(t, 0, nb*nb*sizeof(magmaFloatComplex));
	cudaMemset(dt, 0, nb*n*sizeof(magmaFloatComplex));

	/* copy the first diag tile of A1 from device to host: da1 -> d */
	cublasGetMatrix(nb, nb, sizeof(magmaFloatComplex),
                    da1_ref(0, 0), ldda1,
                    d, ldd);
//	cudaMemcpy( d, da1_ref(0,0),
//	            nb*nb*sizeof(cuFloatComplex),
//	            cudaMemcpyDeviceToHost );

	/* copy first panel of A2 from device to host: da2 -> a2 */
//	cublasGetMatrix(m, nb, sizeof(magmaFloatComplex),
//                    da2_ref(0, 0), ldda2,
//                    a2, lda2);
	cudaMemcpy( a2, da2_ref(0, 0),
	            m*nb*sizeof(cuFloatComplex),
	            cudaMemcpyDeviceToHost );

	/* This is only blocked code for now */
	for (i = 0; i < n; i += nb) {

		ib = min(n-i, nb);
		rows = m;

		/* Send the next panel (diagonal block of A1 & block column of A2)
		   to the CPU (in work_a1 and work_a2) and apply tsmqr update on the
		   remaining non updated panels */
		if (i>0) {

			/* copy the diag tile of A1 from device to host: da1 -> d */
			cublasGetMatrix(ib, ib, sizeof(magmaFloatComplex),
		                    da1_ref(i, i), ldda1,
		                    d, ldd);
//		    cudaMemcpy( d, da1_ref(i,i),
//		        ib*ib*sizeof(cuFloatComplex),
//		        cudaMemcpyDeviceToHost );

			/* copy panel of A2 from device to host: da2 -> a2 */
			cublasGetMatrix(rows, ib, sizeof(magmaFloatComplex),
                            da2_ref(0, i), ldda2,
                            a2, lda2);
//            cudaMemcpy( a2, da2_ref(0,i),
//                rows*ib*sizeof(cuFloatComplex),
//                cudaMemcpyDeviceToHost );

			/* Apply H' to A(i:m,i+2*ib:n) from the left */
			cols = n-old_i-2*old_ib;
			if (cols > 0){
				magma_ctsmqr_gpu( MagmaLeft, MagmaConjTrans,
                                  old_ib, cols, rows, cols, old_ib, old_ib,
								  da1_ref(old_i, old_i+2*old_ib), ldda1,
								  da2_ref(0, old_i+2*old_ib), ldda2,
								  da2_ref(0, old_i), ldda2,
								  dt_ref(0, old_i), lddt,
								  dwork, old_ib,
								  dwork + old_ib * cols, rows,
								  stream );
			}

		}

		/* compute QR factorization of the panel of A2 rows x ib */
		CORE_ctsqrt(rows, ib, ib,
                    (float _Complex*) d, ldd,
                    (float _Complex*) a2, lda2,
                    (float _Complex*) t, ldt,
                    (float _Complex*) tau,
                    (float _Complex*) hwork);

		/* Send the panel from A2 back to the GPU */
		cublasSetMatrix(rows, ib, sizeof(magmaFloatComplex),
                        a2, lda2,
                        da2_ref(0, i), ldda2);
//        cudaMemcpy( da2_ref(0,i), a2,
//            rows*ib*sizeof(cuFloatComplex),
//            cudaMemcpyHostToDevice );

		/* Send the triangular factor T from hwork to the GPU */
		cublasSetMatrix(ib, ib, sizeof(magmaFloatComplex),
                        t, ldt,
                        dt_ref(0, i), lddt);
//        cudaMemcpy( dt_ref(0,i), t,
//            ib*ib*sizeof(cuFloatComplex),
//            cudaMemcpyHostToDevice );

		/* get back the diag tile in A1 from host to device: d -> da1 */
		cublasSetMatrix(ib, ib, sizeof(magmaFloatComplex),
                        d, ldd,
                        da1_ref(i, i), ldda1);
//        cudaMemcpy( da1_ref(i, i), d,
//            ib*ib*sizeof(cuFloatComplex),
//            cudaMemcpyHostToDevice );

		/* tsmqr update on one panel forward (look ahead 1) */
		if (i + ib < n) {

			if (i+2*ib < n){
				cols = ib;
			}
			else{
				cols = n-i-ib;
			}

			/* Apply H' to A(i:m,i+ib:i+2*ib) from the left */
		    magma_ctsmqr_gpu( MagmaLeft, MagmaConjTrans,
                              ib, cols, rows, cols, ib, ib,
                              da1_ref(i, i+ib), ldda1,
                              da2_ref(0, i+ib), ldda2,
                              da2_ref(0, i), ldda2,
                              dt_ref(0, i), lddt,
                              dwork, ib,
                              dwork + ib * cols, rows,
                              stream );
			old_i = i;
			old_ib = ib;
		}
	}

#undef da1_ref
#undef da2_ref
#undef a2_ref
#undef t_ref
#undef dt_ref
#undef d_ref

	return MAGMA_SUCCESS;

} /* magma_ctsqrt_gpu */

static void cl_ctsqrt_cuda_func(void *descr[], void *cl_arg)
{
    MORSE_starpu_ws_t *h_work;
    int m;
    int n;
    int ib;
    cuFloatComplex *h_A2, *h_T, *h_D, *h_TAU, *h_W;
    cuFloatComplex *d_A1, *d_A2, *d_T, *d_D, *d_W;
    int lda1, lda2, ldt;
    CUstream stream;

    starpu_codelet_unpack_args(cl_arg, &m, &n, &ib, &lda1, &lda2, &ldt, &h_work);

    /* Gather pointer to data on device */
    d_A1 = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[0]);
    d_A2 = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[1]);
    d_T  = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[2]);
    d_W  = (cuFloatComplex *)STARPU_MATRIX_GET_PTR(descr[3]); /* 2*ib*n + ib*ib */
    d_D  = d_W + 2*ib*n;

    /* scratch data on host */
    /* m*ib + ib*ib + max(m,n) + ib*n + ib*ib */
    h_A2  = (cuFloatComplex*)RUNTIME_starpu_ws_getlocal(h_work);
    h_T   = h_A2  + m*ib;
    h_TAU = h_T   + ib*ib;
    h_W   = h_TAU + max(m,n);
    h_D   = h_W   + ib*n;

    stream = starpu_cuda_get_local_stream();
    magma_ctsqrt2_gpu( m, n, ib,
                       d_A1, lda1, d_A2, lda2,
                       h_A2, lda2,
                       d_T, ldt, h_T, ib,
                       d_D, h_D, ib, h_TAU,
                       h_W, d_W, stream);

    cudaThreadSynchronize();
}

#endif

/*
 * Codelet definition
 */
#if defined(CHAMELEON_USE_MAGMA) || defined(CHAMELEON_SIMULATION)
CODELETS(ctsqrt, 4, cl_ctsqrt_cpu_func, cl_ctsqrt_cuda_func, 0)
#else
CODELETS_CPU(ctsqrt, 4, cl_ctsqrt_cpu_func)
#endif
