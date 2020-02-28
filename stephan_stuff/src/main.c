#include <stdio.h>
#include <stdlib.h>


int main() {
    const int a = 10;
    *((int*)&a) = 20;

    printf("%d\n", a);
}