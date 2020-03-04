#include <stdio.h>
#include <string.h>

int array_size(char **arr) {
    int size = 0;

    while(*(arr++)) {
        size += 1;
    }

    return size;
}

int main() {
    char* strings[] = {"a", "b", "A", "B", NULL};
    int num_strings = array_size(strings);
    printf("strings has %d elements.\n", num_strings);
    
    printf("%d\n", sizeof(strings)/sizeof(*strings) -1 );

    return 0;
}