#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 9999

int parent[MAX];

// Find function (Disjoint Set)
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Union function
void union_set(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, i, j, a, b, u, v;
    int min, mincost = 0;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // No edge treated as infinity
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int edge_count = 1; edge_count < n; edge_count++) {
        min = INF;

        // Find smallest edge
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find roots of vertices
        u = find(u);
        v = find(v);

        // If no cycle, include edge
        if (u != v) {
            printf("Edge %d: (%d -> %d) cost = %d\n", edge_count, a, b, min);
            mincost += min;
            union_set(u, v);
        }

        // Remove edge from consideration
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}