#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <pthread.h>
#include <string.h>
#include "numgen.h"

int swap(int *,int *);
void *bubblesort(void *);
void *_merge(void *);
int pthread_bubblesort(numbers *,int);


#endif
