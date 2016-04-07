#!/bin/bash
#MSUB -r Khp15000
#MSUB -n 8 
#MSUB -N 1
#MSUB -T 10800 
#MSUB -o out
#MSUB -e err
#MSUB -q hybrid
#MSUB -A gen1567

export PKG_CONFIG_PATH=/ccc/cont003/home/gen1567/lacoste/work/starpu_svn/branches/starpu-1.1/bullxmpi-intel/mpi:/ccc/cont003/home/gen1567/lacoste/
work/starpu_svn/branches/starpu-1.1/bullxmpi-intel:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/ccc/cont003/home/gen1567/lacoste/work/starpu_svn/branches/starpu-1.1/bullxmpi-intel-install/lib/
export STARPU_SCHED=ws

export PTSCOTCH_INCDIR=/ccc/cont003/home/gen1567/pichong/scotch_6.0.0/include
export PTSCOTCH_LIBDIR=/ccc/cont003/home/gen1567/pichong/scotch_6.0.0/lib

# Additionnal modules
module purge
module load ccc
module load dfldatadir/own
module load c/intel/14.0.3.174
module load fortran/intel/14.0.3.174
module load idb/14.0.3.174
module load bullxmpi/1.2.7.2
module load datadir/own
module load licsrv/intel
module load c++/intel/14.0.3.174
module load mkl/14.0.3.174
module load intel/14.0.3.174
module load cuda/5.5.22
module load cmake/2.8.9
module load hwloc/1.7.1

export CFLAGS="-I$C_INCDIR"
export NVCCFLAGS="-ccbin=icc"
export LD=xild
export CC=icc
export FC=ifort
export CXX=icpc
export STARPU_DIR=/ccc/cont003/home/gen1567/lacoste/work/starpu_svn/branches/starpu-1.1/bullxmpi-intel-install/
export PKG_CONFIG_PATH=$STARPU_DIR/lib/pkgconfig/:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=$STARPU_DIR/lib/:$LD_LIBRARY_PATH
export INCLUDE=/usr/local/intel-14.0.3.174/14.0.3.174/mkl/include:$STARPU_DIR/include/:$INCLUDE
export PATH=$STARPU_DIR/bin:$PATH
export HWLOC_PLUGINS_PATH=nimportequoi


touch mat_khp_15000mail.glob/mat_khp_15000mail.glob1noeudhybrid2GPUstarpu.res

ccc_mprun -n 1 /ccc/cont003/home/gen1567/terrazt/pastix_5.2.2.22/src/example/bin/simple -v 3 -t 6 -mm /ccc/work/cont003/gen1567/terrazt/matrices/mat_khp_15000mail.glob.mm -iparm IPARM_STARPU API_YES -iparm IPARM_CUDA_NBR 2 -iparm IPARM_GPU_CRITERIUM 2 -iparm IPARM_DEFAULT_ORDERING API_NO -iparm IPARM_ORDERING_CMIN 20 -iparm IPARM_MIN_BLOCKSIZE 60 -iparm IPARM_MAX_BLOCKSIZE 120 -iparm IPARM_FACTORIZATION API_FACT_LU > mat_khp_15000mail.glob/mat_khp_15000mail.glob1noeudhybrid0GPUstarpu.res
