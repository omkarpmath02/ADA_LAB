#include <stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int n, i, j, s;
    int a[MAX][MAX], dist[MAX], visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    /* Initialize distances */
    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s] = 0;

    /* Dijkstra's Algorithm */
    for(i = 0; i < n - 1; i++)
    {
        int min = INF, u = -1;

        /* Find minimum distance vertex */
        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        /* Update distances */
        for(j = 0; j < n; j++)
        {
            if(!visited[j] && a[u][j] && dist[u] + a[u][j] < dist[j])
            {
                dist[j] = dist[u] + a[u][j];
            }
        }
    }

    /* Output */
    printf("\nShortest distances from vertex %d:\n", s);
    for(i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
