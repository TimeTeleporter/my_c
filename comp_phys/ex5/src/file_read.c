#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* ptr = fopen("power_series.txt", "r");

    int array[10];
    for(int i = 0; i<10; i++) fscanf(ptr, "%d", array+i);

    for(int i = 0; i<10; i++) printf("%d\n", array+i);

    fclose(ptr);
    return 0;
}