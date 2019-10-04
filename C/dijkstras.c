#include<stdio.h>

void dijkstras(int cost[20][20], int source, int visited[20], int d[20], int n)
{
    int i, j, min, v, w;
    for(i=1; i<=n; i++)
    {
        visited[i]=0;
        d[i]=cost[source][i];
    }
    visited[source]=1;
    d[source]=0;
    for(j=2; j<=n; j++)
    {
        min = 999;
        for(i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                if(d[i]<min)
                {
                    min = d[i];
                    v=i;
                }
            }
        }
        visited[v]=1;
        for(w=1; w<=n; w++)
        {
            if(cost[v][w]!=999 && visited[w]==0)
            {
                if(d[w] > cost[v][w]+d[v])
                {
                    d[w] = cost[v][w] + d[v];
                }
            }
        }
    }
}

void main()
{
    int i, j, cost[20][20], d[20], visited[20], n, source;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter the source matrix\n");
    scanf("%d",&source);
    dijkstras(cost, source, visited, d, n);
    for(i=1; i<=n; i++)
    {
        if(i!=source)
        {
            printf("Shortest path from %d to %d = %d\n",source, i, d[i]);
        }
    }
}
