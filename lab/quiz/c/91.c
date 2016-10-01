#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int valid(char *a,int s,int n)
 { 
    if(a[s]=='a' && a[n-1]=='b') 
    {
        valid(a,s+1,n-1);
        
    }
    if(a[s]=='a' && a[s+1]=='b')
    {
        valid(a,s+2,n);
        
    }
    if(a[n-2]=='a' && a[n-1]=='b')
    {
        valid(a,s,n-2);
        
    }
     // if(((n-s)==2) && !strncmp(a+s,"ab",n-s)) return 1;
     if( a[s]=='a'&& a[n-1]=='b' ) return 1; 

      else return 0;
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
