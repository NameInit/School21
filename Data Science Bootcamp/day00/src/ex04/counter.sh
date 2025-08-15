#!/bin/bash

input='../ex03/hh_positions.csv'
output='hh_uniq_positions.csv'

positions=$(tail -n +2 "$input" | awk -F',' '{print $3}' | tr -d '"')

junior_count=$(grep -i 'Junior' <<< "$positions" | wc -l)
middle_count=$(grep -i 'Middle' <<< "$positions" | wc -l)
senior_count=$(grep -i 'Senior' <<< "$positions" | wc -l)
dash_count=$(grep -i '^-$' <<< "$positions" | wc -l)

echo '"name","count"' > "$output"
echo '"Junior",'$junior_count >> "$output"
echo '"Middle",'$middle_count >> "$output"
echo '"Senior",'$senior_count >> "$output"

echo "Output: $output"