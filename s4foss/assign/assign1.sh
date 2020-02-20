#!/usr/bin/env bash

# Author: Mohammed Rabeeh
# Date: 8th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Shows permission, size, file name and
#           last modification time of files.
# Syntax: ./1.sh

(printf "PERM LINKS OWNER GROUP SIZE MONTH DAY " ; \
           printf "MODTIME FILENAME\n" ; \
           ls -lh | sed 1d) | awk '{print $1 " " $5 " " $8 " " $9}' | column -t
