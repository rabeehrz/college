#!/bin/bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Displays a list of all the files in the current directory
#           to which the user has read, write and execute permissions.
# Syntax: ./7.sh file

for file in *
do
	if [ -r $file -a -w $file -a -x $file ]
    then
        echo $file
    fi
done