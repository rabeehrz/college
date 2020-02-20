#!/usr/bin/awk -f

# Author: Mohammed Rabeeh
# Date: 6th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Calculates no. of books sold in each discipline and in total.
# Syntax: ./3.awk file_input

{
  arr[$1]+=$2;
  total+=$2;
}

END {
    for (i in arr){
        print i " = " arr[i];
    }
    print "Total books = " total
}
