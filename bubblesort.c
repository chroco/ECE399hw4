/*
 * Chad Coates
 * ECE 399
 * Homework #5
 * March 12, 2017
 */

#include "bubblesort.h"

// verify the array is sorted
int validate(numbers *nums){
	int i;
	printf("Verifying the array is sorted...\n");
	for(i=0;i<NUM_SIZE-1;++i){
		if(nums->n[i]>nums->n[i+1]){
				fprintf(stderr,"Error: Sort Incomplete\n");
				return 1;
		}
	}
	fprintf(stdout,"*****Sort Complete*****\n");
	return 0;
}

// swap 2 elements of an array
int swap(int *aptr,int *bptr){
	int temp;
	if(*aptr>*bptr){
		temp=*aptr;
		*aptr=*bptr;
		*bptr=temp;
		return 1;
	}
	return 0;
}

// boring bubblesort 
void *bubblesort(void *arg){
	int i,j;
	numberset *nset=(numberset *)arg;
	for(i=0;i<nset->size-1;++i)
	for(j=0;j<nset->size-i-1;++j)
		swap(nset->nptr+j,nset->nptr+j+1);
	return NULL;
}

// less boring merge
void *_merge(void *args){
	int i=0,j=0,k=0;
	merge *mptr=(merge *)args;
	while(i<mptr->nset[0].size&&j<mptr->nset[1].size){
		if(mptr->nset[0].nptr[i]<=mptr->nset[1].nptr[j]){
			mptr->res[k]=mptr->nset[0].nptr[i];
			++i;
		}else{
			mptr->res[k]=mptr->nset[1].nptr[j];
			++j;
		}
		++k;
	}
	if(i<mptr->nset[0].size){
		for(int p=i;p<mptr->nset[0].size;++p) {
			mptr->res[k] = mptr->nset[0].nptr[p];
			++k;
		}
	}else{
		for(int p=j;p<mptr->nset[1].size;++p) {
			mptr->res[k] = mptr->nset[1].nptr[p];
			++k;
		}
	}
	return NULL;
}

// less boring threaded bubblesort
int pthread_bubblesort(numbers *nums,int threads){
	int i,j,size=NUM_SIZE/threads;
	pthread_t p[threads];
	numberset nset[threads];
	merge m[3];
	struct timeval tv1,tv2;

	gettimeofday(&tv1,NULL);
	for(i=0;i<threads;++i){
		nset[i].nptr=&nums->n[0]+size*i;
		nset[i].size=size;
		if(pthread_create(&p[i],NULL,bubblesort,(void *)&nset[i])){
			perror("danger");
			exit(-1);
		}
	}
	
	for(i=0;i<threads;++i)pthread_join(p[i],NULL);

	if(threads==4){
		for(i=0;i<3;++i){
			if(i==2){
				m[i].nset[0].nptr=m[0].res;
				m[i].nset[0].size=m[0].size;
				m[i].nset[1].nptr=m[1].res;
				m[i].nset[1].size=m[1].size;
				m[i].size=2*m[0].size;
				for(j=0;j<i;++j)pthread_join(p[j],NULL);
			}else{
				m[i].nset[0]=nset[2*i];
				m[i].nset[1]=nset[2*i+1];
				m[i].size=2*nset[2*i].size;
			}
			m[i].res=(int*)malloc(m[i].size*sizeof(int));
			if(pthread_create(&p[i],NULL,_merge,(void *)&m[i])){
				perror("danger");
				exit(-1);
			}
		}
		pthread_join(p[2],NULL);
	}
	gettimeofday(&tv2,NULL);
	printf ("(@Y@) time: %f seconds\n",
			    (double)(tv2.tv_usec-tv1.tv_usec)/1000000 +
					(double)(tv2.tv_sec-tv1.tv_sec));
	if(threads==4){
		memcpy(nums->n,m[2].res,NUM_SIZE*sizeof(int));
		for(i=0;i<3;++i)free(m[i].res);
	}
	return 0;
}

