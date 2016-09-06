#include "my_lib.h"

int front=-1;
int rear=0;

int* create(int n)
	{
		int *x;
		x=(int*) malloc(n*sizeof(int));
	 	return x;
	}
int* init (int n){
	int *x,i ;
	x=create(n);
	for(i=0;i<n;i++)
	{
		x[i]=n-i;
		
	}
	front=n-1;
	return x;
}

void enque(int *queue,int data,int n)
{

		if(rear==0)
			{
				rear=n-1;
			}
		else
			{
				rear=rear-1;
			}
			queue[rear]=data;
}


int deque(int *queue,int n)
{

int data=queue[front];
queue[front]=-1;

		if(front==0)
			{
				front=n-1;
			}
		else
			{
				front=front-1;
			}

	return data;	
}

void josephus(int n,int i,int *x)
{
	int count=0,data,j=1,y;
	while(count<n-1)
	{
		if(j==i)
		{
			data=deque(x,n);
			j=1;
			if(count==0)
				printf("[%d] Firstly the person at %d is removed.\n",count+1,data);
			else if(count==n-2)
				printf("[%d] Finally the person at %d is removed.\n",count+1,data);
			else 
				printf("[%d] Then the person at %d is removed.\n",count+1,data);
			count++;

		}
		else 
		{
			data=deque(x,n);
			enque(x,data,n);
			j++;
		}
	}
	printf("Hence the person at %d survives (WINNER).\n",x[front]);
}

