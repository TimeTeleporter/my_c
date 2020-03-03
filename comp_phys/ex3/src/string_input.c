#include <stdio.h>
#include <string.h>

int main() {
    char target[16];
    char input[16];

    printf("Write your first string.\n");
    scanf("%s", target);
    printf("Your input is %s\n", target);
    printf("Write your second string.\n");
    scanf("%s", input);
    printf("Your input is %s\n", input);
    printf("Are those strings equal?\n");
    if(!strcmp(target, input)){
        printf("Yes they are!");
    }
    else {
        printf("Sadly, nope, they aren't.");
    }
    return 0;
}