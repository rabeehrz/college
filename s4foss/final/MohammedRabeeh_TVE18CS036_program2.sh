#!/bin/bash
# Program Name: MohammedRabeeh_TVE18CS036_program2.sh
# Author: Mohammed Rabeeh
# Date: 24th July 2020
# OS: macOS Catalina 10.15.3
# Shell: zsh
# Function: To print name of the file that contains lines longer then n chars. 
# Input: ./MohammedRabeeh_TVE18CS036_program2.sh n

if [ -z "$1" ]; then
  echo "USAGE: $0 n"
  exit
fi

for filename in *.txt; do
    [ -e "$filename" ] || continue
    c=`grep ".\{$(($1 + 1))\}" $filename | wc -l`
    if [ $c -ne 0 ]; then
      echo $filename
    fi
done
