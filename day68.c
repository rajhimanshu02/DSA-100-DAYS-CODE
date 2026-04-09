// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Function for Topological Sort
void topologicalSort(int graph[MAX][MAX], int n) {
    int indegree[MAX] = {0};
    int i, j, count = 0;

    // Step 1: Calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    // Step 3: Process queue
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Step 4: Check cycle
    if (count != n)
        printf("\nCycle detected! Topological sort not possible.\n");
}

int main() {
    int n, graph[MAX][MAX], i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, n);

    return 0;
}