// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>
#include <string.h>

#define MAX 1000

int arr[MAX];
int size = 0;

void insert(int x) {
    arr[size++] = x;
}

int findMinIndex() {
    if(size == 0) return -1;

    int minIndex = 0;
    for(int i = 1; i < size; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void deleteMin() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    int minValue = arr[minIndex];

    for(int i = minIndex; i < size-1; i++) {
        arr[i] = arr[i+1];
    }

    size--;
    printf("%d\n", minValue);
}

void peek() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", arr[minIndex]);
}

int main() {

    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for(int i = 0; i < N; i++) {

        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0) {
            deleteMin();
        }
        else if(strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}