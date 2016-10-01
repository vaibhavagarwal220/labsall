#include <ctype.h>
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
int empty();
void display();
void create();
 
int count = 0;
 
int main()
{
  int t,num,a,b;
  char ch;

  FILE *file = fopen("pfix.txt","r");
    fscanf(file,"%d",&t);
  while(t--)
  {
    num = 0;
    do
    {
      ch = getc(file);
      if(ch == '*')
      {
        a = pop();
          b = pop();
          push(a*b);
      }
      else if(ch == '+')
      {
        a = pop();
          b = pop();
          push(a+b);
      }
      else if(ch == '-')
      {
        a = pop();
        b = pop();
        push(a-b);
      }
      else if(isdigit(ch))
      {
        num = num*10 + ch - '0';
      }
      else if(isspace(ch) && num)
      {
        push(num);
        num = 0;
      }
    }while(ch != '\n' && ch != EOF);
    display();
    printf("\n");
    a = pop();
  }
  return 0; 
}
 
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
int empty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
 
