#!/usr/bin/awk -f

# Author: Mohammed Rabeeh
# Date: 6th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Remove duplicate lines from text and prints it.
# Syntax: ./2.awk filename

!already_present[$0]++ {print $0}
