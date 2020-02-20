#!/bin/bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Count vowels, blank spaces, characters,
#           number of line and symbols in a file.
# Syntax: ./4.sh file1 file2


file=$1
v=0

if [ $# -ne 1 ]
then
 echo "Yyntax:$0 fileName"
 exit 1
fi
if [ ! -f $file ]
then
 echo "$file isn't a valid file."
 exit 2
fi

# read vowels
exec 3<&0
while read -n 1 c
do
  l="$(echo $c | tr '[A-Z]' '[a-z]')"
  [ "$l" == "a" -o "$l" == "e" -o "$l" == "i" -o "$l" == "o" -o "$l" == "u" ] && (( v++ )) || :
done < $file

echo "Vowels : $v"
echo "Characters : $(cat $file | wc -c | sed -e 's/^[[:space:]]*//')"
echo "Blank spaces : $(grep -o ' ' $file | wc -l | sed -e 's/^[[:space:]]*//')"
echo "Lines : $(cat $file|wc -l | sed -e 's/^[[:space:]]*//')"