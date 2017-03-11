#include "bubblesort.h"

typedef struct NumberSet{
	int *nptr;
	int size;
}numberset;

typedef struct Merge{
	numberset nset[2];
	int size,*res;
}merge;

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

void *bubblesort(void *arg){
	int i,j;
	numberset *nset=(numberset *)arg;
//	fprintf(stderr,"(*)[%p]\n",nset->nptr);
	for(i=0;i<nset->size-1;++i)
	for(j=0;j<nset->size-i-1;++j)
		swap(nset->nptr+j,nset->nptr+j+1);
	return NULL;
}
/*
void *_merge(void *arg){
	int i,j,k;
	i=j=k=0;

	merge *mptr=(merge *)arg;

	while(i<mptr->nset[0].size&&j<mptr->nset[1].size){
		if(mptr->nset[0].nptr[i]<=mptr->nset[1].nptr[j]){
			mptr->res[k]=mptr->nset[0].nptr[i];
			i++;
			k++;
		}else{
			mptr->res[k]=mptr->nset[1].nptr[j];
			k++;
			j++;
		}
	}

	while(i<mptr->nset[0].size){
		mptr->res[k]=mptr->nset[0].nptr[i];
		i++;
		k++;
	}

	while(j<mptr->nset[1].size) {
		mptr->res[k]=mptr->nset[1].nptr[j];
		k++;
		j++;
	}

	printf("*****\n");
	for(i=0;i<mptr->size;++i)printf("%d ",mptr->res[i]);
	printf("\n");

	return NULL;
}*/


// m - size of A
// n - size of B
// size of C array must be equal or greater than
// m + n

//void merge(int m, int n, int A[], int B[], int C[]) {
void *_merge(void *args) {
	int i=0,j=0,k=0;
	
	merge *mptr=(merge *)args;
	
	//fprintf(stderr,"(%d,%d)",mptr->nset[0].size,mptr->nset[1].size);
//	fprintf(stderr,"{%d}",mptr->size);
///*
	while(i<mptr->nset[0].size&&j<mptr->nset[1].size){
		if(mptr->nset[0].nptr[i]<=mptr->nset[1].nptr[j]){
			mptr->res[k]=mptr->nset[0].nptr[i];
			i++;
		}else{
			mptr->res[k]=mptr->nset[1].nptr[j];
			j++;
		}
		k++;
	}
	if (i < mptr->nset[0].size) {
		for (int p = i; p < mptr->nset[0].size; p++) {
			mptr->res[k] = mptr->nset[0].nptr[p];
			k++;
		}
	}else{
		for (int p = j; p < mptr->nset[1].size; p++) {
			mptr->res[k] = mptr->nset[1].nptr[p];
			k++;
		}
	}
//*/
	return NULL;
}

int pthread_bubblesort(numbers *nums,int threads){
	int i,j,rc;
	pthread_t p[threads];
	numberset nset[threads];
	int size=NUM_SIZE/threads;
	fprintf(stderr,"size: %d\n",size);
	for(i=0;i<threads;++i){
		nset[i].nptr=&nums->n[0]+size*i;
		nset[i].size=size;
//		fprintf(stderr,"(%d)[%p]\n",i,nset[i].nptr);
//		bubblesort(&nset);
///*
		rc=pthread_create(&p[i],NULL,bubblesort,(void *)&nset[i]);
		if(rc){
			perror("danger");
			exit(-1);
		}
//*/
	}
	
	for(i=0;i<threads;++i)pthread_join(p[i],NULL);

	numprint(nums);
	
	merge m[3];
	for(i=0;i<2;++i){
		m[i].nset[0]=nset[2*i];
		m[i].nset[1]=nset[2*i+1];
	//	fprintf(stderr,"[%d,%d]",nset[0].size,nset[1].size);
		m[i].size=2*nset[2*i].size;
//		fprintf(stderr,"(%d)",m[i].size);
		m[i].res=(int*)malloc(m[i].size*sizeof(int));
		_merge(&m[i]);
		for(j=0;j<m[i].size;++j)printf("%d ",m[i].res[j]);
	}

		printf("\n");
///*
		m[2].nset[0].nptr=m[0].res;
		m[2].nset[0].size=m[0].size;
		m[2].nset[1].nptr=m[1].res;
		m[2].nset[1].size=m[1].size;
		m[2].size=2*m[0].size;
//		fprintf(stderr,"(%d)",m[2].size);
		m[2].res=(int*)malloc(m[2].size*sizeof(int));
		_merge(&m[2]);
//*/
i=2;
//	for(i=0;i<2;++i){
		for(j=0;j<m[i].size;++j)printf("%d ",m[i].res[j]);
		printf("\n");
//	}

	return 0;
}


