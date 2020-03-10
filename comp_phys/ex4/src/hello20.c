#include <stdio.h>
#include <stdlib.h>

int hello20(int times) {
    for(int i; i<times; i++) {
        printf("Hello World!\n");
    }
}

int main(int argc, char *argv[]) {
    if(argc == 2){
        hello20(atoi(argv[1]));
    }
    else {
        printf("Tell us, how many times you want to print it.\n");
    }
    return 0;
}