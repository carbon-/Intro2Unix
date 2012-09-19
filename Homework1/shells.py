#!/usr/bin/env python
#--------------------------------------------------
# ECE 2524 Homework 2 Problem 1 Shaishav Parekh
# 
# Date: 09/11/2012
#--------------------------------------------------

# Open the file
with open('/etc/passwd', 'r') as f:
	# Read each line
	for line in f:
		# Split the line into sections delimited by :
		inline = [line.split(':',6)]
		# Store the username in a variable
		username = inline[0][0]
		# Store the directory in a variable
		# When split was not used the newline character
		# was messing up output
		directory = inline[0][6].split()
		# store the username and directory as a string
		string = [username, directory[0]]
		# join the string with the tab character
		output = "\t".join(string)
		# output username \t directory
		print output
