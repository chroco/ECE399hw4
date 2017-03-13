#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <pthread.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "numgen.h"

int swap(int *,int *);
void *bubblesort(void *);
void *_merge(void *);
int pthread_bubblesort(numbers *,int);
int validate(numbers *);

typedef struct NumberSet{
	int *nptr;
	int size;
}numberset;

typedef struct Merge{
	numberset nset[2];
	int size,*res;
}merge;

#endif
