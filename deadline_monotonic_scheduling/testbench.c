#include<stdio.h>
#include<stdlib.h>
#include "heapSort.c"

void arrayPrint(int*, int);
int lcm(int* ar, int m);

void arrayPrint(int* arr, int n)  {
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int lcm(int* ar, int m)	{
	int res = ar[0];
	int a,b;
	for(int i=1; i<m; i++)  {
		 if(res>ar[i])  {
		   b= res;
		   a= ar[i];
		 }
		 else  {
		   b = ar[i];
		   a = res;
		 }
		 int r=1;
		 while(r>0)  {
		   r = b%a;
		   b = a;
		   a = r;
		 }
		 res = (ar[i]*res)/b;
	}
	return res;
}
int main(int argc, char **argv)  {
 	int m = 3;
 	int arr[3][4] = {{3,20,7,0},{2,5,4,0},{2,10,8,0}};
 	int* exec = (int*)(malloc(sizeof(int)*m));
 	int* period = (int*)(malloc(sizeof(int)*m));
 	int* deadline = (int*)(malloc(sizeof(int)*m));
 	int* arrival = (int*)(malloc(sizeof(int)*m));

 	int* offset = (int*)(malloc(sizeof(int)*m));
 	int* rexec = (int*)(malloc(sizeof(int)*m)); 	
 	int* index = (int*)(malloc(sizeof(int)*m));
 	for(int i=0; i<m; i++)	{
 			exec[i] =  arr[i][0];
 			rexec[i] = arr[i][0];
 			period[i] = arr[i][1];
 			deadline[i] = arr[i][2];
 			offset[i] = arr[i][3];
 			arrival[i] = arr[i][3];

 	}
 	int lcmm = lcm(period,m);
 	int* heapdead = (int*)(malloc(sizeof(int)*lcmm*m));
 	int* heapindex = (int*)(malloc(sizeof(int)*lcmm*m)); 
 	
	int** e = (int**)(malloc(sizeof(int)*m));
	int** plote = (int**)(malloc(sizeof(int)*m));
  for(int i=0; i<m; i++)	{
		e[i] = (int*)(malloc(sizeof(int)*lcmm));
		plote[i] = (int*)(malloc(sizeof(int)*lcmm*100));
	}
 	int value;
 	int indexterm;
 	int heapsize = 0;
 	
 	for(int i=0; i<lcmm; i++)  {	
		
		for(int j=0; j<m; j++)	{
				e[j][i] = 0;

	  		if(arrival[j] == i)	{
	

  				 minHeapPush(heapdead, heapindex, &heapsize, deadline[j], j );
  				 arrival[j] += period[j];
					 rexec[j] = exec[j];
				}
		}
			if(heapsize > 0)	{	
				minHeapPop(heapdead,heapindex,&value,&indexterm,&heapsize);
				printf("%d ",indexterm+1);
				
				e[indexterm][i] = 1;
			
					rexec[indexterm]--;
					if(rexec[indexterm]>0)	{
  			  	minHeapPush(heapdead, heapindex, &heapsize, value, indexterm );
					}  	
				
			}
			else {
	 		printf("0 ");
	 	  }
	}
	printf("\n");
	for(int i=0; i<m; i++){
		arrayPrint(e[i],lcmm); 
	}
	return 0;	
} 
 	
 	
 	

