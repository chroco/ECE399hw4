
#include "numgen.h"

int numgen(char *file,int size){
	FILE *fd;
	fd=fopen(file,"w+");
	int i;
	numbers nums;
	
	srand(time(NULL));
	for(i=0;i<NUM_SIZE;++i){
		//fprintf(fd,"%d ",rand()%100);
		nums.n[i]=rand()%100;
	}

	fwrite(&nums, sizeof(numbers), 1, fd);

	fclose(fd);
	return 0;
}

int numfill(char *file,numbers *n){
	FILE *fd;
	if(!(fd=fopen(file,"r"))){
		perror("cannot open file");
		exit(1);
	}
	fread(n,sizeof(numbers),1,fd);
	fclose(fd);
	return 0;
}

int numprint(numbers *nums){
	int i;
	for(i=0;i<NUM_SIZE;++i)printf("%d ",nums->n[i]);
	printf("\n");
	return 0;
}
	
