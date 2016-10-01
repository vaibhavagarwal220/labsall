#include "lib.h"
extern int count;
int main()
{
    int l,flag=1,i,mid;
    char ch[10000];
   
 
    create();
 
    printf("Enter Expression(or 0 to exit):");
    scanf("%s", ch);
    l=strlen(ch);
    
    if(ch[i]=='0') return 0;
    for(i=0;i<l/2;i++)
    {
    //printf("%c ",ch[i]);
    push(ch[i]);    
    }
    printf("\n");
    if(l%2==0) mid=l/2;
    else mid=l/2+1;
    for(i=mid;i<l;i++)
    {
        int d=pop();
       //printf(" %c %c ",ch[i],d);
        if(d!=ch[i]) 
        {   printf("%s is not a Palindrome \n",ch);
            flag=0;
            break;
        }    
    }
if(flag==1) printf("%s is a palindrome \n",ch);

return 0; 
    
}

 
