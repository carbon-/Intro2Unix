#!/usr/bin/env python
#--------------------------------------------------
# ECE 2524 Homework 2 Problem 2 Shaishav Parekh
# 
# Date: 09/11/2012
#--------------------------------------------------

# NOTE: You need to specify what file to read
# account info from
with open('account.txt', 'r') as f:
	# Print header
	print "ACCOUNT INFORMATION FOR BLACKSBURG RESIDENTS"
	# Read each line
	for line in f:
		# Split the line into different strings
		# First Name, Last Name, Amount Owed, Residence, Phone
		inline = [line.split()]
		# Check if they are a resident of Blacksburg
		if (inline[0][3] == "Blacksburg"):
			# If true store their info into appropriate variables
			Number = inline[0][4]
			LName = inline[0][1]
			FName = inline[0][0]
			Amount = inline[0][2]
			# Store their info into a string
			string = [Number, LName, FName, Amount]
			# Format and output the string
			output = ', '.join(string)
			print output
