/*
 *	Chad Coates
 *	ECE 399
 *	Homework #4
 *
 */

#include "numgen.h"
#include "hw4.h"
#include "bubblesort.h"

int main(int argc,char *argv[]){
	numbers nums;
	numfill("test.num",&nums);
	numprint(&nums);
	bubblesort(&nums);
	numprint(&nums);

	return 0;
}
