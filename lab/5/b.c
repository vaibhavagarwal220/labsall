#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** maker (int n, int m)																		            // initialising the array
{
	int **x,i , j;
	x= (int**)malloc(n*sizeof(int*));																		// creating n pointers for each row
	for (i=0; i<n; i++)
         x[i] = (int *) malloc(m * sizeof(int));
     srand(time(NULL));
	for(i=0;i<n;i++)																						// storing random values into array 
	{
		for(j=0;j<m;j++)
		{
			x[i][j]=rand()%100;
		}
	}
	return(x);
}

void writer(int **matrix , int n, int m, char*filename)													   // function to store elements in file 
{
	FILE *ptr;
	ptr=fopen(filename,"w");
	if(ptr==NULL)																							// if file does not exist 
		{
			printf("%s does not exist",filename);
			return ;
		}
	int i , j;
	for(i=0;i<n;i++)																				
	{
		for(j=0;j<m;j++)
		{
			fprintf(ptr,"%d\t",matrix[i][j]);
		}
		fprintf(ptr,"\n");
	}
	fclose(ptr);
	return ;
}

void printdelete(int **matrix,int n , int m )											// function to free the space and print the elements 
{
	int i , j ;
	for(i=0;i<n;i++)																					// print the elements 
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++) 																			// free elements
	{
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
	printf("Enter the number of rows and column : ");
	int n , m , **x; 
	char file[100] ;
	scanf("%d %d",&n,&m);
	x = maker(n,m);
	printf("Enter the filename to be created :");
	scanf("%s",file);
	writer(x,n,m,file);
	printdelete(x,n,m);

}
