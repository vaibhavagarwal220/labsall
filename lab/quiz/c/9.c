#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int valid(char *a,int s,int n)
 {
    if((n-s)==2 && !strcmp(a,"ab")) return 1;
    else if((a[s]=='a' && a[n-1]=='b' && valid(a,s+1,n-1)))//|| (a[s]=='a' && a[s+1]=='b' && valid(a,s+2,n) ) || (a[n-2]=='a' && a[n-1]=='b' && valid(a,s,n-2)))
    {
        return 1;
    }
    else 
        return 0; 
 }
int main()
{
    char a[10000];
    int n,i,j;
    scanf("%s",a);
    n=strlen(a);
    if(valid(a,0,n)) printf("Valid\n");
    else printf("Invalid\n");
return 0;
}
