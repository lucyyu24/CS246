# September 24

# Shell Scripts -------------------------------------

# files that contain sequences of Linux commands, executed as programs

# Special Variables ---------------------------------

# accept arguments from the command line
$0, $1, $2, $3
$# # number of arguments, excluding $0 
$@ # all arguments (except $0) as separate strings

# Return codes --------------------------------------

# every program returns a status code when finished
# in Unix, 0 is success, non-zero is failure
$?  # status of most recently executed command

# if: semantics -------------------------------------

# if execute commands once if the test commands succeed (return code is 0)

if test-commands; then
		commands
	[elif more-test-commands; then more-commands]
	[else alternate-commands]
fi

# while: semantics ---------------------------------

while test-commands;
do 
	commands
done

# for: semantics -----------------------------------

for name in [list];
do 
	commands
done

# Arithmetic with shell variables ------------------

$(( express )) # to evaluate arithmetic expressions

# Bash Procedures ----------------------------------

function function_name {    # equivalent forms
	commands
}

function_name () {
	commands
}

# Examples ------------------------------------------

#!/bin/bash
echo "Script name: ${0}"
echo "First arg: ${1}"
echo "Num of args: ${#}"
echo "All args: ${@}"
n=4
echo "Fourth arg: ${!n}" # outputs the argument 4
echo "Fourth arg: ${!4}" # undefined 

#!/bin/bash

#function "usage"
usage () {
	echo "Usage: $0 password"
}

# check the number of arguments greater than 1
if [  $# -ne 1 ]; then
	usage 
	exit 1
fi

# try to match words in a dictionary
egrep "^$1$" /usr/share/dict/words > /dev/null

# output message
if [ $? -eq 0 ]; then
	echo Not a good password
else 
	echo Maybe a good password
fi

#!/bin/bash

# list of files with .cpp 
for name in *.cpp; do 
	mv ${name} ${name%cpp}cc 
done

#!/bin/bash

x=0

for word in `cat $2`; do 
	if [ $word = $1 ]; then
			x=$((x+1))
	fi
done

echo $x

#!/bin/bash

answer () {
	if [ $1 -eq 31 ]; then
		echo "This month: on the ${1}st."
	else 
		echo "This month: on the ${1}th."
	fi
}

answer `cal | awk '{print $6}' | grep "[0-9]" | tail -1` 

#!/bin/bash

answer () {
	if [$2]; then
		preamble=$2
	else 
		preamble="This month"
	fi 

	if [$1 -eq 31]; then
		echo "${preamble}: on the ${1}st."
	else
		echo "${preamble}: on the ${1}th."
	fi
}

answer `cal $1 $2 | awk '{print $6}' | grep "[0-9]" | tail -1` $1




