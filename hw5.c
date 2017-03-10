/*
 *	Chad Coates
 *	ECE 399
 *	Homework #4
 *
 */

#include "numgen.h"
#include "hw5.h"
#include "bubblesort.h"


int main(int argc,char *argv[]){
	numbers nums;
	numfill("test.num",&nums);
	numprint(&nums);
	pthread_bubblesort(&nums,2);
	numprint(&nums);

	return 0;
}
