typedef struct intList* intList;

intList create(int capacity);
void destroy(intList *list);
int size(intList list);
int capacity(intList list);
int get(intList list, int index);
void set(intList list, int index, int value);
void append(intList list, int value);
void print(intList list);