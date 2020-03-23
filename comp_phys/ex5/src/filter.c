#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double p1, p2, p3;
    double value = 30.;
    double transverse = 0.;

    FILE* data = fopen("data/data.txt", "r");
    FILE* filter = fopen("data/filterdata.txt", "w");

    while(feof(data) == 0) {
        fscanf(data, "%lf %lf %lf", &p1, &p2, &p3);

        if(value < sqrt(p1*p1 + p2*p2)) {
            fprintf(filter, "%3.3lf %3.3lf %3.3lf\n", p1, p2, p3);
        }
    }

    fclose(data);
    fclose(filter);

    return 0;
}