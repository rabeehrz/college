#!/usr/bin/awk -f

# Author: Mohammed Rabeeh
# Date: 6th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Takes basic salary of an employee and calculates the
#           gross salary of the employee.
# Input: basic salary

BEGIN{
    print "Enter the Basic Salary: ";
    getline < "/dev/tty";

    if($0<10000){
        DA = 45/100 * $0;
        HRA = 15/100 * $0;
        print "Your DA is 45% and HRA is 15%"
    }
    else{
        DA = 50/100 * $0;
        HRA = 20/100 * $0;
        print "Your DA is 50% and HRA is 20%"
    }

    gross_sal = $0 + DA + HRA;

    print "Gross Salary = " gross_sal
}

