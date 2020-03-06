#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned long long ones(int times) {
    return (pow(10,times)-1)/9;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Please make sure to have exactly 2 arguments.\n");
        printf("First comes the number you whish to print, then how many times it should be printed.\n");
        return 1;
    }
    if(argv[1] <= 0 || argv[2] <= 0) {
        printf("Those numbers are not positive! Pls dont.");
        return 1;
    }

    unsigned long long number = atoi(argv[1]);
    int number_size = ceil(log10(number+1));
    unsigned long long repeats = atoi(argv[2]);
    unsigned long long number_row = 0;

    long double nines = pow(10, number_size*(repeats))/ones(number_size);
    number_row = (nines)/9*number;

    printf("%d", number_row);

    return 0;
}