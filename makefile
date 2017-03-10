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

.c.o: $(DEPS)
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(MAIN)

depend: $(SRCS)
	makedepend $(DEPS) $^

#
