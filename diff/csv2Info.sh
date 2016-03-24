#!/bin/bash

declare -a apps=(sgetrf_nopiv sgetrs_nopiv slange sposv spotrf spotri spotrs)

for app in "${apps[@]}"; do
    mkdir -p ./CPU-GPU/${app}
    for TILE in 64 128 256 320 512 640 768 960 ; do
        for i in 1 5 10 20 50 100; do
            CPUinputfile=./CPU/${app}/${app}-${TILE}-${i}.csv
            GPUinputfile=./GPU/${app}/${app}-${TILE}-${i}.csv            
            outputfile=./CPU-GPU/${app}/${app}-${TILE}-${i}.csv
            if [ -f $CPUinputfile ] && [ -f $GPUinputfile ];
                then                
                paste $CPUinputfile $GPUinputfile > Temp 
                cat Temp | awk '{print $0, $5 - $1}' > $outputfile 
            fi
            
        done
    done
done

