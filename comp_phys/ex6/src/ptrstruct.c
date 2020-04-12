#include <stdio.h>
#include <stdlib.h>

void man(int*);

struct ptrstruct {
    int thing;
} big;

int main() {
    man(&big.thing);
    printf("%d\n", big.thing);
    return 0;
}

void man(int* stuff) {
    scanf("%d", stuff);
    return;
}