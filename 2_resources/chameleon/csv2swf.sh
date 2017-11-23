#!/bin/bash


declare -a apps=( sgetrf_nopiv sgetrs_nopiv slange sposv spotrf spotri spotrs )

	for app in "${apps[@]}"; do
		mkdir -p swf/CPU/${app}
		mkdir -p swf/GPU/${app}
		mkdir -p diff/${app}
		for TILE in 64 128  256 320 512 640 768 960; do
			for i in 1 5 10 20 50 100; do
				CPUinputfile=./csv/CPU/${app}/${app}-${TILE}-${i}.csv
				GPUinputfile=./csv/GPU/${app}/${app}-${TILE}-${i}.csv
				CPUoutputfile=./swf/CPU/${app}/${app}-${TILE}-${i}.swf
				GPUoutputfile=./swf/GPU/${app}/${app}-${TILE}-${i}.swf
				Tempoutputfile=diff/${app}/${app}-${TILE}-${i}.csv
				if [ -f $inputfile ];
					then                
					grep  M[0-9]*x[0-9]*x[0-9]* $CPUinputfile | sed 's/,//g' | sort -k11 -n | awk '{print $2, $7, $11, $9}' > TempCPU
					grep  M[0-9]*x[0-9]*x[0-9]* $GPUinputfile | sed 's/,//g' | sort -k11 -n | awk '{print $9, $2, $7, $11}' > TempGPU
					
					cat TempGPU | sed  's/CPU[0-9] [0-9]*.[0-9]*/CPU -1/g' > TempGPU1 
					
					paste -d " " TempCPU TempGPU1 | awk '{print $0, $8-$3}' > $Tempoutputfile
					
					cat $Tempoutputfile  | awk '{print $3, -1, -1, $2, -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1, -1, -1, -1, -1, -1}' > $CPUoutputfile
					cat $Tempoutputfile  | awk '{print $8-$9, -1, -1, $7, -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1, -1, -1, -1, -1, -1}' > $GPUoutputfile
				fi
				
			done
		done
	done
	rm TempCPU TempGPU TempGPU1
