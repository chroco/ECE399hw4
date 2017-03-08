.PHONY: clean cleanall depend

CC=gcc
#CFLAGS= -ansi -pedantic -O0 -Wall
CFLAGS= -O0 -g -Wall

DEPS=bubblesort.h numgen.h hw4.h
SRCS=bubblesort.c numgen.c hw4.c

OBJS = $(SRCS:.c=.o)
MAIN=hw4

all: $(MAIN)
	@echo $(MAIN) compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(MAIN)

depend: $(SRCS)
	makedepend $(DEPS) $^

#
