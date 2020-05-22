#include<stdio.h>
#include<stdlib.h>
#include "queue.c"
int main(){
	int m=5;
	Queue* queue=createQueue(m);
	
	int arr[5][2]={{0,8},{5,2},{1,7},{6,3},{8,5}};
	
	int quantum=3;

	int* arrival=malloc(m*sizeof(int));
	int* exec=malloc(m*sizeof(int));
	int* rexec=malloc(m*sizeof(int));
	int* burst_time=malloc(m*sizeof(int));
	for(int i=0;i<m;i++){
		arrival[i]=arr[i][0];
		burst_time[i]=arr[i][1];
		if(burst_time[i]<quantum){
			exec[i]=rexec[i]=burst_time[i];
			burst_time[i]=0;
		}
		else{
			exec[i]=rexec[i]=quantum;
			burst_time[i]-=quantum;
		}
	}
	
	int total=0;
	for(int i=0;i<m;i++)
		total+=arr[i][1];

	int** e=(int**)(calloc(m,sizeof(int**)));
		for(int i=0;i<m;i++)
			e[i]=(int*)(calloc(total,sizeof(int)));
	int value=0,p=0;

	for(int i=0;i<total;i++)
	{
		for(int j=0;j<m;j++){
			if(arrival[j]==i){
				enqueue(queue,j+1);
			}
		}
		value=queue->array[queue->front];
		if(exec[value-1]==0){
				p=dequeue(queue);
				if(burst_time[p-1]!=0){
					enqueue(queue,p);
					if(burst_time[p-1]<quantum){
						exec[p-1]=burst_time[p-1];
						burst_time[p-1]=0;
					}
					else{
						exec[p-1]=quantum;
						burst_time[p-1]-=quantum;
					}
					

				}
			}	
			value=queue->array[queue->front];
			printf(" %d ",value);
			e[value-1][i]=1;
			exec[value-1]--;
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
