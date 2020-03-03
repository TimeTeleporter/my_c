#include <stdio.h>
#include <string.h>

int array_size(char **arr) {
    return sizeof(arr)/sizeof(*arr);
}

int main() {
    char* strings[] = {"a", "b", "A", "B"};
    int num_strings = array_size(strings);
    printf("strings has %d elements.\n", num_strings);
    
    printf("%d\n", sizeof(strings)/sizeof(*strings));
    
    return 0;
}