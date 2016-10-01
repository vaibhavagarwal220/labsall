#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int val;
   char str[2000];
   while(1){
   scanf("%s",str);
   
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);
}
   return(0);
}