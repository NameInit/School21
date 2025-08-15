#!/bin/sh

input="../ex02/hh_sorted.csv"
output="hh_positions.csv"

head -n 1 $input > $output

tail -n +2 "$input" | while IFS= read -r line
do
  id=$(echo "$line" | awk -F',' '{print $1}')
  created_at=$(echo "$line" | awk -F',' '{print $2}')
  name=$(echo "$line" | awk -F',' '{for (i=3; i<=NF-2; i++) printf $i ","; printf $(NF-2)}' | sed 's/,$//')
  has_test=$(echo "$line" | awk -F',' '{print $(NF-1)}')
  alternate_url=$(echo "$line" | awk -F',' '{print $NF}')

  position=$(echo "$name" | grep -oE "\b(Junior|Middle|Senior)\b" | head -n 1)

  [ -z "$position" ] && position="-"

  echo "$id,$created_at,\"$position\",$has_test,$alternate_url" >> "$output"
done

echo "Output: $output"