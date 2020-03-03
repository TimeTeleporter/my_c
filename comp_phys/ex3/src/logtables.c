#include <stdio.h>
#include <string.h>
#include <math.h>

/* The idea is to return the operation tables of the functions and, or, nand, nor and not*/

int not_table() {
    printf("%-5s | %-5s\n", "a", "!a");
    for(int a=0; a<2; a++) {
        printf("%-5s | %-5s\n", a, !a);
    }
    return 0;
}

int main() {
    const int num_ops = 1;
    const char* operators[] = {"not", "something_else"};
    char* input;

    printf("This program returns the logical tables for some basic logical operators.\n");
    printf("Currently supported are: ");
    for(int i=0; i<num_ops; i++) {
        printf("%s ", operators[i]);
    }

    printf("\n");
    printf("What operator table do you want to see?\n");
    scanf("%s", input);

    printf("Something else: %s\n", operators[1]);
    printf("%s\n", input);

    int index;

    for(int i=0; i<num_ops; i++) {
        printf("%d", index);

        printf("%d", strcmp(input, operators[i]));
        /*
        if(strcmp(input,operators[i])) {
            printf("You chose %s", operators[i]);
            index = i;
        }
        */
    }

    return 0;
}