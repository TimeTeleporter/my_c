#include <stdio.h>
#include <stdlib.h>

int result = 0;
void reverse(int);

int main() {
    int input = 0;
    printf("Enter a integer:");
    scanf("%d", &input);

    reverse(input);

    printf("%d", result);

    return 0;
}

int next = 0;
void reverse(int input) {
    result = result*10 + input%10;
    next = (input-input%10)/10;
    if (next != 0) reverse(next);
    return;
}