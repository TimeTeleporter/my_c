#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double quadratic(double a, double b, double c) {
    b = b/a;
    c = c/a;
    double wurzel = pow(b,2.)/4. - c;
    if(wurzel < 0) {
        printf("There's no solution to this quadratic.");
        return 0;
    }
    double solution = -b/2. + sqrt(wurzel);
    double other_sol = -b/2. - sqrt(wurzel);
    if(other_sol > solution) {
        solution = other_sol;
    }
    return solution;
}