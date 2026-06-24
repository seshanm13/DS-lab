// Program 11: Represent a graph using adjacency matrix and adjacency list

// --- Using Adjacency Matrix ---
#include <stdio.h>
#define MAX 10

int main1() {
    int graph[MAX][MAX];
    int vertices, edges;
    int i, j, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
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

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// --- Using Adjacency List ---
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];

struct Node* createNode(int v) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    struct Node *newNode;
    newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void display(int vertices) {
    int i;
    struct Node *temp;
    printf("\nAdjacency List:\n");
    for(i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        temp = adjList[i];
        while(temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, edges;
    int i, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    display(vertices);
    return 0;
}
