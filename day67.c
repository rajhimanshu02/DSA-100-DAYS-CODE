// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adj[MAX];
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add directed edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// DFS function
void dfsTopo(struct Graph* graph, int v, int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];

    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfsTopo(graph, temp->vertex, visited, stack, top);
        }
        temp = temp->next;
    }

    // Push to stack after visiting all neighbors
    stack[++(*top)] = v;
}

// Topological Sort function
void topologicalSort(struct Graph* graph) {
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            dfsTopo(graph, i, visited, stack, &top);
        }
    }

    // Print stack in reverse order
    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}