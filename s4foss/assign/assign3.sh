#!/bin/bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Compares the permissions of two files
# Syntax: ./3.sh file1 file2

if [ $# -ne 2 ]
then
	echo "Syntax: ./3.sh file1 file2"
elif [ ! -e $1 -o ! -e $2 ]
then
	echo "File does not exist."
else
	p1=`ls -l $1|cut -c2-10`
	p2=`ls -l $2|cut -c2-10`
	if [ $p1 == $p2 ]
	then
		echo "File permissions are equal & is $p1"
	else
		echo "File permissions are not equal"
		echo "1st file $p1"
		echo "2nd file $p2"
	fi
fi