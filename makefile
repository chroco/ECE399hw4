
#  Chad Coates
#  ECE 399
#  Homework #5
#  March 12, 2017

.PHONY: clean cleanall depend

CC=gcc
#CFLAGS= -ansi -pedantic -O0 -Wall
CFLAGS= -O0 -g -Wall -pthread

DEPS=bubblesort.h numgen.h hw5.h
SRCS=bubblesort.c numgen.c hw5.c

OBJS = $(SRCS:.c=.o)
MAIN=hw5

all: $(MAIN)
	@echo $(MAIN) compiled

$(MAIN): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o: 
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(MAIN) test.num

depend: $(SRCS)
	makedepend $(DEPS) $^

#
