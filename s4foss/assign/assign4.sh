#!/bin/sh

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Compares the contents of two files and deletes
#			the duplicate
# Syntax: ./4.sh file1 file2

if [ $# -ne 2 ]
then
	echo "Syntax: ./4.sh file1 file2"
elif [ ! -e $1 -o ! -e $2 ]
then
	echo "File does not exist."
else
	ans="$(diff -q $1 $2 | wc -l)"
	if (( ans < 1 ))
	then
		echo "File are same. Deleting $2"
		rm $2
	else
		echo "Files are different."
	fi
fi