
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
    int l,flag=1,i,mid;
    char ch[10000];
   
 
    create();
 
    printf("Enter Expression(or 0 to exit):");
    scanf("%s", ch);
    l=strlen(ch);
    
    if(ch[i]=='0') return 0;
    for(i=0;i<l/2;i++)
    {
    //printf("%c ",ch[i]);
    push(ch[i]);    
    }
    printf("\n");
    if(l%2==0) mid=l/2;
    else mid=l/2+1;
    for(i=mid;i<l;i++)
    {
        int d=pop();
       //printf(" %c %c ",ch[i],d);
        if(d!=ch[i]) 
        {   printf("%s is not a Palindrome \n",ch);
            flag=0;
            break;
        }    
    }
if(flag==1) printf("%s is a palindrome \n",ch);

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
 
