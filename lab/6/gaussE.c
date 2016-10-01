#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/resource.h>
double ** init_2d (int r, int c) //Initialize the matrix (allocate the memory for matrix)
{
    double **x;
    int i, j;//x is a matrix pointer
        x = (double **) malloc(r * sizeof(double *));// Allocating the space for r row pointers x[0],x[1],----x[r-1]

        for (i=0; i<r; i++)
            x[i] = (double *) malloc(c * sizeof(double));// Now Allocate space for c elements in each row and assign go its pointer 

return(x);
}

int main()
{


    struct rusage memory_used;
    int n,beta,i,j,k;
    clock_t start=clock(),end;
    FILE *out1=fopen("./Out/out4.dat","w");
    FILE *out2=fopen("./Out/out5.dat","w");
    FILE *out3=fopen("./Out/out6.dat","w");
    printf("Please enter the value of N:");
    scanf("%d",&n);
    printf("Please enter the value of beta (Fixed) :");
    scanf("%d",&beta);
    double **arr,theta[n],theex[n],error=0,s,p;
    arr=init_2d(n,n+1);
    //int size = ( sizeof(arr[i][j])*n*n) + ( sizeof(double)*2*n) + sizeof(double)*3 + sizeof(int)*5 + sizeof(clock_t)*2;

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

    fprintf(out1,"The Tri-Diagonal Matrix is as follows:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
                fprintf(out1,"%lf \t",arr[i][j]);
            
        }
        fprintf(out1,"\n");
    }

    for(k=0;k<n-1;k++) //making an upper triangular matrix
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
    fprintf(out2,"%lf\t%lf\t%lf\n",theta[i],theex[i],(double)i/n);
    }
    for(i=0;i<n;i++)
    {
    error=(double)error+((theta[i]-theex[i])*(theta[i]-theex[i])/(double)n);
    }
    error=sqrt(error);
    fprintf(out3,"%lf\t%d\n",error,n);
    end=clock();

    printf("Writing the ouptut in the result files\nTime taken is %lf s\n ",(double)(end-start)/CLOCKS_PER_SEC);
    getrusage(RUSAGE_SELF,&memory_used);
    printf("Total space required is %ld bytes\n",memory_used.ru_maxrss);
    printf("Plotting the required graphs..\n");
    
    //fclose(out);
        
        
        //fprintf(out2,"The Optimum Threshold is %d\nTotal Time Taken %lf\n",opt,timeb);

        char * gnu1[] = {"set term wxt enhanced","set output './Plots/d.png'","set xlabel \"theta\"","set ylabel \"x*\"",
                                    "set title \"x* vs theta \"","set yrange [0:1]","set xrange [0:1]",
                                    "plot './Out/out5.dat' using 1:3 with lines","set term png"};

    char * gnu2[] = {"set term wxt enhanced","set output './Plots/e.png'","set xlabel \"theta exact\"","set ylabel \"x*\"",
                                    "set title \"x* vs theta exact\"","set yrange [0:1]","set xrange [0:1]",
                                    "plot './Out/out5.dat' using 2:3 with lines","set term png"};

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
    return(0);

}
