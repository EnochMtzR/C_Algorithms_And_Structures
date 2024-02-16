#include <stdlib.h>

#include "Lists/Node.h"

Node *newNode(int value) {
    Node *node = malloc(sizeof(Node));

    node->previous = NULL;
    node->next = NULL;
    node->value = value;

    return node;
}
