
#include "my_lib.h"
struct node *stack1=NULL,*stack2=NULL;
int count=0;

  
/* Push data into stack */
void push(int data,struct node** ref)
{   struct node* temp=NULL;
    if (*ref == NULL)
    {
        *ref =(struct node *)malloc(1*sizeof(struct node));
        (*ref)->ptr = NULL;
        (*ref)->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = *ref;
        temp->info = data;
        *ref = temp;
    }
    count++;
}
 
/* Display stack elements */
void display(struct node **ref)
{
    struct node* top1;
    top1=*ref;
    while (top1)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
int pop(struct node **ref)
{
    struct node *temp1 = NULL;
 
    if (*ref == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return 0;
    }
    else
        {
            temp1 = (*ref)->ptr;
            int data=(*ref)->info;
            free(*ref);
            *ref = temp1; 
            return data;
        }
    
}
 
int deque()                                                                             
{
    struct node *temp = NULL;
    int countt=0;
    int tmp1,tmp2 ;
    while(stack1!=NULL)                                                                     
    {
        tmp1 = pop(&stack1);
        push(tmp1,&stack2);
        countt++;
    }
    //display(&stack2);
    tmp2=pop(&stack2); 
    while(stack2!=NULL)                                                                     
    {
        tmp1 = pop(&stack2);
        push(tmp1,&stack1);
        countt--;
    }
    //display(&stack1);
    return tmp2;
    
}
void enque(int data )                                                               
{
    push(data,&stack1);
    count++;
}
