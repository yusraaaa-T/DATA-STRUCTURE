#include <stdio.h>

#define N 7

int graph[N][N] = {
    {0,1,0,0,0,0,0},
    {1,0,1,0,0,0,0},
    {0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,1,0}
};

int visited[N] = {0};

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);
    int i;

    for (i = 0; i < N; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int clusterNo = 1;
    int i;
    for (i = 0; i < N; i++) {
        if (visited[i] == 0) {
            printf("Cluster %d: ", clusterNo);
            dfs(i);
            printf("\n");
            clusterNo++;
        }
    }

    return 0;
}

