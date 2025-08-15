#!/bin/sh

temp_output="t_result_concat.csv"

> "$temp_output"

for file in *.csv; do
    if [ "$file" != "$temp_output" ]; then
        head -n 1 "$file" > "$temp_output"
        break
    fi
done

for file in *.csv; do
    if [ "$file" != "$temp_output" ]; then
        tail -n +2 "$file" | awk -F',' '{
            printf "%s,\"%s\",%s,%s,%s\n", $1, $2, $3, $4, $5
        }'
    fi
done | sort -u >> "$temp_output"

output="result_concat.csv"

head -n 1 $temp_output > $output

tail -n +2 $temp_output | sort -t, -k2,2 -k1,1 >> $output

rm "$temp_output"

echo "Output: $output"