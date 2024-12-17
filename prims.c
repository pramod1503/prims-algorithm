#include <stdio.h>
#include <stdlib.h>
#define INF 999999

void prims(int n, int cost[10][10])
{
    int i, j, u, v, min, mincost = 0, visited[10] = {0}, ne = 0;
    
    printf("The edges considered for MST are:\n");
    visited[0] = 1;  // Start with the first vertex
    
    while (ne < n - 1)
    {
        min = INF;
        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        
        if (min != INF)
        {
            printf("Edge %d: (%d,%d) cost: %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
            cost[u][v] = cost[v][u] = INF;  // Mark as visited
        }
    }
    
    printf("Total cost of MST is: %d\n", mincost);
}

int main()
{
    int i, j, n, cost[10][10];
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    
    prims(n, cost);
    
    return 0;
}