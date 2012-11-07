# ECE 2524 Shaishav Parekh 11/04/2012
# C++ Sources/Flags/Executable
CC=g++
CFLAGS=-c -Wall

all: exprtest

exprtest: parser.tab.o scanner.o exprtest.o
			$(CC) exprtest.o driver.o parser.tab.o scanner.o -o exprtest

exprtest.o: exprtest.cpp driver.cpp
			$(CC) $(CFLAGS) exprtest.cpp driver.cpp parser.tab.cpp scanner.cpp

# Running driver.o without exprtest.o causes errors so 
driver.o: parser.tab.o scanner.o driver.cpp
			$(CC) $(CFLAGS) driver.cpp

parser.tab.o: parser.ypp
			bison parser.ypp

scanner.o: scanner.ll
			flex -t scanner.ll > scanner.cpp

clean: 
		rm -rf *o exprtest parser.tab.hpp parser.tab.cpp scanner.cpp *hh
