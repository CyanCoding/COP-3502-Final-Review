#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int val;
    struct tree *left;
    struct tree *right;
} tree;

// Add leaves to our tree
tree *add(int data) {
    tree *leaf = malloc(sizeof(tree));
    leaf->val = data;
    leaf->right = NULL;
    leaf->left = NULL;

    return leaf;
}

// The inorder version of traversing
// Prints from left leaves up and down to right leaves
void inorder(tree *root) {
    // When you get to the end of a branch
    if (root == NULL)
        return;

    // Go down both sides
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// The preorder version of traversing
// Prints branches before leaves
void preorder(tree *root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// The postorder version of traversing
// Goes from a bottom up technique
void postorder(tree *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    // Init
    tree *root = malloc(sizeof(tree));
    root->val = 500;
    root->left = add(100);
    root->right = add(20);
    root->left->left = add(120);
    root->left->right = add(18);
    root->right->right = add(15);

    printf("Tree visual:\n");
    printf("        500\n");
    printf("        / \\\n");
    printf("      100  20\n");
    printf("      / \\    \\\n");
    printf("    120 18   15\n\n");

    printf("Inorder traversal:\n");
    inorder(root);

    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\nPostorder traversal:\n");
    postorder(root);

    return 0;
}
