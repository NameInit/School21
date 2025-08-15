#!/bin/bash

VACANCY_NAME='data+scientist'

url="https://api.hh.ru/vacancies?text=$VACANCY_NAME&per_page=20"

curl -s "$url" | jq "." > hh.json

echo "Output: hh.json"