# This is a comment line
CC=g++
# CFLAGS will be the options passed to the compiler
CFLAGS=-c -Wall

all: lab_09

lab_09: lab_09.o
	$(CC) lab_09.o -o lab_09

lab_09.o: lab_09.cpp
	$(CC) $(CFLAGS) lab_09.cpp

clean:
	rm -rf *.o lab_09
