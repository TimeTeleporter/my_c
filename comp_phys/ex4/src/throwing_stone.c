#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myfuncs.h"

void read_data(double* angleptr, double* velocityptr, double* heightptr) {
    do {
        printf("At which angle do you want to throw it? (deg)\n");
        scanf("%lf", angleptr);
    } while(fabs(*angleptr) > 90);
    do {
        printf("How fast do you throw it? (meters/second)\n");
        scanf("%lf", velocityptr);
    } while(*velocityptr <= 0);
    do {
        printf("And how high above the ground are you? (meters)\n");
        scanf("%lf", heightptr);
    } while(*heightptr < 0);
    return;
}

void throw(double angle, double velocity, double height, double* distanceptr, int notes) {
    double vy = velocity*sin(angle), vx = velocity*cos(angle), g = 9.81;

    double time = quadratic(-g/2., vy, height);

    if(notes > 0) {
        double interval = time/(notes+1.);
        for(int i = 1; i< (notes+1); i++) {
            printf("(x, y): (%lf, %lf)\n", vx*interval*i+(*distanceptr), height + vy*interval*i - g/2.*pow(i*interval,2.));
        }
    }

    *distanceptr += vx*time;
    return;
}

int main(int argc, char* argv[]) {
    double angle = 0, velocity = 0, height = 0, distance = 0;
    int notes = 0;

    if(argc == 2) notes = atoi(argv[1]);
    read_data(&angle, &velocity, &height);
    angle = angle*M_PI/180.;

    printf("Angle: %lf, Velocity: %lf, Height %lf\n", angle, velocity, height);

    throw(angle, velocity, height, &distance, notes);

    printf("Distance: %lf", distance);

    return 0;
}