#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct {
    char name[32];
    int number;
} Object;

void obj__init__(Object*);
void objprint(Object);

int main() {
    int obj_size = 4;
    Object* obj1 = (Object*) malloc(sizeof(Object)*obj_size);
    for(int i = 0; i<obj_size; i++) obj__init__(obj1+i);

    objprint(obj1[2]);

    Object* obj2 = obj1;

    objprint(obj2[2]);

    obj1[2].number = 3;

    free(obj1);

    objprint(obj1[2]);
    objprint(obj2[2]);

    return 0;
}

void obj__init__(Object* ptr) {
    strcpy(ptr->name, "Standardobjekt");
    ptr->number = 0;
}

void objprint(Object obj) {
    printf("%s has %d\n", obj.name, obj.number);
}