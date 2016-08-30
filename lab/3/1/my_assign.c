#include "my_fun.h"
int main()
{
int n,i,*x;
printf("Enter values of n and i:");
scanf("%d %d",&n,&i);
x=init(n);
josephus(n,i,x);
}