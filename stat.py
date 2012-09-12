#!/usr/bin/env python
#--------------------------------------------------
# ECE 2524 Homework 2 Problem 3 Shaishav Parekh
# 
# Date: 09/11/2012
#--------------------------------------------------

# NOTE: You need to specify what file to read
# account info from
with open('account.txt', 'r') as f:
	# Print header
	print "ACCOUNT SUMMARY"
	# Initialize some variables
	average = 0
	total_amount = 0
	max_amount = 0
	min_amount = 0
	count = 0
	max_name = "Alice"
	min_name = "Bob"
	# Read each line
	for line in f:
		# Split the line into different string
		# First Name, Last Name, Amount Owed, Residence, Phone
		inline = [line.split()]
		temp_amount = float(inline[0][2])
		# if its the first time through the loop
		if (count == 0):
			# initialize the min_amount to check against
			min_amount = temp_amount
		# Keep a running tab of the total_amount
		total_amount = total_amount + temp_amount
		# Do some checking to see if value read is maximum
		# amount owed or minimum amount owed
		if (temp_amount > max_amount):
			# if it is greater store the amount and name
			max_amount = temp_amount
			max_name = inline[0][1]
		if (temp_amount < min_amount):
			# if it is lesser store the amount and name
			min_amount = temp_amount
			min_name = inline[0][1]
		# Keep track of how many customers are read in
		count = count + 1
	# Calculate the average
	average = total_amount/count
	# Output the results
	print "Total amount owed =", total_amount
	print "Average amount owed =", average
	print "Maximum amount owed =", max_amount, "by", max_name
	print "Maximum amount owed =", min_amount, "by", min_name
