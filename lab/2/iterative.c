#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 
 int count=0;
struct Stack
{
   unsigned capacity;
   int top;
   int *array;
};
 
struct Stack* create(unsigned capacity)
{
    struct Stack* stack =
        (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =
        (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack)
{
   return (stack->top == stack->capacity - 1);
}
int isEmpty(struct Stack* stack)
{
   return (stack->top == -1);
}
 
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] = item;
}
 
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return 0;
    return stack -> array[stack -> top--];
}

void moved(char dest, char src, int disk)
{   count++;
    printf("[%d] Move disk %d from %c -> %c\n",
           count,disk, dest, src);
}
 
void movedfrmpeg(struct Stack *src,
            struct Stack *dest, char s, char d)
{
    int p1top = pop(src);
    int p2top = pop(dest);
 
    if (p1top == 0)
    {
        push(src, p2top);
        moved(d, s, p2top);
    }
 
    else if (p2top == 0)
    {
        push(dest, p1top);
        moved(s, d, p1top);
    }
 
    else if (p1top > p2top)
    {
        push(src, p1top);
        push(src, p2top);
        moved(d, s, p2top);
    }
 
    else
    {
        push(dest, p2top);
        push(dest, p1top);
        moved(s, d, p1top);
    }
}
void hanoi(int n, struct Stack
             *src, struct Stack *aux,
             struct Stack *dest)
{
    int i, nmoves;
    char s = 'A', d = 'C', a = 'B';
    if (n % 2 == 0)
    {
        char temp = d;
        d = a;
        a  = temp;
    }
    nmoves = pow(2, n) - 1;
 
    
    for (i = n; i >= 1; i--)
        push(src, i);
 
    for (i = 1; i <= nmoves; i++)
    {
        if (i % 3 == 1)
          movedfrmpeg(src, dest, s, d);
 
        else if (i % 3 == 2)
          movedfrmpeg(src, aux, s, a);
 
        else if (i % 3 == 0)
          movedfrmpeg(aux, dest, a, d);
    }
}
int main()
{
    int n ;
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    struct Stack *src, *dest, *aux;
 
    src = create(n);
    aux = create(n);
    dest = create(n);
    
    hanoi(n, src, aux, dest);
    printf("Total number of steps : %d\n",count);
    return 0;
}