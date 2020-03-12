#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please give one argument.\n");
        return 1;
    }

    int number = atoi(argv[1]);

    if(ceil(atof(argv[1])) != number) {
        printf("Please only integers.\n");
        printf("%d", number);
        return 1;
    }

    int top = ceil(sqrt(number));

    if(number % 2 == 0 && number != 2) {
        printf("%d devides %d.\n", 2, number);
        return 0;
    }
    for(int i = 3; i<=top; i+=2) {
        if(number % i == 0) {
            printf("%d devides %d.\n", i, number);
            return 0;
        }
    }
    printf("%d is prime.\n", number);
    return 0;
}