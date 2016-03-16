#!/bin/bash

#export WORKDIR=$PWD

. ./spack/share/spack/setup-env.sh

source ./morse_tutorial/chameleon/paje2csv.sh
      
STARPU_HOSTNAME=gpu-ccsl
STARPU_PERF_MODEL_DIR=./morse_tutorial/chameleon/perfmodels/.starpu/sampling/
STARPU_FXT_PREFIX=./

CHAMELEON_EXE=`./spack/bin/spack location -i chameleon@trunk+cuda+fxt~quark+examples~shared~simu ^starpu@svn-trunk~shared+cuda+fxt`/lib/chameleon/timing/

declare -a apps=(spotrf sgetrf_nopiv sgeqrf)


for app in "${apps[@]}"; do
    mkdir -p data/${app}    
    for TILE in 64 128 256 320 512 640 768 960; do
        for i in 1 8 20 50 100; do    
            #PARAMS_FLOPS="--n_range=$((${TILE}*${i})):$((${TILE}*${i})):$((${TILE}*${i})) --nb=${TILE} --threads=8 --printerrors --nowarmup --check"
            PARAMS_TRACE="--n_range=$((${TILE}*${i})):$((${TILE}*${i})):$((${TILE}*${i})) --nb=${TILE} --threads=8 --printerrors --nowarmup --trace"

            #${CHAMELEON_EXE}time_${app}_tile $PARAMS_FLOPS | tee ./${app}/${app}_gflops_out;
            STARPU_GENERATE_TRACE=1 ${CHAMELEON_EXE}time_${app}_tile $PARAMS_TRACE;

            mv paje.trace  ./data/${app}/${app}-${TILE}-${i}.trace; 
            mv trace.html ./data/${app}/${app}-${TILE}-${i}trace.html; 
            mv tasks.rec ./data/${app}/${app}-${TILE}-${i}tasks.rec;
            mv dag.dot ./data/${app}/${app}-${TILE}-${i}dag.dot; 
            mv trace.rec ./data/${app}/${app}-${TILE}-${i}trace.rec;
            mv activity.data ./data/${app}/${app}-${TILE}-${i}activity.data;
            mv distrib.data ./data/${app}/${app}-${TILE}-${i}distrib.data;
            mv starpu_idle_microsec.log ./data/${app}/${app}-${TILE}-${i}starpu_idle_microsec.log
            mv prof_file_marcos_0 ./data/${app}/${app}-${TILE}-${i}prof_file_marcos_0
        done
    done
done



