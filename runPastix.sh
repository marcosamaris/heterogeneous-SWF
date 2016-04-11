#!/bin/bash

STARPU_HOSTNAME=supermicro
STARPU_PERF_MODEL_DIR=./morse_tutorial/chameleon/perfmodels/.starpu/sampling/
STARPU_FXT_PREFIX=./

CPUExecution='-t 40'

GPUExecution='-iparm IPARM_CUDA_NBR 4 -iparm IPARM_GPU_CRITERIUM 4'

PASTIX_DIR=`spack location -i pastix@develop~mpi+starpu+cuda^starpu@svn-trunk+fxt+cuda`

declare -a apps=( ssimple dsimple zsimple  )

declare -a TILES=( 60 120 240 360 600 720 960  )

declare -a sizes=( 960 4800  9600 48000 96000)

for app in "${apps[@]}"; do
    mkdir -p data/${app}
	for TILE in "${TILES[@]}"; do
        for i in "${sizes[@]}"; do
			PARAMS_TRACE=" ${CPUExecution} -v 1  -lap ${i} -iparm IPARM_STARPU API_YES -iparm IPARM_MIN_BLOCKSIZE ${TILE} -iparm IPARM_MAX_BLOCKSIZE $((TILE + 60)) -iparm IPARM_DEFAULT_ORDERING API_NO -iparm IPARM_ORDERING_CMIN 20 ${GPUExecution} -iparm IPARM_FACTORIZATION API_FACT_LU"
            
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


#-iparm IPARM_FACTORIZATION API_FACT_LU
#-iparm IPARM_FACTORIZATION API_FACT_LLT
#-iparm IPARM_FACTORIZATION API_FACT_LDLT

declare -a Matriz=( af_shell10  audikw_1 dielFilterV2clx Flan_1565 Geo_1438 Hook_1498 Serena )

for TILE in "${TILES[@]}"; do
	for i in "${Matriz[@]}" ; do
		PARAMS_TRACE=" ${CPUExecution}  -v 1 -mm ./Matrices/${i}/${i}.mtx -iparm IPARM_STARPU API_YES -iparm IPARM_MIN_BLOCKSIZE ${TILE} -iparm IPARM_MAX_BLOCKSIZE $((TILE + 60)) -iparm IPARM_DEFAULT_ORDERING API_NO -iparm IPARM_ORDERING_CMIN 20 ${GPUExecution} -iparm IPARM_FACTORIZATION API_FACT_LU"					

        if [ ${i} == 'dielFilterV2clx' ];
        then
            app='zsimple'
        else
            app='dsimple'
        fi        
            
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

declare -a Matriz=( audikw_1 Flan_1565 Geo_1438 Serena )
app=dsimple

for TILE in "${TILES[@]}"; do
	for i in "${Matriz[@]}" ; do
    
        if [ ${i} == 'Serena' ];
        then
            factParam='API_FACT_LDLT'
        else
            factParam='API_FACT_LLT'
        fi     

        PARAMS_TRACE=" ${CPUExecution}  -v 1 -mm ./Matrices/${i}/${i}.mtx -iparm IPARM_STARPU API_YES -iparm IPARM_MIN_BLOCKSIZE ${TILE} -iparm IPARM_MAX_BLOCKSIZE $((TILE + 60)) -iparm IPARM_DEFAULT_ORDERING API_NO -iparm IPARM_ORDERING_CMIN 20 ${GPUExecution} -iparm IPARM_FACTORIZATION ${factParam}"					

        STARPU_GENERATE_TRACE=1 ${PASTIX_DIR}/examples/${app} $PARAMS_TRACE;
        			
		mv paje.trace  ./data/${app}/${app}-${TILE}-${i}-${factParam}.trace;
		mv trace.html ./data/${app}/${app}-${TILE}-${i}-${factParam}-trace.html;
		mv tasks.rec ./data/${app}/${app}-${TILE}-${i}-${factParam}-tasks.rec;
		mv dag.dot ./data/${app}/${app}-${TILE}-${i}-${factParam}-dag.dot;
		mv trace.rec ./data/${app}/${app}-${TILE}-${i}-${factParam}-trace.rec;
		mv activity.data ./data/${app}/${app}-${TILE}-${i}-${factParam}-activity.data;
		mv distrib.data ./data/${app}/${app}-${TILE}-${i}-${factParam}-distrib.data;
	done
done



