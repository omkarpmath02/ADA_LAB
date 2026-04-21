#include <stdio.h>

#define MAX 20
#define INF 9999

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int min, mincost = 0;
    int a, b, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Start from vertex 0
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    // We need n-1 edges
    for (int edge_count = 0; edge_count < n - 1; edge_count++) {
        min = INF;

        for (i = 0; i < n; i++) {
            if (visited[i]) { // only from visited vertices
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("Edge %d: (%d -> %d) cost = %d\n",
               edge_count + 1, a, b, min);

        mincost += min;
        visited[b] = 1; // include new vertex

        // Remove edge
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}