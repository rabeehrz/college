#!/usr/bin/awk -f

# Author: Mohammed Rabeeh
# Date: 6th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Formats the date from dd-mm-yyyy format to Day, Month and Year
# Input: Date in dd-mm-yyyy format

BEGIN{
	FS="-"
	print "Enter the date in dd-mm-yyyy format: "
	getline < "/dev/tty"

	if((($3%4!=0) && ($2==2) && ($1>28)) || 
	  (($3%4==0) && ($2==2) && ($1>29)) || 
	  $2 > 12)

	    print"Invalid date\n"

	else
	{
		split("January February March April May June July August September October November December", month, " ")
		print "Day: " $1
		print "Month: " month[$2]
		print "Year: " $3
	}

}
