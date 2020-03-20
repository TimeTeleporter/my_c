#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double matrix[3][3];
    int dimensions = 3;

    for(int row = 0; row<dimensions; row++) {
        for(int col = 0; col<dimensions; col++) {
            if(row == col) matrix[row][col] = 1.;
            else matrix[row][col] = 0.;
        }
    }

    for(int row = 0; row<dimensions; row++) {
        for(int col = 0; col<dimensions; col++) {
            printf("%3.1lf    ", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}