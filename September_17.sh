# September 17

# Wildcards and Globbing --------------------------------

ls *.txt 			# see text files in current directory
*.txt 				# is a glob pattern 
example*.txt 		# wildcard can be inserted anywhere
?.txt 				# matches one character
ls badname* 		# > ls: badname*: No such file or directory

echo '*.txt' 		# both quotes supress expansion of globs (see Quoting)
echo "*.txt"		# literally print *.txt

# Shell Variables ---------------------------------------

COURSE_NAME			# variable
COURSE_NAME=CS246 	# variables defined using = (NO spaces!)

echo $COURSE_NAME	# retrieve variable value using $
${COURSE_NAME}		# good practice 

dir1=~/Teaching 
echo ${dir1}		# > /Users/lucy/Teaching

first_nm=lucy 
echo ${first_nm}yu 	# > lucyyyu

PATH				# several global variables are set up for you 
CLASSPATH			# java
0					# currently running script 

# Quoting ----------------------------------------------

echo '${PATH}'		# protect eveyrthing (even newline) except single quote
					# > ${PATH}

echo "${PATH}"		# protect everything except double quote, backquote, and dollar sign
					# will output the same as echo ${PATH}

# Working with Files, I/O Redirection --------------------

cat 				# displays the contents of a file
					# if no parameters are specified, cat waits for input from standard input
					# CTRL-D is EOF

# in general, command args > file

cat > output.txt 	# standard input will write to example.txt until EOF

cat < input.txt 	# input can also be redirected
					# shows contents of input.txt
cat input.txt 		# different

cat < myfile > myfile_redirected

# Standard Streams --------------------------------------

# every process is attached to 3 streams
# 	stdin -> program -> stderr (2)
# 				   	 -> stout  (1)

# stderr vs. stdout
# 	separate output stream for error messages; avoid cluttering output files/corrupting formatting
# 	stdout may be buffered, but stderr is never buffered 

program < in.txt > out.txt 2> error.txt
program < in.txt 1> out.txt 2> error.txt

# Pipes --------------------------------------------------

| 					# makes standard output for a command the standard input for the next command
					# wihtout creating intermediate file

# --------------------------------------------------------
# Question: can we use the output of one program as the parameter of another program? 





