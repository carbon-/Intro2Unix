#!/usr/bin/env python
#--------------------------------------------------
# ECE 2524 Homework 3 Problem 2 Shaishav Parekh
# 
# Date: 09/16/2012
#--------------------------------------------------

import argparse
import sys
import fileinput

a = []

parser = argparse.ArgumentParser(description='Multiply some numbers. \n Uses stdin if file is not specified')
parser.add_argument('file', nargs='?', type=argparse.FileType('r'), default = "-")
parser.add_argument('--ignore-blank', action="store_true", default=False, help='ignores blanks')
parser.add_argument('--ignore-non-numeric', action="store_true", default=False, help='ignores non numeric characters')
args = parser.parse_args()

def mul(a):
	prod = 1
	for i in a:
		prod *= i 
		res = ('%f' % prod).rstrip('0').rstrip('.')
	print res
	
for line in iter(args.file.readline, ''):
	try:
		n = float(line)
	except ValueError:
		if (line == '\n' and args.ignore_blank == False):
			del a[:]
			continue
		elif (line != '\n' and args.ignore_non_numeric == False):
			sys.stderr.write("Error: not a valid number.\n")
			sys.exit(1)
		else:
			continue
			
	a.append(n)

mul(a)

