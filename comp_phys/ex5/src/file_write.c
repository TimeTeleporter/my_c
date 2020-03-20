#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    unsigned int array[16];
    int array_len = 10;
    if(argc = 2) {
        array_len = atoi(argv[1]);
    }
    printf("%d", array_len);

    array[0] = 1;
    for(int i=1; i<array_len; i++) array[i] = array[i-1]*2;

    FILE* ptr = fopen("./bin/power_series.txt", "w");

    for(int i=0; i<array_len; i++) fprintf(ptr, "%d\n", array[i]);

    fclose(ptr);
    return 0;
}