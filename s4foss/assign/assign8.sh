#!/bin/bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Fold file to 40 columns per line
# Syntax: ./7.sh file

if [ $# -ne 1 ]
then
    echo "Syntax: ./8.sh file"
elif [ ! -e $1 ]
then
    echo "File does not exist."
else
    fold -w 39 $1
    echo ""
fi