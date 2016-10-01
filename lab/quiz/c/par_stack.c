
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
    int l,i,c=0;
    char ch[10000];
   
 
    create();
 
    printf("\n Enter Expression(or 0 to exit):");
    scanf("%s", ch);
    l=strlen(ch);
    
    if(ch[i]=='0') return 0;
    for(i=0;i<l;i++)
    {
        if(ch[i]=='{'||ch[i]=='('||ch[i]=='[')
            push(ch[i]);

        else if(ch[i]=='}'||ch[i]==')'||ch[i]==']')
            {
            char b=pop();
            
            if((ch[i]=='}' && b=='{')||(ch[i]==')' && b=='(') || (ch[i]==']' && b=='['))
                {c+=2;
				continue;}
            
            }
    }
     printf("Expression %s is having %d balanced parentheses\n",ch,c);
    
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
 
