#!/bin/bash

declare -a apps=(sgetrf_nopiv sgetrs_nopiv slange sposv spotrf spotri spotrs)

for app in "${apps[@]}"; do
    mkdir -p ./task/${app}
    for TILE in 64 128 256 320 512 640 768 960 ; do
        for i in 1 5 10 20 50 100; do
            inputfile=./data/${app}/${app}-${TILE}-${i}tasks.rec           
            outputfile=./task/${app}/${app}-${TILE}-${i}.txt
            if [ -f $inputfile ];
                then
                 cat $inputfile | sed -n '/^DependsOn\|^JobId/p' | sed  's/JobId: //g' | sed  ':a;N;$!ba;s/\nDependsOn: /,/g' > $outputfile
            fi
            
        done
    done
done
    

