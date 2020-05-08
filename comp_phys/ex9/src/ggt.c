#include <stdio.h>

void input(unsigned int* a, unsigned int* b);
unsigned int logic(unsigned int x, unsigned int y);

int main() {
    unsigned int a = 0;
    unsigned int b = 0;

    input(&a, &b);

    unsigned int ggt = logic(a, b);

    printf("The greatest common divisor of %u and %u is %u", a, b, ggt);

    return 0;
}

void input(unsigned int* a, unsigned int* b) {
    printf("Enter the first positive integer:");
    scanf("%u", a);
    printf("Enter the second porsitive integer:");
    scanf("%u", b);
    return;
}

unsigned int logic(unsigned int x, unsigned int y) {
    if(y == 0) return x;
    else return logic(y, x%y);
}