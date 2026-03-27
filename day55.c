#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order
struct Queue {
    struct TreeNode* arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    struct TreeNode* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (i < n && !isEmpty(&q)) {
        struct TreeNode* curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Right View Function
void rightView(struct TreeNode* root) {
    if (!root) return;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);

            // last node of level
            if (i == size - 1) {
                printf("%d ", node->val);
            }

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    rightView(root);

    return 0;
}