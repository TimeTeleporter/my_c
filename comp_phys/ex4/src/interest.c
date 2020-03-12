#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_data(double* capital, double* interest, int* years, int* rate) {
    do {
        printf("Your starting capital (CHF): ");
        scanf("%lf", capital);
    } while(*capital < 0);
    do {
        printf("The interest rate (percent): ");
        scanf("%lf", interest);
    } while(*interest < 0);
    do {
        printf("How many years do you want to recieve interest (years)? ");
        scanf("%d", years);
    } while(*years < 0);
    do {
        printf("At what rate do you want to recieve interest (times/year)? ");
        scanf("%d", rate);
    } while(*rate < 0);
}

int main() {
    double capital = 0, interst = 0;
    int years = 0, rate = 0;

    read_data(&capital, &interst, &years, &rate);
    
    interst = 1+interst/100/rate;
    years *= rate;

    for(int time=0; time<years; time++) {
        capital *= interst;
    }

    printf("Your resulting capital will be %lf CHF.\n", capital);
    
    return 0;
}