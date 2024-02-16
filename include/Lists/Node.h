#include <stdlib.h>

typedef struct T {
    void *value;
    size_t size;
} T;

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *previous;
} Node;

Node *newNode(int value);
