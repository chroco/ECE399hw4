#ifndef NUMGEN_H
#define NUMGEN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_SIZE 0x20

typedef struct Numbers{
	int n[NUM_SIZE];
}numbers;

int numgen(char *,int);
int numfill(char *,numbers *);
int numprint(numbers *);

#endif
