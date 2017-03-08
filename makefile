.PHONY: clean
.PHONY: cleanall

#CFLAGS= -ansi -pedantic -O0 -Wall
CFLAGS= -O0# -Wall

all: bubblesort numgen

bubblesort: bubblesort.o
	gcc -g -o bubblesort $(CFLAGS) bubblesort.o

bubblesort.o: bubblesort.c bubblesort.h hw4.h
	gcc -c -g -o bubblesort.o $(CFLAGS) bubblesort.c 

numgen: numgen.c numgen.h hw4.h 
	gcc -g -o numgen $(CFLAGS) numgen.c 

clean:
	rm -f *.o

cleanall:
	rm -f *.o bubblesort numgen
