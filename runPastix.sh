#!/bin/bash

STARPU_HOSTNAME=supermicro
STARPU_PERF_MODEL_DIR=./morse_tutorial/chameleon/perfmodels/.starpu/sampling/
STARPU_FXT_PREFIX=./

CPUExecution= '-t 20'

GPUExecution='-iparm IPARM_CUDA_NBR 4 -iparm IPARM_GPU_CRITERIUM 4'

PASTIX_DIR=`spack location -i pastix@develop~mpi+starpu+cuda^starpu@svn-trunk+fxt+cuda`

declare -a apps=( backward_only forward_backward forward_only reentrant simple )

declare -a Matriz=( af_shell10  )

declare -a TILES=( 64  )

declare -a sizes=( 960  )

for app in "${apps[@]}"; do
    mkdir -p data/${app}
	for TILE in "${TILES[@]}"; do
        for i in "${sizes[@]}"; do
			PARAMS_TRACE=" ${CPUExecution} -v 1  -lap ${i} -iparm IPARM_STARPU API_YES -iparm IPARM_MIN_BLOCKSIZE ${TILE} -iparm IPARM_MAX_BLOCKSIZE $((TILE + 60)) -iparm IPARM_DEFAULT_ORDERING API_NO -iparm IPARM_ORDERING_CMIN 20 ${GPUExecution}"
			
			STARPU_GENERATE_TRACE=1 ${PASTIX_DIR}/examples/${app} $PARAMS_TRACE;			
			mv paje.trace  ./data/${app}/${app}-${TILE}-${i}.trace;
            mv trace.html ./data/${app}/${app}-${TILE}-${i}-trace.html;
            mv tasks.rec ./data/${app}/${app}-${TILE}-${i}-tasks.rec;
            mv dag.dot ./data/${app}/${app}-${TILE}-${i}-dag.dot;
            mv trace.rec ./data/${app}/${app}-${TILE}-${i}-trace.rec;
            mv activity.data ./data/${app}/${app}-${TILE}-${i}-activity.data;
            mv distrib.data ./data/${app}/${app}-${TILE}-${i}-distrib.data;
            
		done

        for i in "${Matriz[@]}" ; do
			PARAMS_TRACE=" ${CPUExecution}  -v 1 -mm ./Matrices/${i}/${i}.mtx -iparm IPARM_STARPU API_YES -iparm IPARM_MIN_BLOCKSIZE ${TILE} -iparm IPARM_MAX_BLOCKSIZE $((TILE + 60)) -iparm IPARM_DEFAULT_ORDERING API_NO -iparm IPARM_ORDERING_CMIN 20 ${GPUExecution}"			

            STARPU_GENERATE_TRACE=1 ${PASTIX_DIR}/examples/${app} $PARAMS_TRACE;			
			mv paje.trace  ./data/${app}/${app}-${TILE}-${i}.trace;
            mv trace.html ./data/${app}/${app}-${TILE}-${i}-trace.html;
            mv tasks.rec ./data/${app}/${app}-${TILE}-${i}-tasks.rec;
            mv dag.dot ./data/${app}/${app}-${TILE}-${i}-dag.dot;
            mv trace.rec ./data/${app}/${app}-${TILE}-${i}-trace.rec;
            mv activity.data ./data/${app}/${app}-${TILE}-${i}-activity.data;
            mv distrib.data ./data/${app}/${app}-${TILE}-${i}-distrib.data;
        done
	done
done


for app in "${apps[@]}"; do
    mkdir -p data/${app}

	for TILE in 64 128 256 320 512 640 768 960; do
			
            

	done
done 

