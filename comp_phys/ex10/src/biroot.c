#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x);
int input(float*, float*);

float precision = 1e-8;
float root(float positive, float negative);

int main() {
    /*Initialization*/
    float postitive=0, negative=0, c=0;

    /*Input*/
    if(input(&postitive, &negative) != 0) return 0;

    /*Logic*/
    float toot = root(postitive, negative);

    printf("The root is at x = %f", toot);

    return 0;
}

float f(float x) {
    return exp(-x)-x;
}

int input(float* positive, float* negative) {
    float a=0, b=0;
    printf("Enter the first number: ");
    scanf("%f", &a);
    printf("Enter the second number: ");
    scanf("%f", &b);

    /*Already a root*/
    if(f(a) == 0.) {
        printf("%f is the root.", a);
        return 1;
    }
    if(f(b) == 0.) {
        printf("%f is the root.", b);
        return 1;
    }

    /* No root inbetween */
    if(f(a)*f(b) > 0) {
        printf("Please enter two numbers with an odd number of roots inbetween.\n");
        input(&a, &b);
    }

    /* Determine the positive and negative numbers */
    if(f(a) > 0) {
        *positive = a;
        *negative = b;
    }
    else {
        *positive = b;
        *negative = a;
    }

    return 0;
}

float root(float positive, float negative) {
    float difference = fabsf(positive-negative), middle;

    do {
        middle = positive/2. + negative/2.;

        if(f(middle) >= 0.) {
            positive = middle;
        }
        else {
            negative = middle;
        }
        difference = difference/2;
    } while (difference >= precision);
    
    return middle;
}