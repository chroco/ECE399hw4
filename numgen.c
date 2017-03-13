/*
 * Chad Coates
 * ECE 399
 * Homework #5
 * March 12, 2017
 */

#include "numgen.h"

// generate random numbers and save them in
// a binary file
int numgen(char *file){
	FILE *fd;
	fd=fopen(file,"w+");
	int i;
	numbers nums;
	printf("generating %d random integers...\n",NUM_SIZE);
	srand(time(NULL));
	for(i=0;i<NUM_SIZE;++i)nums.n[i]=rand()%100;
	fwrite(&nums,sizeof(numbers),1,fd);
	fclose(fd);
	return 0;
}

// fill a numbers struct from a file
int numfill(char *file,numbers *n){
	FILE *fd;
	printf("populating array with the random numbers...\n");
	if(!(fd=fopen(file,"r"))){
		perror("cannot open file!\n");
		exit(1);
	}
	fread(n,sizeof(numbers),1,fd);
	fclose(fd);
	return 0;
}

// print out a numbers struct
int numprint(numbers *nums){
	int i;
	for(i=0;i<NUM_SIZE;++i)printf("%d ",nums->n[i]);
	printf("\n");
	return 0;
}
	
