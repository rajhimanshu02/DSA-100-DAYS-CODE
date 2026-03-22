// Problem: BST Search

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

// ✅ Define struct FIRST
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ✅ Then write function
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

// Helper to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Build a sample BST:
    //        4
    //       / \
    //      2   7
    //     / \
    //    1   3
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int target = 2;
    struct TreeNode* result = searchBST(root, target);

    if (result != NULL)
        printf("Found node with value: %d\n", result->val);
    else
        printf("Value %d not found in BST\n", target);

    return 0;
}