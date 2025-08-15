#!/bin/sh

input="../ex03/hh_positions.csv"
header=$(head -n 1 "$input")

awk -F',' 'NR > 1 {gsub("\"", "", $2); split($2, date, "T"); print date[1]}' "$input" | sort -u | while read -r date; do
    [ -z "$date" ] && continue
    
    output="${date}.csv"
    
    echo "$header" > "$output"
    
    awk -F',' -v date="$date" -v OFS=',' 'NR > 1 {gsub("\"", "", $2); if ($2 ~ date) print}' "$input" | sort -u >> "$output"
    echo "Output: $output"
done