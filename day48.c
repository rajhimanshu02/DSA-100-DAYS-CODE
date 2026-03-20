// Problem: Count Leaf Nodes

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // If it's a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Count in left + right
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Driver code
int main() {
    /*
        Creating tree:
              1
             / \
            2   3
           / \
          4   5
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int result = countLeafNodes(root);
    printf("Leaf nodes count: %d\n", result);

    return 0;
}

