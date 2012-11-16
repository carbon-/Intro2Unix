# ECE 2524 Shaishav Parekh 11/15/2012
# Defines
CC=g++
CFLAGS=-g -Wall

all: generator consumer dispatcher

generator: generator.cpp
	$(CC) $(CFLAGS) generator.cpp -o generator

consumer: consumer.cpp
	$(CC) $(CFLAGS) consumer.cpp -o consumer

dispatcher: dispatcher.cpp
	$(CC) $(CFLAGS) dispatcher.cpp -o dispatcher

clean:
	rm -rf generator consumer dispatcher
