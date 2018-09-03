# Makefile for simple server

FLAGS = -std=gnu99 -Wall

all : server

server : server.o
	gcc -o $@ server.o ${FLAGS}

# separately compile each C file
%.o : %.c
	gcc -c $< ${FLAGS}

clean :
	-rm *.o server
