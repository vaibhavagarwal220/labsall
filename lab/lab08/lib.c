#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1000000
int V;
int** create (int v)	

{
	int **x,i;
	x= (int**)malloc(v*sizeof(int*));												
	for (i=0; i<v; i++)
         x[i] = (int *) malloc(v* sizeof(int));
    return(x);
}

int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
int printSolution(int dist[], int n)
{
   printf("V      Distance\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int **graph, int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V);
}
int main()
{
	srand(time(NULL));
	int n , **maze , i , j ,sq,x,y,mazend=0,**edge;
	while(1)
	{
		scanf("%d",&n);
		sq = sqrt(n);
		if(sq*sq!=n)
		{
			printf("Please enter a perfect square ()\n");
		}
		else
		{
			break;
		}
	}
	V=n;
	maze = create(sq);
	edge = create(n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			edge[i][j]=0;
		}
	}
	for(i=0;i<sq;i++)
	{
		for(j=0;j<sq;j++)
		{
			maze[i][j]=0;
		}
	}
	i=rand()%sq;
	j=rand()%sq;
	maze[i][j]=1;
	int fron[3*n][3] ;
	for(x=0;x<n;x++)
	{
		fron[x][0]=0;
	}
	fron[0][0]=2;
	fron[0][1]=i;
	fron[0][2]=j;
	int frct =1 ;

	for(x=0;x<sq;x++)
	{
		for(y=0;y<sq;y++)
		{
			printf("%d ",maze[x][y]);
		}
		printf("\n");
	}
	
	while(1)
	{
		mazend=0;
		for(x=0;x<sq;x++)
		{
			for(y=0;y<sq;y++)
			{
				if(maze[x][y]==2 || maze[x][y]==0)
				{
					mazend=1;
					break;
				} 

			}
			if(mazend==1)
				break;
		}
		if(mazend==0)
		{
			break;
		}

		
		int up,down,left,right;
		up=i-1;
		down=i+1;
		left=j-1;
		right=j+1;
		//printf("%d %d %d %d\n",up,down,left,right);
		if(up>=0 && maze[up][j]==0)
		{
			fron[frct][0]=1;
			fron[frct][1]=up;
			fron[frct][2]=j;
			frct++;
			maze[up][j]=2;
			//printf("up\n");
		}
		if(down<=sq-1 && maze[down][j]==0)
		{
			fron[frct][0]=1;
			fron[frct][1]=down;
			fron[frct][2]=j;
			frct++;
			maze[down][j]=2;
			//printf("down\n");
		}
		if(left>=0 &&  maze[i][left]==0)
		{
			fron[frct][0]=1;
			fron[frct][1]=i;
			fron[frct][2]=left;
			frct++;
			maze[i][left]=2;
			//printf("left\n");
		}
		if(right<=sq-1 && maze[i][right]==0)
		{
			fron[frct][0]=1;
			fron[frct][1]=i;
			fron[frct][2]=right;
			frct++;
			maze[i][right]=2;
			//printf("right\n");
		}
		/*for(x=0;x<=frct;x++)
		{
			printf("%d ",fron[x][0]);
		}
		printf("\n");*/
		int c ;
		while(1)
		{
			c = rand()%frct ; 
			//printf("%d ",c);
			if(fron[c][0]==1)
			{
				fron[c][0]=2;
				i=fron[c][1];
				j=fron[c][2];
				//printf("%d %d",i,j);
				maze[i][j]=1;
				break;
			}
		}
		printf("\n");
		for(x=0;x<sq;x++)
		{
			for(y=0;y<sq;y++)
			{
				printf("%d ",maze[x][y]);
			}
			printf("\n");
		}
		printf("\n");
		maze[i][j]=1;
		up=i-1;
		down=i+1;
		left=j-1;
		right=j+1;
		if(up>=0 && maze[up][j]==1)
		{
			edge[sq*i+j][sq*up+j]=1;
			edge[sq*up+j][sq*i+j]=1;
			//printf("%d %d %d %d\n",i,j,up,j);
			continue;
		}
		if(down<=sq-1 && maze[down][j]==1)
		{
			edge[sq*i+j][sq*down+j]=1;
			edge[sq*down+j][sq*i+j]=1;
			//printf("%d %d %d %d\n",i,j,down,j);
			continue;
		}
		if(left>=0 &&  maze[i][left]==1)
		{
			edge[sq*i+j][sq*i+left]=1;
			edge[sq*i+left][sq*i+j]=1;
			//printf("%d %d %d %d\n",i,j,i,left);
			continue;
		}
		if(right<=sq-1 && maze[i][right]==1)
		{
			edge[sq*i+j][sq*i+right]=1;
			edge[sq*i+right][sq*i+j]=1;
			//printf("%d %d %d %d\n",i,j,i,right);
			continue;
		}
	}

	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
		{
			printf("%d ",edge[x][y]);
		}
		printf("\n");
	}
	int source ;
	printf("Enter source \n");
	scanf("%d",&source);
	dijkstra(edge,source);

}

