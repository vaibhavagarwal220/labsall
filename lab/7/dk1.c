#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>
#define maxVertices 100
#define  inf 1000010000

typedef struct Node
{
        int vertex,distance;
}Node;
Node heap[1000000];

int visited[maxVertices];
int heapSize;

int** create (int v)              //create the adjacency list (using dynamically allocated array)                                                           
{
    int **x,i;
    x= (int**)malloc(v+1*sizeof(int*));                                                             
    for (i=0; i<v+1; i++)
         x[i] = (int *) malloc(v+1 * sizeof(int));
    return(x);
}

void Init()//to initialize the heap
{
        heapSize = 0;
        heap[0].distance = -INT_MAX;
        heap[0].vertex  = -1;
}

void Insert(Node element) //to insert an element into heap
{
        heapSize++;
        heap[heapSize] = element;
        int i = heapSize;
        while(heap[i/2].distance > element.distance) 
        {
                heap[i] = heap[i/2];
                i /= 2;
        }
        heap[i] = element;
}

Node DeleteMin() //delete an element from heap
{
        Node minElement,lastElement;
        int child,i;
        minElement = heap[1];
        lastElement = heap[heapSize--];
        for(i = 1; i*2 <= heapSize ;i = child)
        {
            child = i*2;
            if(child != heapSize && heap[child+1].distance < heap[child].distance) 
            {
                child++;
            }
            if(lastElement.distance > heap[child].distance)
            {
                heap[i] = heap[child];
            }
            else 
            {
                break;
            }
        }
        heap[i] = lastElement;
        return minElement;
}
int main()
{
    int v,E,**graph,i,j,k; 
    scanf("%d",&v);
    scanf("%d",&E);
    int size[v+1],dist[v+1] ;
    int weight[v+1][v+1];
    graph=create(v);
    for(i=1;i<v+1;i++)
    {
        size[i]=1;
    }
    for(i=1;i<=v;i++)//assign the initial values to adjacency list
    {
        for(j=1;j<=v;j++)
        {
            graph[i][j]=-1;
            weight[i][j]=0;
        }
    }
    for(i=0;i<E;i++)
    {
        int s , d ;
        float wgt ;
        scanf("%d %d %f",&s,&d,&wgt);
        if(wgt<0)
        {
            printf("Distances should be +ve.\n");
            return 0 ;
        }
        weight[s][d]=wgt;
        graph[s][size[s]]=d;
        size[s]++;
    }
    int src , no ;
    int host[no+1];
    scanf("%d %d",&src , &no);
    for(i=1;i<=no;i++)
    {
        scanf("%d",&host[i]);//to store the hostels where CS is played
    }
    
    Node temp;
    for(i=1;i<=v;i++)
    {
        if(i==src)
        {
                temp.distance = 0;
                dist[i]=0;
        }
        else
        {
                temp.distance = inf;
                dist[i]= inf;
        }
        temp.vertex = i;
        Insert(temp);
    }//to initialize the values in the priority queue

    while(heapSize)
    {
            Node del = DeleteMin();
            int mindist = del.vertex;
            if(visited[mindist])
            {
                    continue;
            }
            visited[mindist] = 1;
            for(i=1;i<size[mindist];i++)//to relax the neighbour vertices
            {
                    int to = graph[mindist][i];
                    if(dist[to] > dist[mindist] + weight[mindist][to])
                    {
                            dist[to] = dist[mindist] + weight[mindist][to];
                            temp.vertex = to;
                            temp.distance = dist[to];
                            Insert(temp);
                    }
            }
    }

    /*for(i=1;i<=v;i++)
    {
            printf("vertex is %d, its distance is %d\n",i,dist[i]);
    }*/
   
    for(i=1;i<=no;i++)
    {
        printf("%d %d\n",host[i],dist[host[i]]);
    }
     return 0;




}
