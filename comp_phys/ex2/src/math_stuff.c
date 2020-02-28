#include <stdio.h>
#include <math.h>
#include <string.h>

double main(int argc, char *argv[]) {
    char *stringly = argv[1];
    double input = atof(argv[2]), result;

    printf("Function: %s\n", stringly);
    printf("Input: %lf\n", input);

    if(strcmp(stringly, "sin") == 0) {
        printf("computing sin...");
        result = sin(input);
    }
    else if(strcmp(stringly, "cos") == 0) {
        printf("computing cos...");
        result = cos(input);
    }
    else {
        printf("computing 1-(x^2)/2+(x^4)/24");
        result = 1-pow(input,2)/2 + pow(input, 4)/24;
    }
    printf("The result is: %lf", result);

    return result;
}
