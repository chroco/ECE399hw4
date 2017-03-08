#include "bubblesort.h"

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
	for(i=0;i<NUM_SIZE-1;++i)
		for(j=0;j<NUM_SIZE-i-1;++j)
			swap(&nums->n[j],&nums->n[j+1]);
	return 0;
}


