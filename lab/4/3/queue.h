#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct list
{
	struct node *front,*rear;
	int size;
}queue;

queue init(queue q);
queue enqueue(queue q,int data);
int dequeue(queue *q);
int print(queue q);
void flush(queue *q);

#endif
