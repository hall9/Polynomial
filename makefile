# Alex Hall
# makefile project3

CC = gcc
CFLAGS = -std=c99 -Wall -g
LDFLAGS = -lm

# name of the executable to be created
PROJECT = Project3

# list of all .c files
SRCS = project3.c

#list of all .h files
HDRS =

# list of .o files
OBJS = project3.o

# build the executable from the .o files
$(PROJECT) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(PROJECT)

# a separate rule to compile each .c file
project3.o: project3.c
	$(CC) $(CFLAGS) -c project3.c

clean:
	rm -fv core* $(PROJECT) $(OBJS)

cleaner: clean
	rm -vf #* *~