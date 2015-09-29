
# Basic Commands --------------------------------

uniq -c 				# prints out the occurence of CONSECUTIVE duplicate lines
ls -a 					# shows hidden files
egrep "count" *.c 		# combining regex with globbing expression in egrep 

# Redirection -----------------------------------

./printer > out 2>&1	# redirect error and output to the same file
./printer >> out 2> out # this will do the same as above

./printer 2>&1 > out 	# error gets printed to the terminal
						# output gets redirected to "out"
						# because &1 was pointing to stdout

./printer > /dev/null	# /dev/null is a black hole

# Quotes ----------------------------------------

egrep `cat word.txt` /usr/share/dict/words # cat words.txt will run, pattern sent to egrep
echo '`cat word.txt`'  # prints `cat word.txt`; anything within single quotes are taken literally


