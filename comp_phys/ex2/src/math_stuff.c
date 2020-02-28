#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Only two arguments work!");
        return 1;
    }

    char *stringly = argv[1];
    double input = atof(argv[2]), result;

    printf("Function: %s\n", stringly);
    printf("Input: %lf\n", input);

    if(strcmp(stringly, "sin") == 0) {
        printf("computing sin...\n");
        result = sin(input);
    }
    else if(strcmp(stringly, "cos") == 0) {
        printf("computing cos...\n");
        result = cos(input);
    }
    else {
        printf("computing 1-(x^2)/2+(x^4)/24...\n");
        result = 1-pow(input,2)/2 + pow(input, 4)/24;
    }
    printf("The result is: %lf\n", result);

    return 0;
}