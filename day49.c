// Problem: BST Insert

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    // If tree is empty
    if (root == NULL) {
        return createNode(val);
    }

    // Go to left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // Go to right subtree
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal (to check BST)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, val;

    scanf("%d", &n);  // number of nodes

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Print inorder traversal
    inorder(root);

    return 0;
}