#!/usr/bin/env python
#--------------------------------------------------
# ECE 2524 Homework 2 Problem 1 Shaishav Parekh
# 
# Date: 09/11/2012
#--------------------------------------------------


with open('/etc/passwd', 'r') as f:
	i = 0
	w = open('output.txt', 'w')
	for line in f:
		inline = [line.split(':',6)]
		w.write(inline[0][0])
		w.write('\t')
		w.write(inline[0][6])
		i = i+1
