// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex, weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Min heap node
struct HeapNode {
    int vertex, dist;
};

// Min heap
struct MinHeap {
    int size;
    struct HeapNode arr[MAX];
};

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Extract min
struct HeapNode extractMin(struct MinHeap* heap) {
    struct HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

// Insert into heap
void insertHeap(struct MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->arr[i].vertex = v;
    heap->arr[i].dist = dist;

    while (i && heap->arr[i].dist < heap->arr[(i - 1) / 2].dist) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

// Main
int main() {
    int n, m, u, v, w, source;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}