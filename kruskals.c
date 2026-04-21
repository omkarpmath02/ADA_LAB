#include <stdio.h>

#define MAX 20
#define INF 9999

int parent[MAX];

// Find root of a node
int find(int i) {
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

// Union of two sets
void union_set(int u, int v) {
    parent[v] = u;
}

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int min, mincost = 0;
    int a, b, u, v;

    // Initialize parent array
    for (i = 0; i < MAX; i++)
        parent[i] = -1;

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

    printf("\nEdges in Minimum Spanning Tree:\n");

    // Kruskal's algorithm
    for (int edge_count = 0; edge_count < n - 1; edge_count++) {
        min = INF;

        // Find minimum edge
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find roots
        u = find(u);
        v = find(v);

        // If no cycle, include edge
        if (u != v) {
            printf("Edge %d: (%d -> %d) cost = %d\n",
                   edge_count + 1, a, b, min);
            mincost += min;
            union_set(u, v);
        }

        // Remove edge from matrix
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
