#include<stdio.h>
#include<stdlib.h>
#include "heapSort.c"
int main(){
	int m=5;

	int arr[5][2]={{2,1},{1,5},{4,1},{0,6},{2,3}};

	int* arrival=malloc(m*sizeof(int));
	int* burst_time=malloc(m*sizeof(int));
	for(int i=0;i<m;i++){
		arrival[i]=arr[i][0];
		burst_time[i]=arr[i][1];
	}
	
	int total=0;
	for(int i=0;i<m;i++)
		total+=arr[i][1];

	int** e=(int**)(calloc(m,sizeof(int**)));
		for(int i=0;i<m;i++)
			e[i]=(int*)(calloc(total,sizeof(int)));
	int* heaphead=(int*)calloc(m,sizeof(int));
	int* indexvalue=(int*)calloc(m,sizeof(int));

	int index=0;
	int value=0,size=0,job=0;

	for(int i=0;i<total;i++)
	{
		for(int j=0;j<m;j++){
			if(arrival[j]==i){
				minHeapPush(heaphead,indexvalue,&size,burst_time[j],j);	
			}
		}

			if(value==0)
				minHeapPop(heaphead,indexvalue,&value,&index,&size);
			printf(" %d ",index+1);
			e[index][i]=1;
			burst_time[index]--;
			value--;
			

		

	}
printf("\n\n");
for(int i=0;i<m;i++){
	for(int j=0;j<total;j++)
		printf("%*d ",2,e[i][j]);
	printf("\n");
}
	
	
	/*
int m=5;
int total=10;
int** e=(int**)malloc(m*sizeof(int**));
for(int i=0;i<m;i++)
	e[i]=(int*)malloc(total*sizeof(int));
for(int i=0;i<m;i++){
	for(int j=0;j<10;j++)
		printf("%d ",e[i][j]);
	printf("\n");}

	int** a = (int**)(malloc(sizeof(int)*5));
	int** plote = (int**)(malloc(sizeof(int)*m));
  for(int i=0; i<5; i++)	{
		a[i] = (int*)(malloc(sizeof(int)*10));
	
	}
  for(int i=0;i<5;i++)
	  for(int j=0;j<10;j++)
		  a[i][j]=0;
  for(int i=0;i<5;i++){
	  for(int j=0;j<10;j++)
		  printf("%d ",a[i][j]);
	  printf("\n");
  }*/
return 0;
}
