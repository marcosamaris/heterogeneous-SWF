#!/bin/bash

declare -a apps=(sgeqrf)


for app in "${apps[@]}"; do
    for TILE in 64 128 256 320 512 640 768 960; do
        for i in 1 8 20 50 100; do

            bash ./morse_tutorial/chameleon/paje2csv.sh ./data/${app}/${app}-${TILE}-${i}.trace ./data/${app}/${app}-${TILE}-${i}.csv;
            
        done
    done
done
