#!/usr/bin/perl

# Author: Mohammed Rabeeh
# Date: 6th February 2020
# OS: macOS Catalina 10.15.2
# Shell: zsh
# Function: Searches the text file for the following queries
# a) Search for the pattern ‘apple’ in the
#    file and display the number of occurences.
# b) Count the number of words that ends with ‘e’
# c) Count the number of words that starts with ‘ap’
# d) Search for words containing ‘a’ or ‘s’
# e) Search for words containing zero or more occurrence of ‘e’
# f) Search for words containing one or more occurrence of ‘e’
# g) Search for words containing the letters ‘l’ and ‘m’,
#    with any number of characters in between 
# Input: file.txt

open(FH, "file.txt") or die "Couldn't open the file.";
print "Reading file... \n\n";
my $apple_count = 0;
my $e_count = 0;
my $ap_count = 0;
my $as_count = 0;
my $total_count = 0;
my $e_oc_count = 0;
my $lm_count = 0;
@a_s = ();
@e_1 = ();
@l_m = ();
@all = ();
while(my $file = <FH>)  { 
	foreach my $str (split /\s+/, $file) {
		$total_count++;
		push(@all, $str);
        if($str =~ /^apple$/) { 
        	$apple_count++; 
    	}
    	if($str =~ /e$/) {
    		$e_count++;
    	}
    	if($str =~ /^ap/) {
    		$ap_count++;
    	}
    	if($str =~ /[as]/) {
    		push(@a_s, $str);
    		$as_count++;
    	}
    	if($str =~ /e/) {
    		push(@e_1, $str);
    		$e_oc_count++;
    	}
    	if($str =~ /[l]/) {
    			if($str =~ /[m]/) {
		    		push(@l_m, $str);
		    		$lm_count++;
    			}
    	}
    }
    
}

print("Words containing a or s: \n");
$string = join("\n", @a_s);
print("$string\n\n");

print("Words containing 0 or more occurences of e: \n");
$string = join("\n", @all);
print("$string\n\n");

print("Words containing 1 or more occurences of e: \n");
$string = join("\n", @e_1);
print("$string\n\n");


print("Words containing l and m: \n");
$string = join("\n", @l_m);
print("$string\n\n");

print("Words with apple: $apple_count\n");
print("Words ending with e: $e_count\n");
print("Words starting with ap: $ap_count\n");
close; 
