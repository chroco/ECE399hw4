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
	fprintf(stderr,"(*)[%p]\n",nset->nptr);
	for(i=0;i<nset->size-1;++i)
	for(j=0;j<nset->size-i-1;++j)
		swap(nset->nptr+j,nset->nptr+j+1);
	return NULL;
}
void *_merge(void *arg){
	int i,j,k;
	i=j=k=0;
//	int res[16];

	merge *mptr=(merge *)arg;

//	int size=mptr->size;
	while(i<mptr->size&&j<mptr->size){
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

	while(i<8) {
		mptr->res[k]=mptr->nset[0].nptr[i];
		i++;
		k++;
	}

	while(j<8) {
		mptr->res[k]=mptr->nset[1].nptr[j];
		k++;
		j++;
	}

//	for(i=0;i<16;++i)printf("%d ",mptr->res[i]);
//	printf("\n");

	return NULL;
}


int pthread_bubblesort(numbers *nums,int threads){
	int i,rc;
	pthread_t p[threads];
	numberset nset[threads];
	int size=NUM_SIZE/threads;
	fprintf(stderr,"size: %d\n",size);
	for(i=0;i<threads;++i){
		nset[i].nptr=&nums->n[0]+size*i;
		nset[i].size=size;
		fprintf(stderr,"(%d)[%p]\n",i,nset[i].nptr);
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

	merge m;
	m.nset[0]=nset[0];
	m.nset[1]=nset[1];
	m.size=size;
	m.res=(int*)malloc(size*sizeof(int));
	_merge(&m);
	for(i=0;i<m.size;++i)printf("%d ",m.res[i]);
	printf("\n");

	return 0;
}


