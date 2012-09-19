#!/usr/bin/env python
#--------------------------------------------------
# ECE 2524 Homework 3 Problem 1 Shaishav Parekh
# 
# Date: 09/16/2012
#--------------------------------------------------

import argparse
import sys
import traceback
a = []
parser = argparse.ArgumentParser(description='Multiply some numbers.')
args = parser.parse_args()

def mul(a):
	prod = 1
	for i in a:
		prod *= i 
		res = ('%f' % prod).rstrip('0').rstrip('.')
	return res
	
for line in iter(sys.stdin.readline, ''):
	try:
		n = float(line)
	except ValueError as e:
		sys.stderr.write("Error: not a valid number\n")
		sys.exit(1)
	a.append(n)

print(mul(a))

