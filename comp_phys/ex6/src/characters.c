#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int main() {
    char input[MAX];
    
    printf("Give your input string of max %d characters: ", (int) MAX);
    gets(input);

    printf("%s\n", input);

    return 0;
}