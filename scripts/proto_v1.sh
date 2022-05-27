#/bin/bash

#####################	P R O T O T Y P E  U P D A T E R	###########################
#
# This script will update your header file with the function prototypes.
#
# Version 1.0. In the header file this script will DELETE your existing prototypes
# before adding the new ones.
#
# !!!!!!!!!!!ATTENTION!!!!!!!!!!!!
#
# DON'T USE THE SCRIPT IF THE PROTOTYPES ARE LONG AND SEPARATED BY COMMA IN TWO LINES.
# 
#####################	  	  B Y  P S K Y T T A		    ###########################

	printf "\n------\033[10GP R O T O\033[22G------\n"
	printf "\nAcquiring all .c prototypes.\n"

# Finding the protoypes using 'ctags -x' and redirecting the output to types.txt file.
# Note that the semicolon is added to each line with 'awk'. Also does the sorting and
# deletes the static functions prototypes. It also adds one extra tab to all 'int'
# prototypes to be Norme compliant.

	ctags -x *.c | awk '{print substr($0, index($0,$4))";"}' > types.txt
	vim +':sort | x' types.txt
	vim +':%s/int\t/int\t\t/ | x' types.txt

# Uncomment below to inspect the file content.
	#cat types.txt

# Removing 'static' and main() from the output.
	printf ":g/static/d\n:g/main(/d\nZZ" > cmds.keys
	vim -s cmds.keys types.txt
	echo "" >> types.txt
	
# Printing the vim commands into cmds.keys file. Vim will run these commands
# to the header file.

	printf ":g/);/d\n:r types.txt\ngg\n:/);/\nkdd\nZZ" > cmds.keys

# Uncomment below to see the file contents.
	#cat cmds.keys
	echo ""

# Inserting the prototypes with 'vim -s <filename> <filename>' first file being the
# file containing the commands to be executed on the file given as the second
# argument. The '-s' flag stands for silent mode.

	header=$(ls *.h)
	vim -s cmds.keys $header 
	printf "Header file updated.\n"

# Removing the auxiliary files.

	rm types.txt
	rm cmds.keys

	printf "\n------\033[12GE N D\033[22G------\n\n"
