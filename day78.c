
// Input Format
// n m
// u v w
// ...
// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mst[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST(int graph[MAX][MAX], int n) {
    int key[MAX], mst[MAX];
    
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0; // start from node 0

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mst, n);
        mst[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++)
        total += key[i];

    return total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; // convert to 0-based index
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int result = primMST(graph, n);
    printf("%d\n", result);

    return 0;
}