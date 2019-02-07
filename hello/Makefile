
CC = gcc
CFLAGS = -Wall

hello: hello.o greeting.o factorial.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<


#TARGET: PREREQ1 PREREQ2 ....
#	COMMAND





