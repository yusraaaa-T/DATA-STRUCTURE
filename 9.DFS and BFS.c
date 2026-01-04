#include <stdio.h>
#include <stdlib.h>

#define N 4

int visited[N];   

void DFS(int v, int graph[N][N]) {
    visited[v] = 1;
    printf("%d ", v);
	int i;
    for (i = 0; i < N; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, graph);
        }
    }
}

void BFS(int start, int graph[N][N]) {
    int queue[20];
    int front = 0, rear = 0;
    int visitedBFS[N] = {0};

    visitedBFS[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
		int i;
        for (i = 0; i < N; i++) {
            if (graph[v][i] == 1 && !visitedBFS[i]) {
                visitedBFS[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int graph[N][N];
    int start;
	int i;
	int j;
    printf("Adjacency matrix girin :\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Baslangic dugumunu girin:");
    scanf("%d", &start);

    
    for ( i = 0; i < N; i++)
        visited[i] = 0;

    printf("DFS traversal:");
    DFS(start, graph);

    printf("\nBFS traversal:");
    BFS(start, graph);

    return 0;
}


