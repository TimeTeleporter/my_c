#include <stdio.h>
#include <stdlib.h>

int count_zeros(unsigned int input);
int count_ones(unsigned int input);

int main() {
    unsigned int integer = 0;

    /* Input */
    printf("Please enter a positive integer:");
    scanf("%u", &integer);

    /* Logic */
    int zeros = count_zeros(integer);
    int ones = count_ones(integer);

    printf("Your given integer has %d zeros and %d ones.\n", zeros, ones);

    return 0;
}

int count_zeros(unsigned int input) {
    int sum = 0;
    unsigned int x = input;
    for(int i = 0; i<8*sizeof(input); i++) {
        if((x&~1) == x) sum++; /* It changes the first bit only if it isnt a zero, thus it only counts zeros. */
        x = x >> 1;
    }
    return sum;
}

int count_ones(unsigned int input) {
    int sum = 0;
    unsigned int x = input;
    for(int i = 0; i<8*sizeof(input); i++) {
        if((x|1) == x) sum++; /* It changes the first bit only if it isnt a one, thus it only counts ones. */
        x = x >> 1;
    }
    return sum;
}