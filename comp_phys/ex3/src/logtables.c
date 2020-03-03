#include <stdio.h>
#include <string.h>
#include <math.h>

/* The idea is to return the operation tables of the functions and, or, nand, nor and not*/

void not_table();
void and_table();
void or_table();
void nand_table();
void nor_table();

int main() {
    const char* ops[] = {"not", "and", "or", "nand", "nor"};
    const int num_ops = sizeof(ops)/sizeof(*ops);
    char* input;

    printf("This program returns the logical tables for some basic logical operators.\n");
    printf("Currently supported are: ");
    for(int i=0; i<num_ops; i++) {
        printf("\"%s\" ", ops[i]);
    }

    printf("\n");
    printf("What operator table do you want to see?\n");
    scanf("%s", input);

    if(strcmp(input, ops[0]) == 0) {
        not_table();
    }
    else if(strcmp(input, ops[1]) == 0) {
        and_table();
    }
    else if(strcmp(input, ops[2]) == 0) {
        or_table();
    }
    else if(strcmp(input, ops[3]) == 0) {
        nand_table();
    }
    else if(strcmp(input, ops[4]) == 0) {
        nor_table();
    }
    else {
        printf("You really wanna see it all!\n");
        not_table();
        and_table();
        or_table();
        nand_table();
        nor_table();
    }

    return 0;
}
void not_table() {
    printf("The \"not\"-table:\n");
    printf("%-3s | %-3s\n", "a", "!a");
    for(int a=0; a<2; a++) {
        printf("%-3d | %-3d\n", a, !a);
    }
    return;
}
void and_table() {
    printf("The \"and\"-table:\n");
    printf("%-3s | %-3s | %-3s\n","a","b", "a and b");
    for(int a=0; a<2; a++) {
        for(int b=0; b<2; b++) {
            printf("%-3d | %-3d | %-3d\n", a, b, a&&b);
        }
    }
    return;
}
void or_table() {
    printf("The \"or\"-table:\n");
    printf("%-3s | %-3s | %-3s\n","a","b", "a or b");
    for(int a=0; a<2; a++) {
        for(int b=0; b<2; b++) {
            printf("%-3d | %-3d | %-3d\n", a, b, a||b);
        }
    }
    return;
}
void nand_table() {
    printf("The \"nand\"-table:\n");
    printf("%-3s | %-3s | %-3s\n","a","b", "a or b");
    for(int a=0; a<2; a++) {
        for(int b=0; b<2; b++) {
            printf("%-3d | %-3d | %-3d\n", a, b, !(a&&b));
        }
    }
    return;
}
void nor_table() {
    printf("The \"nor\"-table:\n");
    printf("%-3s | %-3s | %-3s\n","a","b", "a or b");
    for(int a=0; a<2; a++) {
        for(int b=0; b<2; b++) {
            printf("%-3d | %-3d | %-3d\n", a, b, !(a||b));
        }
    }
    return;
}