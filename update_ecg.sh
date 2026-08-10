#!/bin/bash

heart=70
high=120
low=80

while true
do
  change=$((RANDOM % 11 -5))
  heart=$((heart + change))

  if [ $heart -lt 60 ]; then
    heart=60
  fi

  if [ $heart -gt 100 ]; then
    heart=100
  fi

  high_change=$((RANDOM % 7 - 3))
  high=$((high + high_change))

  low_change=$((RANDOM % 5 - 2))
  low=$((low + low_change))

  if [ $high -lt 100 ]; then
    high=100
  fi

  if [ $high -gt 140 ]; then
    high=140
  fi

  if [ $low -lt 60 ]; then 
    low=60
  fi
  
  if [ $low -gt 90 ]; then
    low=90
  fi

  echo "田中太郎,$heart,$high,$low" > ecg.csv

  sleep 1
done

