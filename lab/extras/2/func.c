#include "lib.h"
//extern int count; 
/* Create empty stack */
//

void create()
{
    top = NULL;
}
 
/* Count stack elements */

 
/* Push data into stack */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        return ;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
int pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        
        return -1;
    }
    else
        top1 = top1->ptr;
    
    int val=top->info;
    
    free(top);
    top = top1;
    count--;
    return val;
}
 
/* Return top element */
/* Check if stack is empty or not */
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void insbottom(int item)
{
    if (isEmpty())
        push(item);
    else
    {
         int temp = pop();
        insbottom(item);
 
        push(temp);
    }
}
 
void reverse()
{
    if (!isEmpty())
    {
        int temp = pop();
        reverse();
 
        insbottom(temp);
    }
}

 

