#!/bin/bash


input='../ex01/hh.csv'
output='hh_sorted.csv'

head -n 1 $input > $output

tail -n +2 $input | sort -t, -k2,2 -k1,1 >> $output

echo "Output: $output"