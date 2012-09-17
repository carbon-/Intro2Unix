#!/usr/bin/env python
#--------------------------------------------------
# ECE 2524 Homework 3 Problem 1 Shaishav Parekh
# 
# Date: 09/16/2012
#--------------------------------------------------

import argparse

def mul(iterable):
	prod = 1
	for n in iterable:
		prod *= n
		res = ('%f' % prod).rstrip('0').rstrip('.')
	return res
	

parser = argparse.ArgumentParser(description='Multiply some numbers.')
parser.add_argument('numbers', metavar='N', type=float, nargs='+', help='a number for the multiplication.')

parser.add_argument(dest='multiply', action='store_const', const=mul, help='multiply the integers.')
args = parser.parse_args()
print(args.multiply(args.numbers))

