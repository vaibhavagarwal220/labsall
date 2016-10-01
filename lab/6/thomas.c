/***********************************************
Name: Vaibhav Agarwal
Roll: B15139
Purpose: IC250 Assignment 01 - Question 1 - FILE I/O 
Date: 17/08/2016
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>
/*add other includes as necessary*/

double ** init_2d (int r, int c) //Initialize the matrix (allocate the memory for matrix)
{
	double **x;
	int i, j;//x is a matrix pointer
        x = (double **) malloc(r * sizeof(double *));// Allocating the space for r row pointers x[0],x[1],----x[r-1]

        for (i=0; i<r; i++)
         	x[i] = (double *) malloc(c * sizeof(double));// Now Allocate space for c elements in each row and assign go its pointer 

return(x);
}


//typedef struct node{
//int data;
//struct node *next;
//} NODE;

int main(int argc, char const *argv[])
{
		struct rusage memory_used;
		int n,beta,i,j;
		clock_t start,end;
		start=clock();
	FILE *out1=fopen("./Out/out1.dat","w");
	FILE *out2=fopen("./Out/out2.dat","w");
	FILE *out3=fopen("./Out/out3.dat","w");
	printf("Please enter the value of N:");
	scanf("%d",&n);
	printf("Please enter the value of beta (Fixed) :");
	scanf("%d",&beta);
	double **arr,b[n],d[n],a[n],r[n],theta[n],theex[n],error=0;
	arr=init_2d(n,n);
	//int size = ( sizeof(arr[i][j])*n*n) + ( sizeof(double)*6*n) + sizeof(double) + sizeof(int)*4 + sizeof(clock_t)*2;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				arr[i][j]=-beta-2*(n-1)*(n-1);
			}
			else if(i==j+1 || i==j-1)
			{
				arr[i][j]=(n-1)*(n-1);	
			}
			
			else 
				arr[i][j]=0;
		}
	}

	arr[0][0]=1;
	arr[0][1]=0;
	arr[n-1][n-2]=-1;
	arr[n-1][n-1]=1;
	fprintf(out1,"The Tri-Diagonal Matrix is as follows:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
				fprintf(out1,"%lf \t",arr[i][j]);
			
		}
		fprintf(out1,"\n");
	}


	for(i=1;i<n;i++)
	{
	b[i]=(n-1)*(n-1);
	}
	for(i=0;i<n;i++)
	{
	d[i]=-beta-2*(n-1)*(n-1);
	}
	for(i=0;i<n-1;i++)
	{
	a[i]=(n-1)*(n-1);
	}
	for(i=0;i<n;i++)
	{
		r[i]=0;
	}
	d[0]=1;
	d[n-1]=1;
	a[0]=0;
	b[n-1]=-1;
	b[0]=0;//of no Use
	a[n-1]=0;//of no Use
	r[0]=1;

	fprintf(out1,"The values of array b are:\n");
	for(i=1;i<n;i++)
	{
		fprintf(out1,"b[%d]=%lf \n",i+1,b[i]);
	}
	fprintf(out1,"\nThe values of main diagonal d are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(out1,"d[%d]=%lf \n",i+1,d[i]);
	}
	fprintf(out1,"\nThe values of array a are:\n");
	for(i=0;i<n-1;i++)
	{
		fprintf(out1,"a[%d]=%lf \n",i+1,a[i]);
	}
	fprintf(out1,"\nThe values of right side vector r are:\n");
	for(i=0;i<n;i++)
	{
	fprintf(out1,"r[%d]=%lf \n",i+1,r[i]);
	}

	for(i=1;i<n;i++)
	{
		d[i]=d[i]-((a[i-1]*b[i])/d[i-1]);
		r[i]=r[i]-((r[i-1]*b[i])/d[i-1]);
	}
	theta[n-1]=(double)r[n-1]/d[n-1];
	for(i=n-2;i>=0;i--)
	{
		theta[i]=(double)(r[i]-a[i]*theta[i+1])/d[i];
	}
	for(i=0;i<n;i++)
	{
		theex[i]=cosh(sqrt(beta)*(n-i)/n)/cosh(sqrt(beta));
	}

	for(i=0;i<n;i++)
	{
	fprintf(out2,"%lf\t%lf\t%lf\n",theta[i],theex[i],(double)i/n);
	}
	for(i=0;i<n;i++)
	{
	error=(double)error+((theta[i]-theex[i])*(theta[i]-theex[i])/(double)n);
	}
	error=sqrt(error);
	fprintf(out3,"%lf\t%d\n",error,n);
	end=clock();

	printf("Writing the ouptut in the result files\nTime taken is %lf s\n",(double)(end-start)/CLOCKS_PER_SEC);
	getrusage(RUSAGE_SELF,&memory_used);
	printf("Total space required is %ld bytes\n",memory_used.ru_maxrss);
	printf("Plotting the required graphs..\n");
	
	//fclose(out);
		
	    
	    //fprintf(out2,"The Optimum Threshold is %d\nTotal Time Taken %lf\n",opt,timeb);

		char * gnu1[] = {"set term wxt enhanced","set output './Plots/a.png'","set xlabel \"theta\"","set ylabel \"x*\"",
									"set title \"x* vs theta \"","set yrange [0:1]","set xrange [0:1]",
									"plot './Out/out2.dat' using 1:3 with lines","set term png"};

	char * gnu2[] = {"set term wxt enhanced","set output './Plots/b.png'","set xlabel \"theta exact\"","set ylabel \"x*\"",
									"set title \"x* vs theta exact\"","set yrange [0:1]","set xrange [0:1]",
									"plot './Out/out2.dat' using 2:3 with lines","set term png"};

	int g ;
	FILE * gnuplot1 = popen ("gnuplot -persistent", "w");
	FILE * gnuplot2 = popen ("gnuplot -persistent", "w");
	for(g=0;g<9;g++)
	{
		fprintf(gnuplot1, "%s \n", gnu1[g]);
	}
	for(g=0;g<9;g++)
	{
		fprintf(gnuplot2, "%s \n", gnu2[g]);
	}
	fclose(out1);
	fclose(out2);
	fclose(out3);
	pclose(gnuplot1);
	pclose(gnuplot2);
	return 0;
}






