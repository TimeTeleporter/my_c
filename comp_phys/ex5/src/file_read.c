#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* ptr = fopen("power_series.txt", "r");

    if(ptr == NULL) {
        printf("No file anywhere to be seen.");
        return 1;
    }

    int array[10];

    int i = 0;
    while(feof(ptr) == 0) {
        fscanf(ptr, "%d", array+i);
        i++;
    }

    for(int j = 0; j<i; j++) printf("%d\n", *(array+j));

    fclose(ptr);
    return 0;
}