#!/bin/bash

./run input.txt 0 | awk 'BEGIN{i = 1} {if(i!=1){print $0;}i++;}' > output.txt
gnuplot <<- EOF
            set xlabel "n"
            set ylabel "ms"
            set title "runtime vs input size"
            set term png
            set output "output.png"
            plot "output.txt"
EOF
