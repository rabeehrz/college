#!/bin/bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Remove lines containing a word from multiple files
# Syntax: ./7.sh file

if [ $# -eq 0 ]
then
    echo "ERROR: Please enter one or more filenames as argument."
    exit
fi

echo "Enter the word to be searched in files:"
read word
for file in $*
do
    sed -ie "/$word/d" $file
done