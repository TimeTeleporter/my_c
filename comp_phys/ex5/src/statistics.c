#include <stdio.h>
#include <math.h>

int main() {
    /* Initialization */
    int array[3];
    int array_size = sizeof(array)/sizeof(*array);
    for(int i = 0; i<array_size; i++) array[i] = 0;

    /* Input */
    printf("Please enter %d integers.\n", array_size);
    for(int i = 0; i<array_size; i++) {
        scanf("%d", array+i);
    }

    /* Logic */
    double sum = 0.;
    for(int i = 0; i<array_size; i++) sum += array[i];
    double average = sum/array_size;

    double var = 0;
    for(int i = 0; i<array_size; i++) {
        var += pow((double)array[i]- average, 2);
    }
    double sd = sqrt(var);

    /* Return */
    printf("The average of the given values is: %lf\n", average);
    printf("The standard deviation is: %lf\n", sd);

    return 0;
}