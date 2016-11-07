#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int** create (int V)																			
{
	int **x,i;
	x= (int**)malloc(V+1*sizeof(int*));												
	for (i=0; i<V+1; i++)
         x[i] = (int *) malloc(V+1 * sizeof(int));
    return(x);
}


int main()
{
	int V,E,**graph,i,j,k,pos; 
	scanf("%d",&V);
	scanf("%d",&E);
	int size[V] ;
	float weight[V+1][V+1],ans ;
	graph=create(V);
	for(i=1;i<V+1;i++)
	{
		size[i]=1;
	}
	for(i=1;i<=V;i++)
	{
		for(j=1;j<=V;j++)
		{
			graph[i][j]=-1;
			weight[i][j]=0;
		}
	}
	for(i=0;i<E;i++)
	{
		int s , d ;
		float wgt ;
		scanf("%d %d %f",&d,&s,&wgt);
		weight[s][d]=wgt;
		graph[s][size[s]]=d;
		size[s]++;
	}
	int src ;
	float currw ;
	scanf("%d %f",&src , &currw);
	
	for(i=1;i<=V;i++)
	{
		j=1;
		while(graph[i][j]!=-1)
		{
			printf("%d ",graph[i][j]);
			j++;
		}
		printf("\n");
	}
	/*for(i=1;i<=V;i++)
	{
		for(j=1;j<=V;j++)
		{
			printf("%f",weight[i][j]);
		}
		printf("\n");
	}*/
	
	float dist[V+1];
	for(i=1;i<=V;i++)
	{
		if(i==src)
			dist[i]=0;
		else
			dist[i]=INT_MAX;
	}

	for(i=1;i<V+1;i++)
	{
		float temp[V+1];
		for(j=1;j<=V;j++)
		{
			temp[j]=dist[j];
		}
		for(j=1;j<=V;j++)
		{
			if(j==src)
				continue;
			float min = temp[j];
			k=1;
			while(graph[j][k]!=-1)
			{
				if(dist[graph[j][k]]+weight[j][graph[j][k]]<min&& i==V)
				{
					printf("The Graph Contains negative cycle \n");
					return 0 ;
				}
				if(dist[graph[j][k]]+weight[j][graph[j][k]]<min)
				{
					min=dist[graph[j][k]]+weight[j][graph[j][k]];
				}
				k++;
			}
			temp[j]=min;
		}

		for(j=1;j<=V;j++)
		{
			dist[j]=temp[j];
			printf("%f ",dist[j]);
		}
		printf("\n");
	}

	ans=dist[1];
	pos=1;

	for(i=2;i<V;i++)
	{
		if(dist[i]<ans)
		{
			ans=dist[i];
			pos=i;
		}
	}

	ans = pow(10,ans);
	printf("%d %f ",pos,ans);

}