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
/*add other includes as necessary*/

int ** init_2d (int r, int c) //Initialize the matrix (allocate the memory for matrix)
{
	int **x, i, j;//x is a matrix pointer
        x = (int **) malloc(r * sizeof(int *));// Allocating the space for r row pointers x[0],x[1],----x[r-1]

        for (i=0; i<r; i++)
         	x[i] = (int *) malloc(c * sizeof(int));// Now Allocate space for c elements in each row and assign go its pointer 

return(x);
}
/* creates matrix mat */
int** create_D (int r, int c ,char *file)
{
	int **x,i,j;
	FILE *fp=fopen(file,"r");
	if(fp==NULL){
					printf("Error opening file");
					return 0;
				}
        x=init_2d(r,c);//Matrix Allocation
	for ( i = 0 ; i < r ; i++ )
	{
		for ( j = 0 ; j < c ; j++ )
		{	
			fscanf(fp,"%d",&x[i][j]);

			// Polpulating Matrix 
		}
	}
	printf ( "\n" ) ;
        return(x);
}

//typedef struct node{
//int data;
//struct node *next;
//} NODE;

int main(int argc, char const *argv[])
{
	clock_t start,betw,final;
	start=clock();
	long long int a[256],histc[256];
	double amean,bmean,sdeva,sdevb,np,di,asum,bsum,na,nb,optmin=1000000; 
	int temp,**x,i,j,th;
	int opt;
	FILE *out=fopen("out2.dat","w");
	FILE *out2=fopen("Final2.txt","w");
	char fnm[10];
	int r,c;
	strcpy(fnm,argv[1]);
	r=atoi(argv[2]);
	c=atoi(argv[3]);
	printf("%s %d %d",fnm,r,c);
	x=create_D(r,c,fnm);
	betw=clock();
	printf("	Reading the input data .........\nData read in %lf ms\n",(double)(betw-start)/CLOCKS_PER_SEC);
	fprintf(out2,"Data read in %lf ms\n",(double)(betw-start)/CLOCKS_PER_SEC);
	for(th=0;th<256;th++)
	{
		asum=0,bsum=0,na=0,nb=0,sdeva=0,sdevb=0;
		for(i=0;i<198;i++)
		{
			for(j=0;j<200;j++)
			{	
				if(x[i][j]<=th) 
					{	
						asum+=x[i][j];
						na++;
					}
				else 
					{	bsum+=x[i][j];
						nb++;
					}


			}	
		}	
		amean=asum/na;
		bmean=bsum/nb;
		for(i=0;i<198;i++)
		{
			for(j=0;j<200;j++)
			{	
				if(x[i][j]<=th) 
					{	
						sdeva+=(x[i][j]-amean)*(x[i][j]-amean);
					}
				else 
					{
						sdevb+=(x[i][j]-bmean)*(x[i][j]-bmean);
					}


			}	
		}
		sdeva/=na;
		sdevb/=nb;
		np=na/nb;
		if(fabs(np-1.0)<optmin)
		{
			optmin=fabs(np-1.0),opt=th;

		}
		di=fabs(amean-bmean)/sqrt(sdeva+sdevb);
		fprintf(out,"%d\t%lf\t%lf\n",th,di,np);
	}
	fclose(out);
		final = clock();
		
	    double timeb=(double)(final-betw)/CLOCKS_PER_SEC;
	    fprintf(out2,"The Optimum Threshold is %d\nTotal Time Taken %lf\n",opt,timeb);

	    printf("Performing iterative thesholding ...........\nThresholding done in %lf ms\n",timeb);
	    printf("out1.dat is generated at </home/lab/01/do>.\nGraphs are generated at </home/lab/01/do>\nFinal res.txt is generated at </home/lab/01/do>\n");
		char * gnu1[] = {"set term wxt enhanced","set xlabel \"d\'\"","set ylabel \"th\"",
									"set title \"th vs d\' \"","set yrange [0:260]","set xrange [0:5]",
									"plot 'out1.dat' using 2:1 with lines","set term png","set output 'a.png'",};

	char * gnu2[] = {"set term wxt enhanced","set xlabel \"np\"","set ylabel \"th\"",
									"set title \"th vs np\"","set yrange [0:260]","set xrange [0:320]",
									"plot 'out1.dat' using 3:1 with lines","set term png","set output 'b.png'",};

	char * gnu3[] = {"set term wxt enhanced","set xlabel\"np\"","set ylabel \"d\'\"",
									"set title \"d\' vs np \"","set yrange [0:5]","set xrange [0:320]",
									"plot 'out1.dat' using 3:2 with lines","set term png","set output 'c.png'",};
	int g ;
	FILE * gnuplot1 = popen ("gnuplot -persistent", "w");
	FILE * gnuplot2 = popen ("gnuplot -persistent", "w");
	FILE * gnuplot3 = popen ("gnuplot -persistent", "w");
	for(g=0;g<9;g++)
	{
		fprintf(gnuplot1, "%s \n", gnu1[g]);
	}
	for(g=0;g<9;g++)
	{
		fprintf(gnuplot2, "%s \n", gnu2[g]);
	}
	for(g=0;g<9;g++)
	{
		fprintf(gnuplot3, "%s \n", gnu3[g]);
	}
	return 0;
}