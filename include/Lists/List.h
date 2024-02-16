#include "Lists/Node.h"

typedef struct List {
    Node *head;
    Node *tail;
    int length;

    void (*prepend)(struct List *self, int item);
    void (*append)(struct List *self, int item);
    char *(*toString)(struct List *self);
    int (*get)(struct List *self, int index);
    void (*insertAt)(struct List *self, int item, int index);
    void (*removeAt)(struct List *self, int index);
} List;

List *newList(int *array, int n);

void prepend(List *self, int item);

void append(List *self, int item);

char *toString(List *self);

int get(List *self, int index);

void insertAt(List *self, int item, int index);

void removeAt(List *self, int index);
