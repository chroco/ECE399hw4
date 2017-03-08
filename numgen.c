

#include "numgen.h"

int main(int argc, char *argv[]){
	char *file="test.num";
	numbers nums;
	numgen(file,0x100);
	numfill(file,&nums);
	int i;
	for(i=0;i<SIZE;++i)printf("%d ",nums.n[i]);
	printf("\n");
	return 0;
}


