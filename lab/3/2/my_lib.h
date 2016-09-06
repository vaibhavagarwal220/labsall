#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *ptr;
};
 

void push(int data,struct node **ref);
int pop(struct node **ref);
void display(struct node **ref);
int deque();
void enque(int data);
