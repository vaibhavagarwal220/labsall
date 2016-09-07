/*
 * C Program to Implement Queue Data Structure using Linked List
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
queue q1,q2;
void push(int data);
int pop();

void main()
{
	q1=init(q1);
	q2=init(q2);
	
    int no, e,temp;
    char ch,bu;
	
    printf("\n i - Push");
    printf("\n r - Pop");
    printf("\n o - Exit");
    printf("\n s - Display");
    
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%c", &ch);
        switch (ch)
        {
        case 'i':
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 'r':
            pop();
            break;
        case 'o':
            exit(0);
        case 's':
           temp=print(q1);
            if(temp) printf("Stack is Empty\n");
            break;    
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
        scanf("%c", &bu);
    }
}



void push(int data)
{
struct node *temp=NULL;
int size;
if(q1.size==0) 
    {
     //   printf("insertd in q1\n");
        q1=enqueue(q1,data);
      //  print(q1);
    }
else
{
//    printf("insertd in q2\n");
q2=enqueue(q2,data);
//print(q2);
while(q1.size!=0)
{
 int data=dequeue(&q1);
 q2=enqueue(q2,data);
}


temp=q2.front;
 q2.front=q1.front;
 q1.front=temp;
 temp=q2.rear;
 q2.rear=q1.rear;
 q1.rear=temp;

 size = q2.size;
 q2.size = q1.size;
 q1.size = size;
}

/*printf("End :\n");
print(q1);
print(q2);
printf("\n");*/

}
int pop()
{
	return dequeue(&q1);
}

