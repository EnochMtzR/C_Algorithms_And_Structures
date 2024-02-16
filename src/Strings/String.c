#include <stdio.h>
#include <stdlib.h>

#include "Strings/String.h"


char *numberToString(int number) {
    int valueLength = snprintf(NULL, 0, "%d", number);
    char *valueString = malloc(valueLength + 1);

    snprintf(valueString, valueLength + 1, "%d", number);

    return valueString;
}

String *newString() {
    String *string = malloc(sizeof(String));

    string->length = 0;
    string->bufferSize = 16;
    string->value = calloc(string->bufferSize, 1);

    string->concat = concat;
    string->concatCString = concatCString;
    string->setValue = setValue;

    return string;
}

String *newStringFrom(char *str) {
    String *string = newString();

    string->setValue(string, str);

    return string;
}

void appendCharacter(String *self, char character) {
    if (self->length + 1 == self->bufferSize) {
        self->bufferSize *= 2;
        self->value = realloc(self->value, self->bufferSize);
    }

    self->value[self->length] = character;

    self->length++;

    self->value[self->length] = '\0';
}

void setValue(String *self, char *str) {
    self->length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        appendCharacter(self, str[i]);
    }
}

void concatCString(String *self, char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        appendCharacter(self, str[i]);
    }
}

void concat(String *self, String *str) {
    concatCString(self, str->value);
}
