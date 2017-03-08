#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "hw4.h"
#include "numgen.h"

int swap(int *aptr,int *bptr){
	int temp;
///*
	if(*aptr>*bptr){
		temp=*aptr;
		*aptr=*bptr;
		*bptr=temp;
		return 1;
	}
//*/
	return 0;
}

int bubblesort(numbers *nums){
	int i,j;
	for(i=0;i<SIZE-1;++i)
		for(j=0;j<SIZE-i-1;++j)
			swap(&nums->n[j],&nums->n[j+1]);
	return 0;
}


#endif
