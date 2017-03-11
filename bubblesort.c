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
	for(i=0;i<nset->size-1;++i)
	for(j=0;j<nset->size-i-1;++j)
		swap(nset->nptr+j,nset->nptr+j+1);
	return NULL;
}

void *_merge(void *args){
	int i=0,j=0,k=0;
	
	merge *mptr=(merge *)args;
	
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

int pthread_bubblesort(numbers *nums,int threads){
	int i,j,k,rc,
			size=NUM_SIZE/threads;
	pthread_t p[threads];
	numberset nset[threads];
	merge m[3];

	
	for(i=0;i<threads;++i){
		nset[i].nptr=&nums->n[0]+size*i;
		nset[i].size=size;
		rc=pthread_create(&p[i],NULL,bubblesort,(void *)&nset[i]);
		if(rc){
			perror("danger");
			exit(-1);
		}
	}
	
	for(i=0;i<threads;++i)pthread_join(p[i],NULL);

	for(i=0;i<3;++i){
		if(i==2){
			m[i].nset[0].nptr=m[0].res;
			m[i].nset[0].size=m[0].size;
			m[i].nset[1].nptr=m[1].res;
			m[i].nset[1].size=m[1].size;
			m[i].size=2*m[0].size;
			for(k=0;k<i;++k)pthread_join(p[k],NULL);
		}else{
			m[i].nset[0]=nset[2*i];
			m[i].nset[1]=nset[2*i+1];
			m[i].size=2*nset[2*i].size;
		}
		m[i].res=(int*)malloc(m[i].size*sizeof(int));
	//	_merge(&m[i]);
		rc=pthread_create(&p[i],NULL,_merge,(void *)&m[i]);
		if(rc){
			perror("danger");
			exit(-1);
		}
	}

	pthread_join(p[2],NULL);

	memcpy(nums->n,m[2].res,NUM_SIZE*sizeof(int));
	/*
	i=2;
	for(j=0;j<m[i].size;++j)printf("%d ",m[i].res[j]);
	printf("\n");
//*/
	return 0;
}


