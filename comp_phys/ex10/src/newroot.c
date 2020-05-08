#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x);
float fprime(float x);

int input(float*);

float precision = 1e-8;
float root(float value);

int main() {
    /*Initialization*/
    float start=0;

    /*Input*/
    if(input(&start) != 0) return 0;

    /*Logic*/
    float toot = root(start);

    printf("The root is at x = %f", toot);

    return 0;
}

float f(float x) {
    /* Returns the value of the function at a given x value.*/
    return exp(-x)-x;
}

float fprime(float x) {
    /* Returns the value of the derrivative of the function above at a given x value.*/
    return -exp(-x)-1;
}

int input(float* ptr) {
    /* Reads the number, returns 1 if it already is a root of f(x).*/
    float number = 0;
    printf("Enter a number: ");
    scanf("%f", &number);

    /*Already a root*/
    if(f(number) == 0.) {
        printf("%f is the root.", number);
        return 1;
    }

    *ptr = number;

    return 0;
}

float root(float value) {
    float old_value;
    do {
        old_value = value;
        value = value - f(value)/fprime(value);
    } while(fabsf(value-old_value) >= precision);
    return value;
}