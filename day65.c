// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adj;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = createNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;

    node = createNode(u);
    node->next = graph->adj[v];
    graph->adj[v] = node;
}

// DFS function to detect cycle
bool dfs(struct Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            if (dfs(graph, adjVertex, visited, v))
                return true;
        }
        else if (adjVertex != parent) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    return false;
}

// Function to check cycle in graph
bool hasCycle(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));

    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, -1))
                return true;
        }
    }

    return false;
}

// Main function
int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}