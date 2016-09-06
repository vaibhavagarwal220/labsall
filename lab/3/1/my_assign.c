/****************************
Vaibhav Agarwal
B15139
Lab 3 Question 1
****************************/
#include "my_lib.h"
int main()
{
int n,i,*x;
printf("Enter values of n and i:");
scanf("%d %d",&n,&i);
x=init(n);
josephus(n,i,x);
}
