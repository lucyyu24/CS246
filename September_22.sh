# September 22

# Pipes ---------------------------------------------

head -20 myfile.txt | wc -w  # how many words occur in the first 20 lines of a file
							 # head -20 myfile.txt outputs the first 20 lines of myfile.txt to wc -w
cat words*.txt | sort | uniq # pint a duplication-free list of all the words that occur in any of a set of files
							 # e.g., there exists words1.txt, words2.txt, words3.txt

# Backquotes ----------------------------------------

# can we use the ouput of one program as the parameter of another program?

echo "Today is" `date` "and I am " `whoami`
echo "Today is `date` and I am `whoami`" 
echo "Today is $(date) and I am $(whoami)"

# The grep Ccommand ---------------------------------

grep   # global regular expression print
egrep  # extended grep, equiv: grep -E

egrep pattern file	# general usage	
				 	# print every line in file that contains pattern

egrep cs246 index.shtml | wc -l # number of lines in index.shtml that contains 'cs246'

# Regular Expressions -------------------------------

# not the same as glob patterns

# [0-9] [a-z] range patterns

egrep "cs246|CS246" index.html # | means OR
egrep "(cs|CS)246" index.html  # these two statements are equivalent

egrep "(c|C)(s|S)246" index.html # will match cs246, CS246, cS246, Cs246
egrep "[cC][sS]246" index.html

egrep "[cC][sS] ?246" index.html # ? means 0 or 1 of the preceding expression
								 # matches CS 246, cs246, etc.

egrep "(cs)*246" index.html # 0 or more of the preceding expression
							# matches 246, cs246, cscs246, cscscs246

egrep "(cs).*246" index.html # . means any character
							 # .* means any sequence of characters
							 # matches lines that contain a string that starts with cs and ends with 246

# ^ beginning of line and $ end of line
egrep "^cs246" index.html # lines that start with cs246
egrep "^cs246$" index.html # lines that contain just cs246

# + matchs 1 or more occurances of the preceding pattern
egrep "^.+$" index.html # matches all non-blank lines

egrep "^(..)*$" index.html # print all lines of even length

ls | egrep "^[^a]*a[^a]*$" # print all files in the current directory whose names contain exactly one a
						   # any character but a: [^a] ^ in [] means negation

egrep "^e....$" /user/share/dict/words # print all the words in the global dictionary (/usr/share/dict/words) that start with e and consist of 5 characters

# File Permissions ----------------------------------

ls -l # gives a long form directory listing

drwxr-xr-x 5 chenzhang staff 170 Sep 16 11:00 words
# type/permissions #links owner group size last-modified-date-and-time name

# Permissions: 3 groups of 3 bits
rwxr-xr-- # user bits, group bits, other bits

# bit | meaning for ordinary files | meaning for directories
# ---- ---------------------------- ------------------------
# r   | file's contents can be read| directory's conentes can be read (can ls)
# w   | .. modified                | .. modified
# x   | .. excuted as a program    | .. navigated (can cd)


# the chmod command ----------------------------------

chmod mode file # general form for changing a file's permission
# ownership class: u,g,o,a
# operator: +,-,=
# permissions: r,w,x

chmod o+r file 	# give others read permission
chmod g-x file  # revoke execute permission from group
chmod a=rx file # make everyone's permission rx
chmod u+rwx file # give owner full control







