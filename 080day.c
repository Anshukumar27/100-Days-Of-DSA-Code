#include <stdio.h>
#include <limits.h>

#define MAXN 105

int min(int a, int b) {
    return (a < b) ? a : b;
}

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {
    int dist[MAXN][MAXN];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int result = -1;
    int minCount = INT_MAX;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        if (count <= minCount) {
            minCount = count;
            result = i;
        }
    }

    return result;
}

int main() {
    int n = 4;
    int edges[][3] = {
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int edgesSize = 4;
    int distanceThreshold = 4;

    int ans = findTheCity(n, edges, edgesSize, distanceThreshold);
    printf("Output: %d\n", ans);

    return 0;
}