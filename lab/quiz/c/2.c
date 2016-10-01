#include <stdio.h>
#include <stdlib.h>
 
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
} 
 
int main()
{
    int a[10000],b[10000],n1,n2,i,j;
    printf("Enter size of array 1:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter element [%d] : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter size of array 2:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter element [%d] : ",i+1);
        scanf("%d",&b[i]);
    }
    qsort(a, n1, sizeof(int), cmpfunc);
    qsort(b, n2, sizeof(int), cmpfunc);
    i=0,j=0;
    printf("Union of both arrays is as follows\n");
    while(i<n1 && j<n2 )
    {
       if(a[i]>b[j]) 
        {
            printf("%d ",b[j]);
            j++;
        }
       else if(a[i]<b[j])
        {
            printf("%d ",a[i]);
            i++;
        }
        else if(a[i]==b[j])
        {
            printf("%d ",a[i]);
            i++;
            j++;
        } 
    }
     while(i < n1)
   printf("%d ", a[i++]);
     while(j < n2)
   printf("%d ", b[j++]);


    i=0,j=0;
    printf("\nIntersection of both arrays is as follows\n");
    while(i<n1 && j<n2 )
    {
       if(a[i]>b[j]) 
        {
            j++;
        }
       else if(a[i]<b[j])
        {   
            i++;
        }
        else if(a[i]==b[j])
        {
            printf("%d ",a[i]);
            i++;
            j++;
        } 
    }
printf("\n");

return 0;
}
