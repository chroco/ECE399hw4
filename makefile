.PHONY: clean
.PHONY: cleanall

#CFLAGS= -ansi -pedantic -O0 -Wall
CFLAGS= -O0# -Wall

all: bubble 

bubble: bubble.o
	gcc -g -o bubble $(CFLAGS) bubble.o

bubble.o: bubble.c bubble.h
	gcc -c -g -o bubble.o $(CFLAGS) bubble.c 

clean:
	rm -f *.o

cleanall:
	rm -f *.o bubble
