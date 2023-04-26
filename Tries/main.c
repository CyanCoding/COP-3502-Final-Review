#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct trie {
    struct trie *children[ALPHABET_SIZE];
    int isEndOfWord;
} trie;

// Creates a new trie structure
trie *init() {
    trie *node = malloc(sizeof(trie));

    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

// Adds to a trie if it is not already present there
void add(trie *root, char *key) {
    int length = strlen(key);

    trie *current = root;
    for (int i = 0; i < length; i++) {
        int char_int = ((int)key[i]) - ((int)'a');

        if (!current->children[char_int])
            current->children[char_int] = init();

        current = current->children[char_int];
    }
    current->isEndOfWord = 1;
}

// Gets the amount of letters in our trie that match the word we're looking for
// If return = length of word, the word is in our trie already
int search(trie *root, char *key) {
    int length = strlen(key);
    int count = 0;

    trie *current = root;

    for (int i = 0; i < length; i++) {
        int char_int = ((int)key[i]) - ((int)'a');

        if (!current->children[char_int])
            return count;
        count++;
        current = current->children[char_int];
    }
    return count;
}

int main() {
    // Make sure 10 is longer or equal to any length of word in our array
    char keys[][10] = {"actor", "bank", "cat", "capitol", "caption"};

    trie *root = init();

    // 5 is length of keys
    for (int i = 0; i < 5; i++)
        add(root, keys[i]);

    char word[] = "capitulate";
    int word_length = strlen(word);
    int result = search(root, word);
    printf("We have %d/%d letters of %s in our trie.\n", result, word_length, word);

    return 0;
}
