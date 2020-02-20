#!/bin/bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Remove duplicate lines from file.
# Syntax: ./6.sh file

if [ $# -ne 1 ]
then
	echo "Syntax: ./6.sh filename"
elif [ ! -e $1 ]
then
	echo "File does not exist."
else
	sort $1 | uniq
fi