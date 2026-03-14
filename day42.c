// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10


#include <stdio.h>
#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    int x = queue[front];
    front++;
    return x;
}

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    int x = stack[top];
    top--;
    return x;
}

int main()
{
    int n, i, x;

    scanf("%d", &n);

    // Input queue elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue elements to stack
    for(i = 0; i < n; i++)
    {
        push(dequeue());
    }

    // Step 2: Move stack elements back to queue
    for(i = 0; i < n; i++)
    {
        enqueue(pop());
    }

    // Step 3: Print reversed queue
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
