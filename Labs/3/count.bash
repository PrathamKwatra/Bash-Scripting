#!/bin/bash 
#
# Pratham Kwatra
# 9/10/2020 [DATE/MONTH/YEAR]
# 
# Platform: Linux tux1 5.4.0-48-generic #52-Ubuntu SMP Thu Sep 10 10:58:49 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux
# 
# EDITOR: tabs=3, cols=120 (checked with echo $COLUMNS)  
#	
# count.bash file
#

debugOn="n"

read -p "Do you want to see the script as it executes? (y/[n]) => " \
   debugOn
if [ "$debugOn" == "y" -o "$debugOn" == "Y" ] ; then
	set -x      # very useful switch to the set command
fi

echo "Hello $USER"

echo "I am going to print filenames, the # of lines and the # of words on your displays"

for file in *; 
	do 
		if [ -f "$file" ]; then 
		words_lines=$(wc -l -w "$file")
#		echo ${words_lines%$file*}
		echo "$file" ${words_lines%$file*}; fi 
		done  
