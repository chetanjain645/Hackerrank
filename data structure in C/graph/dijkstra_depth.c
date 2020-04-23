/* program to find shortest distances using dijkstra's Algorithm */

#include<stdio.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

void findpath(int s,int v);
void dijkstra(int s);
int min_temp();
void create_graph();

int n;   //Denotes number of vertices in the graph
int adj[MAX][MAX];
int predecessor[MAX]; //predecessor of each vertex in shortest path
int pathlength[MAX];
int status[MAX];

int main()
{
    int s,v;

    create_graph();
    printf("Enter source vertex : ");
    scanf("%d",s);
    dijkstra(s);

    while(1)
    {
        printf("Enter destination vertex (-1 to quit) : ");
        scanf("%d",&v);
        if(v==-1)
            break;
        else if(v<0 || v>=n)
            printf("This vertex doesn't exist \n");
        else if(v==s)
            printf("Source and Destination Vertices are same\n");
        else if(pathlength[v]==infinity)
            printf("There is no path between source to Destiantion vertex\n ");
        else
            findpath(s,v);
    }
    return 0;
} //End of main


void dijkstra(int s)
{
    int i,current;
    /*Make all vertices temporary*/
    for(i=0;i<n;i++)
    {
        predecessor[i]=NIL;
        pathlength[i]=infinity;
        status[i]=TEMP;
    }
    /* Make pathlength of source vertex equal to 0*/
    pathlength[s]=0;
    while(1)
    {
        /*search for temporary vertex with minimum pathlength and
        make it current vertex*/
        current = min_temp();
        if(current==NIL)
            return;
        status(current) = PERM;
        for(i=0; i<n; i++)

    }
}
