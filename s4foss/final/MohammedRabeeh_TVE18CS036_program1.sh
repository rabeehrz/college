#!/bin/bash
# Program Name: MohammedRabeeh_TVE18CS036_program1.sh
# Author: Mohammed Rabeeh
# Date: 24th July 2020
# OS: macOS Catalina 10.15.3
# Shell: zsh
# Function: To find the sum of all the multiples of 3 or 5 below an integer n (10 <= n <= 10000). 
# Input: ./MohammedRabeeh_TVE18CS036_program1.sh n

if [ -z "$1" ]; then
  echo "USAGE: $0 n"
  exit
fi
sum=0
for ((i = 0 ; i < $1 ; i++)); do
  if [ $((i%3)) -eq 0 -o $((i%5)) -eq 0 ]; then
    sum=$((sum + i))
  fi
done
echo $sum