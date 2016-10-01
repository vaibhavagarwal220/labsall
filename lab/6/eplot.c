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

int main(int argc, char const *argv[])
{
		int n,beta=100,i,j;
	FILE *out3=fopen("./Out/out3.dat","w");
	for(n=10;n<=100;n++){
	double b[n],d[n],a[n],r[n],theta[n],theex[n],error=0;

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
	error=(double)error+((theta[i]-theex[i])*(theta[i]-theex[i])/(double)n);
	}
	error=sqrt(error);
	
	fprintf(out3,"%lf\t%d\n",error,n);
	
	
	//fclose(out);
	    //fprintf(out2,"The Optimum Threshold is %d\nTotal Time Taken %lf\n",opt,timeb);

	}
	char * gnu3[] = {"set term wxt enhanced","set output './Plots/c.png'","set xlabel \"error\"","set ylabel \"N\"",
									"set title \"N vs error\"","set yrange [0:0.01]","set xrange [10:100]",
									"plot './Out/out3.dat' using 2:1 with lines","set term png"};
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






