#!/bin/bash


for i in 2 5 10 20 30 40 50; do
    for j in 100 200 300 400 500; do

            ggen static-graph forkjoin $i $j -o ./dot/forkjoin-$i-$j.dot

    done
done
