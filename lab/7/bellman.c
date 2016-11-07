#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int** create (int V)	//to create the adjacency list(using dynamically allocated array																		
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
		graph[s][size[s]]=d;//save the pints which are connected in adjacency list
		size[s]++;//increase the number of that vertex connected to s
	}
	int src ;
	float currw ;
	scanf("%d %f",&src , &currw);
	
	/*for(i=1;i<=V;i++)
	{
		j=1;
		while(graph[i][j]!=-1)
		{
			printf("%d ",graph[i][j]);
			j++;
		}
		printf("\n");
	}
	for(i=1;i<=V;i++)
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
			dist[i]=0;//initialize src to src distance to 0 and others to infinity
		else
			dist[i]=INT_MAX;
	}

	for(i=1;i<V;i++)//loop to find minimum distance values using upto n-1 edges
	{
		float temp[V+1];//create a temp array to store the previous distances
		for(j=1;j<=V;j++)
		{
			temp[j]=dist[j];//assign the dist values to temp for all the vertices
		}
		for(j=1;j<=V;j++)
		{
			if(j==src)
				continue;// dist of src from src will always remain zero  
			float min = temp[j];//assign the value of distance calculated without using any neighbours
			k=1;
			while(graph[j][k]!=-1)//to loop through all neighbours of a vertex and find the minimum distance
			{
				if(dist[graph[j][k]]+weight[j][graph[j][k]]<min)
				{
					min=dist[graph[j][k]]+weight[j][graph[j][k]];
				}
				k++;
			}
			temp[j]=min;//assign the min value to temp[j]
		}

		for(j=1;j<=V;j++)
		{
			dist[j]=temp[j];//store the distances in dist array from temp array 
			//printf("i=%d %f ",i,dist[j]);
		}
		
			
		
		printf("\n");
	}

	ans=dist[1];
	pos=1;

	for(i=2;i<V;i++)
	{
		if(dist[i]<ans)//find the minimum shortest path distance 
		{
			ans=dist[i];
			pos=i;
		}
	}

	ans = currw*pow(10,ans);//find the final weight 
	printf("%d %f \n",pos,ans);

}
