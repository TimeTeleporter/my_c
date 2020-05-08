#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <search.h>

/* Defining the constants and functions of the program */
float A_0 = 2.0;
float yamma = 0.3;
float omega_1 = 3./2.;
float omega_2 = 17./4.;
float myFuncA(float t);
float myFuncAprime(float t);

/* The precision and method of finding the root */
float precision = 1e-8;
float root(float value);

/* Array shenanigans */
int isNewRoot(float* array, unsigned int array_entries, float new_root);
int isInInterval(float* interval, float num);
void addArrayEntry(float* array, unsigned int* array_size, unsigned int* array_entries, float add);
void printArrayEntries(float* array, unsigned int array_entries);

/* Methods for bookkeeping */
void userInput(float* interval, float* step_ptr);

int main() {
    /* Initialize the user input and other variables */
    float interval[2] = {0., 0.};
    float step = 0.1;

    userInput(interval, &step);

    float pos = interval[0];

    /* Create an expanding array for storage*/
    unsigned int array_size = 4, array_entries = 0;
    float* array = (float*) malloc(array_size*sizeof(float));

    float toot; /* temporary root */

    while(pos <= interval[1]) {
        toot = root(pos);

        if(isNewRoot(array, array_entries, toot) && isInInterval(interval, toot)) {
            addArrayEntry(array, &array_size, &array_entries, toot);
        }

        pos = pos + step;
    }

    printArrayEntries(array, array_entries);

    return 0;
}

float myFuncA(float t) {
    /* Returns the value of the function at a given value.
    The constants are defined at the function definitions.*/
    return A_0*expf(-yamma*t)*(cosf(omega_1*t)+sinf(omega_2*t));
}

float myFuncAprime(float t) {
    /* Returns the value of the derrivative of the function above at a given value.
    The constants are defined at the function definitions.*/
    return A_0*(yamma*expf(-yamma*t)*(cosf(omega_1*t)+sinf(omega_2*t))
                +expf(-yamma*t)*(-omega_1*sinf(omega_1*t)+omega_2*cosf(omega_2*t)));
}

float root(float value) {
    /* Calculates the zeros of a given function, its derrivative and a starting value
    using the newton-method. */
    float old_value;
    do {
        old_value = value;
        value = value - myFuncA(value)/myFuncAprime(value);
    } while(fabsf(value-old_value) >= precision);
    return value;
}

int isNewRoot(float* array, unsigned int array_entries , float new_root) {
    for(int i = 0; i<array_entries; i++){
        if (new_root == array[i]) return 0;
    }

    return 1;
}

int isInInterval(float* interval, float num) {
    if(interval[0]<= num && num <= interval[1]) return 1;
    return 0;
}

void addArrayEntry(float* array, unsigned int* array_size, unsigned int* array_entries, float add) {
    if((*array_entries)+1 >= *array_size) {
        *array_size = (*array_size)*2;
        array = (float*) realloc(array, (*array_size)*sizeof(float));
    }
    array[*array_entries] = add;
    *array_entries = *array_entries + 1;
    return;
}

void printArrayEntries(float* array, unsigned int array_entries) {
    printf("These are the %u roots in the interval:\n", array_entries);
    for(int i = 0; i<array_entries; i++) {
        printf("x_%d = %f\n", i, array[i]);
    }
}

void userInput(float* interval, float* step_ptr) {
    float a, b, stp;
    printf("Enter the start of the interval: ");
    scanf("%f", &a);
    printf("Enter the end of the interval: ");
    scanf("%f", &b);

    if(a<b) {
        *interval = a;
        *(interval+1) = b;
    }
    else {
        *interval = b;
        *(interval+1) = a;
    }

    printf("Enter the step width: ");
    scanf("%f", &stp);

    *step_ptr = fabsf(stp);
    return;
}