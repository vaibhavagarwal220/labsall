#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int count = 0;
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
void insbottom(int);
void reverse(); 
#endif
