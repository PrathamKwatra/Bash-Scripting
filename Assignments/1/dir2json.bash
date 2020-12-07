#!/bin/bash
#dir2json.awk
#
#
#
# Editor: tabstop=2, cols = 120
#


debugOn="n"

read -p "Do you want to see the script as it executes? (y/[n]) => " \
   debugOn
	if [ "$debugOn" == "y" -o "$debugOn" == "Y" ] ; then
		   set -x      # very useful switch to the set command
	fi

checkInArray(){
	localArray=$1
	givenValue=$2
	if [[ "${localArray[@]}" =~ "${givenValue}" ]]; then
		    return 0 
		else
			return 2
	fi
}



requiredArray=()

ls README

if [ $? -eq 0 ]
	then
		index=$(awk -F":" '$1=="index" {print $NF}' README)
		required=$(awk -F":" '$1=="required" {for (i=2; i<=NF; i++) print $i}' README)
		required=$(echo $required)
		while [ "$required" != "${required#* }" ]; do requiredArray+=" ${required#* }"
												required=${required% *}; done
		requiredArray+=" $required"
		requiredArray+=" $index"
		echo $index
		echo $required
		echo $requiredArray
	else
		index=""
		required=""
	fi


files=()
directories=()
otherFiles=()
otherDirectory=()

for thing in $( ls -A )
	do 
		if checkInArray "$requiredArray" "$thing"
			then 
				if [ -d "$thing" ] 
					then directories+=" $thing"
				else 
					if [ "$thing" != "$index" ]; then
						files+=" $thing"; fi
				fi
		elif [ -f "$thing" ]
			then otherFiles+=" $thing"
		else
			otherDirectory+=" $thing"
		fi
	done

stringArray(){
	array=${!1}
	lastEle=$2
	STRING=''
	for n in ${array[@]}; do
		if [ "$n" != "$lastEle" ]; then
		STRING+="\"$n\", "
		else
		STRING+="\"$n\""
   fi
	done
	echo $STRING
	}
stringFiles=$( stringArray "files" "${files##* }")
stringDir=$( stringArray "directories" "${directories##* }")
stringOD=$( stringArray "otherDirectory" "${otherDirectory##* }")
stringOF=$( stringArray "otherFiles" "${otherFiles##* }")

echo "{
  \"index\" : \"$index\",
    \"required\" : {
      \"files\": [$stringFiles],
      \"directories\" : [$stringDir]
   },
  \"other\" : {
    \"files\": [$stringOF], 
    \"directories\" : [$stringOD]
    }
}" > dir.json


