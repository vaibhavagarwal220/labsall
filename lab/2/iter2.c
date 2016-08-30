#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int count=0;
struct node
{
    int info;
    struct node *ptr;
} *top1=NULL,*top2=NULL,*top3=NULL,*temp,*temp1;

 
/* Push data into source stack  */
void push1(int data)
{
    if (top1 == NULL)
    {
        top1 =(struct node *)malloc(1*sizeof(struct node));
        top1->ptr = NULL;
        top1->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top1;
        temp->info = data;
        top1 = temp;
    }
}

/* Push data into destination stack  */
void push2(int data)
{
    if (top2 == NULL)
    {
        top2 =(struct node *)malloc(1*sizeof(struct node));
        top2->ptr = NULL;
        top2->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top2;
        temp->info = data;
        top2 = temp;
    }
}

/* Push data into Auxilary stack  */
void push3(int data)
{
    if (top3 == NULL)
    {
        top3 =(struct node *)malloc(1*sizeof(struct node));
        top3->ptr = NULL;
        top3->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top3;
        temp->info = data;
        top3 = temp;
    }
}


/* Pop Operation on source stack */
int pop1()
{
    
    if (top1 == NULL)
    {
        return 0;
    }
    else
    {
    	int data ;
        temp1 = top1->ptr;
        data = top1->info;
        free(top1);
    	top1 = temp1;
    	return data ;
    }
    
}

/* Pop Operation on destination stack */
int pop2()
{
    
    if (top2 == NULL)
    {
        return 0;
    }
    else
    {
    	int data ;
        temp1 = top2->ptr;
        data = top2->info;
        free(top2);
    	top2 = temp1;
    	return data ;
    }
    
}

/* Pop Operation on auxilary stack */
int pop3()
{
    
    if (top3 == NULL)
    {
        return 0;
    }
    else
    {
    	int data ;
        temp1 = top3->ptr;
        data = top3->info;
        free(top3);
    	top3 = temp1;
    	return data ;
    }
    
}

void moveDisk(int count,char dest, char src, int disk)
{
    printf("[%d] Move the disk %d from \'%c\' to \'%c\'\n",
           count,disk, dest, src);
}
char s='A',d='C',a='B';
int main()
{
	int n,i,x,t1,t2 ;
	printf("Enter the no. the disks : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		push1(i);
	}
	x=pow(2,n)-1;
	printf("\nDisk movement sequence to solve it is as follows:\n\n");
	if(n%2==0)
	{	
		for(i=1;i<=x;i++)
		{
			
			if(i%3==1)
			{	count++;
				t1 = pop1();
				t2 = pop3();
				if(t1==0)
				{	
					push1(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg A \n",count,t2);
				}
				else if(t2==0)
				{	
					
					push3(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg B \n",count,t1);
				}
				else if(t1>t2)
				{
					
					push3(t2);
					push3(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg B \n",count,t2);
				}
				else if(t2>t1)
				{
					
					push1(t1);
					push1(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg A \n",count,t1);
				}
			}

			if(i%3==2)
			{	count++;
				t1 = pop1();
				t2 = pop2();
				if(t1==0)
				{	
					push1(t2);
					printf("[%d] Move Disk %d from Peg C --> Peg A \n",count,t2);
				}
				else if(t2==0)
				{	
					push2(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg C \n",count,t1);
				}
				else if(t1>t2)
				{	
					push2(t2);
					push2(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg C \n",count,t2);
				}
				else if(t2>t1)
				{
					
					push1(t1);
					push1(t2);
					printf("[%d] Move Disk %d from Peg C --> Peg A \n",count,t1);
				}
				
			}

			if(i%3==0)
			{
				t1 = pop2();
				t2 = pop3();
				count++;
				if(t1==0)
				{
					push2(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg C \n",count,t2);
				}
				else if(t2==0)
				{
					push3(t1);
					printf("[%d] Move Disk %d from Peg C --> Peg B \n",count,t1);
				}
				else if(t1>t2)
				{
					push3(t2);
					push3(t1);
					printf("[%d] Move Disk %d from Peg C --> Peg B \n",count,t2);
				}
				else if(t2>t1)
				{
					push2(t1);
					push2(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg C \n",count,t1);
				}
				
			}
		}
	}
	else
	{
		for(i=1;i<=x;i++)
		{
			
			if(i%3==1)
			{	count++;
				t1 = pop1();
				t2 = pop2();
				if(t1==0)
				{
					push1(t2);
					printf("[%d] Move Disk %d from Peg C --> Peg A \n",count,t2);
				}
				else if(t2==0)
				{
					push2(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg C \n",count,t1);
				}
				else if(t1>t2)
				{
					push2(t2);
					push2(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg C \n",count,t2);
				}
				else if(t2>t1)
				{
					push1(t1);
					push1(t2);
					printf("[%d] Move Disk %d from Peg C --> Peg A \n",count,t1);
				}
			}

			if(i%3==2)
			{
				t1 = pop1();
				t2 = pop3();
				count++;
				if(t1==0)
				{
					push1(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg A \n",count,t2);
				}
				else if(t2==0)
				{
					push3(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg B \n",count,t1);
				}
				else if(t1>t2)
				{
					push3(t2);
					push3(t1);
					printf("[%d] Move Disk %d from Peg A --> Peg B \n",count,t2);
				}
				else if(t2>t1)
				{
					push1(t1);
					push1(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg A \n",count,t1);
				}
				
			}

			if(i%3==0)
			{
				count++;
				t1 = pop2();
				t2 = pop3();
				if(t1==0)
				{
					push2(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg C \n",count,t2);
				}
				else if(t2==0)
				{
					push3(t1);
					printf("[%d] Move Disk %d from Peg C --> Peg B \n",count,t1);
				}
				else if(t1>t2)
				{
					push3(t2);
					push3(t1);
					printf("[%d] Move Disk %d from Peg C --> Peg B \n",count,t2);
				}
				else if(t2>t1)
				{
					push2(t1);
					push2(t2);
					printf("[%d] Move Disk %d from Peg B --> Peg C \n",count,t1);
				}
				
			}
		}
	}
	printf("Total number of moves is %d\n",count);
	return 0;
}
