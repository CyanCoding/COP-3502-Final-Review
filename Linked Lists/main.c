#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} node;

char *linked_list_to_str(node *head, int length) {
    // Chars are size 1
    char *string = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        string[i] = head->data;
        head = head->next;
    }
    string[length] = '\0';

    return string;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
