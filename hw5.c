/*
 * Chad Coates
 * ECE 399
 * Homework #5
 * March 12, 2017
 *
 *
 * Compares the sort times for bubblesort and
 * threaded bubblesort
 *
 */

#include "numgen.h"
#include "hw5.h"
#include "bubblesort.h"

int main(int argc,char *argv[]){
	numbers nums;
	numgen("test.num");
	numfill("test.num",&nums);
	printf("bubblesorting array with 1 thread...\n");
	pthread_bubblesort(&nums,1);
	validate(&nums);
	numfill("test.num",&nums);
	printf("bubblesorting array with 4 threads...\n");
	pthread_bubblesort(&nums,4);
	validate(&nums);
	return 0;
}
