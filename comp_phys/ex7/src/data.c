#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Initialization */
    int array_size = 0;
    float* array = (float*) malloc(sizeof(float)*array_size);
    for(int i = 0; i<array_size; i++) array[i] = .0;

    /* Input */
    while(1) {
        int append_size = 0;

        printf("How many numbers do you want to enter? ");
        scanf("%d", &append_size);

        if(append_size == 0) break;

        int new_array_size = array_size+append_size;

        float* append = (float*) malloc(sizeof(float)*append_size);
        for(int i = 0; i<append_size; i++) append[i] = .0;

        float* new_array = (float*) malloc(sizeof(float)*new_array_size);
        for(int i = 0; i<array_size; i++) new_array[i] = array[i];
        for(int i = array_size; i<new_array_size; i++) new_array[i] = .0;

        printf("Please enter %d integers.\n", append_size);
        for(int i = 0; i<append_size; i++) {
            scanf("%f", append+i);
        }

        for(int i = 0; i<append_size; i++) new_array[i+array_size] = append[i];
        free(append);

        array = new_array;
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

    free(array);

    return 0;
}