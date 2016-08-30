#include "my_fun.h"
extern struct node  *stack1,*stack2;
int main(){
	int temp;
	printf("press E to enqueue element\npress D to dequeue element\npress S to display queue.\npress T to terminate program.\nEnter Your Choice:");
while(1)
{
	char c=getchar();
	char buff=getchar();
	if(c=='d'||c=='D')
	{
		temp=deque();
		printf("%d dequeued\n",temp);
	}
	else if(c=='S'||c=='s')
	{
		display(&stack1);
	}
	else if(c=='e'||c=='E')
	{
		printf("Enter Element:");
		scanf("%d",&temp);
		char buff=getchar();
		enque(temp);
	}
	
	else if(c=='T'||c=='t')
	{
		break;
	}
printf("\nAgain Enter Your Choice:");
}
return 0;
}