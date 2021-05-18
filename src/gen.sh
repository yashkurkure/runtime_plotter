#!/bin/bash

h=1000
for((c = 1; c <= 30; c++))
do


    a=$( for((j = 1; j <= $h; j++)) ; do echo $((RANDOM % 1000)); done | awk -vORS=',' '{print $0}' | sed 's/,$/\n/' )
    echo $a
    ((h = h+100))

done