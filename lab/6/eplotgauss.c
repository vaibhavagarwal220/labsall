/***********************************************
Name: Vaibhav Agarwal
Roll: B15139
Purpose: IC250 Assignment 05 - Question 1 
Date: 28/09/2016
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//typedef struct node{
//int data;
//struct node *next;
//} NODE;
double ** init_2d (int r, int c) //Initialize the matrix (allocate the memory for matrix)
{
	double **x;
	int i, j;//x is a matrix pointer
        x = (double **) malloc(r * sizeof(double *));// Allocating the space for r row pointers x[0],x[1],----x[r-1]

        for (i=0; i<r; i++)
         	x[i] = (double *) malloc(c * sizeof(double));// Now Allocate space for c elements in each row and assign go its pointer 

return(x);
}

int main(int argc, char const *argv[])
{
		int n,beta=100,i,j,k;
	FILE *out3=fopen("./Out/out6.dat","w");
	for(n=10;n<=100;n++){	
double **arr,theta[n],theex[n],error=0,s,p;
    arr=init_2d(n,n+1);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
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
    arr[0][n]=1;
    arr[n-1][n]=0;

    

    for(k=0;k<n-1;k++)
 {
  for(i=k+1;i<n;i++)
  {
   p = arr[i][k] / arr[k][k] ;
   for(j=k;j<n+1;j++)
    arr[i][j]=arr[i][j]-p*arr[k][j];
  }
 }

    theta[n-1]=arr[n-1][n]/arr[n-1][n-1];

 for(i=n-2;i>=0;i--)
 {
  s=0;
  for(j=i+1;j<n;j++)
  {
   s +=(arr[i][j]*theta[j]);
   theta[i]=(arr[i][n]-s)/arr[i][i];
  }
 }
 

    for(i=0;i<n;i++)
    {
        theex[i]=cosh(sqrt(beta)*(n-i)/n)/cosh(sqrt(beta));
    }
 
    for(i=0;i<n;i++)
    {
    error=(double)error+((theta[i]-theex[i])*(theta[i]-theex[i])/(double)n);
    }
    error=sqrt(error);
    fprintf(out3,"%lf\t%d\n",error,n);
	
	
	//fclose(out);
	    //fprintf(out2,"The Optimum Threshold is %d\nTotal Time Taken %lf\n",opt,timeb);

	}
	char * gnu3[] = {"set term wxt enhanced","set output './Plots/f.png'","set xlabel \"error\"","set ylabel \"N\"",
									"set title \"N vs error\"","set yrange [0:0.01]","set xrange [10:100]",
									"plot './Out/out6.dat' using 2:1 with lines","set term png"};
	int g ;
	FILE * gnuplot3 = popen ("gnuplot -persistent", "w");
	for(g=0;g<9;g++)
	{
		fprintf(gnuplot3, "%s \n", gnu3[g]);
	}

	fclose(out3);
  pclose(gnuplot3);
	return 0;
}






