typedef struct String {
    char *value;
    int length;
    int bufferSize;

    void (*setValue)(struct String *self, char *str);
    void (*concat)(struct String *self, struct String *str);
    void (*concatCString)(struct String *self, char *str);
}String;

char *numberToString(int number);

String *newString();
String *newStringFrom(char *str);

void concatCString(String *self, char *str);

void concat(String *self, String *str);

void setValue(String *self, char *str);
