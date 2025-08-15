#!/bin/bash

input=../ex00/hh.json
output=hh.csv
filter=filter.jq
echo '"id","created_at","name","has_test","alternate_url"' > $output
jq -r -f $filter $input | jq -r '[.id, .created_at, .name, .has_test, .alternate_url] | @csv' >> $output

echo "Output: $output"