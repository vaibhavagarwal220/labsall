#ifndef LIB_H
#define LIB_H
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
#endif
