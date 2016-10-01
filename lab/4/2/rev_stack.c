#include "lib.h"
extern int count; 


int main()
{
int no, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Empty");
    printf("\n 4 - Exit");
    printf("\n 5 - Display");
    printf("\n 6 - Reverse");
    create();
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
		    case 1:
		        printf("Enter data : ");
		        scanf("%d", &no);
		        push(no);
		        break;
		    case 2:
		        pop();
		        break;
		    case 3:
		        isEmpty();
		        break;
		    case 4:
		        exit(0);
		    case 5:
		        display();
		        break;
		    case 6:
		        reverse();
		        break;
		    default :
		        printf(" Wrong choice, Please enter correct choice  ");
		        break;
        }
    }}

