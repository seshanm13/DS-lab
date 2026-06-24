// Program 12: Implement graph traversal - BFS and DFS
#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int vertices;

void enqueue(int value) {
    queue[++rear] = value;
}

int dequeue() {
    return queue[++front];
}

void BFS(int start) {
    int i;
    printf("BFS Traversal: ");
    visited[start] = 1;
    enqueue(start);
    while(front != rear) {
        int node = dequeue();
        printf("%d ", node);
        for(i = 0; i < vertices; i++) {
            if(graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void DFS(int start) {
    int i;
    printf("%d ", start);
    visited[start] = 1;
    for(i = 0; i < vertices; i++) {
        if(graph[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges;
    int i, src, dest;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++) {
        visited[i] = 0;
        for(int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    for(i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}
