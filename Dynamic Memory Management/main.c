#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct tree {
    struct tree *left;
    struct tree *right;

    int value;
    node *head;
} tree;

// Delete an entire tree list by freeing memory
tree *deleteTreeList(tree *root) {
    // Already done
    if (root == NULL)
        return NULL;

    // Delete the linked list on this tree item
    node *current = root->head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    // Recursively delete the child branches
    root->left = deleteTreeList(root->left);
    root->right = deleteTreeList(root->right);
    free(root);

    return NULL;
}
