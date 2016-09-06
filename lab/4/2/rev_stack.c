
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 

void push(int data);
int pop();
int isEmpty();
void display();
void create();
 
int count = 0;

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

 
int main()
{int no, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Empty");
    printf("\n 4 - Exit");
    printf("\n 5 - Display");
    printf("\n 6 - Reverse");
    create();
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            exit(0);
        case 5:
            display();
            break;
        case 6:
            reverse();
            break;
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }}
 
/* Create empty stack */
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
 

