#!/bin/bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Compares two directories and copies the files
#           not present in dir2 to it.
# Syntax: ./2.sh dir1 dir2
for file_1 in $( find DIR_1/* -type f | sed 's/\.\.\///g' )
do
        file_2=$( echo $file_1 | sed 's/DIR_1/DIR_2/g' )
        dir_2=$( dirname $file_2 )

        if [ ! -d $dir_2 ]
        then
                echo -e "DIR: $dir_2 does not exist. Creating...\c"
                mkdir -p $dir_2
                echo "Done"
        fi

        if [ -f $file_2 ]
        then
                cksum_file_1=$( cksum $file_1 | cut -f 1 -d " " )
                cksum_file_2=$( cksum $file_2 | cut -f 1 -d " " )

                if [ $cksum_file_1 -ne $cksum_file_2 ]
                then
                        echo -e "FILE: $file_1 is modified. Copying..\c"
                        cp $file_1 $file_2
                        echo "Done"
                fi
        else
                echo -e "FILE: $file_2 does not exist. Copying...\c"
                cp $file_1 $file_2
        fi
done
echo "Program executed."