#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Lists/List.h"
#include "Strings/String.h"

List *newList(int *array, int n) {
    List *list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    list->get = get;
    list->prepend = prepend;
    list->append = append;
    list->toString = toString;
    list->insertAt = insertAt;
    list->removeAt = removeAt;
    
    for (int i = 0; i < n; i++) {
        list->append(list, array[i]);
    }

    return list;
}

Node *getNode(List *self, int index) {
    Node *current = self->head;

    if (current == NULL) {
        fprintf(stderr, "Error: Failed to obtain List element at index %i", index);
        abort();
    }

    if (index < 0 || index >= self->length) {
        fprintf(stderr, "Error: Failed to obtain List element at index %i", index);
        abort();
    }

    for (int i = 0; i != index; i++) {
        current = current->next;
    }

    return current;
}

int get(List *self, int index) {
    Node *searchedNode = getNode(self, index);

    return  searchedNode->value;
}

void prepend(List *self, int item) {
    Node *node = newNode(item);

    if (self->head == NULL) {
        self->head = node;
        self->tail = node;
    } else {
        self->head->previous = node;
        node->next = self->head;
        self->head = node;
    }

    self->length++;
}

void append(List *self, int item) {
    Node *node = newNode(item);

    if (self->head == NULL) {
        self->head = node;
        self->tail = node;
    } else {
        self->tail->next = node;
        node->previous = self->tail;
        self->tail = node;
    }

    self->length++;
}


void insertAt(List *self, int item, int index) {
    Node *new = newNode(item);
    Node *current = getNode(self, index);

    if (current->previous != NULL)
        current->previous->next = new;
    else
        self->head = new;

    new->previous = current->previous;
    new->next = current;
    current->previous = new;

    self->length++;
}

void removeAt(List *self, int index) {
    Node *current = getNode(self, index);
    
    if (current->previous != NULL)
        current->previous->next = current->next;
    else {
        self->head = current->next;
    }

    if (current->next != NULL)
        current->next->previous = current->previous;
    else {
        self->tail = current->previous;
    }

    free(current);

    self->length--;
}

char *toString(List *self) {
    String *result = newStringFrom("[");
    Node *current = self->head;

    for (int i = 0; i < self->length; i++) {
        char *value = numberToString(current->value);

        result->concatCString(result, value);

        if (i != self->length - 1) {
            result->concatCString(result, ", ");
        }

        free(value);

        current = current->next;
    }
    
    result->concatCString(result, "]");

    return result->value;
}
