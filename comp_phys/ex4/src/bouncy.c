#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myfuncs.h"

double g = 9.81;

void read_data(double* angle, double* velocity, int* bounces) {
    do {
        printf("At which angle do you want to throw it? (deg)\n");
        scanf("%lf", angle);
    } while(*angle <= 0);
    do {
        printf("And how fast do you throw it? (meters/second)\n");
        scanf("%lf", velocity);
    } while(*velocity <= 0);
    do {
        printf("How many bounces do you want?\n");
        scanf("%d", bounces);
    } while(*bounces <= 0);
    return;
}

void throw(double* angleptr, double* velocityptr, double* distanceptr, int notes) {
    double angle = *angleptr, velocity = *velocityptr;
    double vy = velocity*sin(angle), vx = velocity*cos(angle);

    double time = quadratic(-g/2., vy, 0);

    if(notes > 0) {
        double interval = time/(notes+1.);
        for(int i = 1; i< (notes+1); i++) {
            printf("(x, y): (%lf, %lf)\n", vx*interval*i+(*distanceptr), vy*interval*i - g/2.*pow(i*interval,2.));
        }
    }

    *distanceptr += vx*time;
    return;
}

int main(int argc, char* argv[]) {
    double angle = 0, velocity = 0, distance = 0;
    int bounces = 0, notes = 0;

    if(argc == 2) notes = atoi(argv[1]);

    printf("Hello. You are here to throw a stone.\n");
    read_data(&angle, &velocity, &bounces);
    angle = angle*M_PI/180.;

    printf("Angle: %lf, Velocity: %lf, Bounces: %d, Notes: %d.\n", angle, velocity, bounces, notes);

    for(int i = 0; i<bounces; i++) {
        throw(&angle, &velocity, &distance, notes);
        velocity *= 2/sqrt(5);
        printf("Velocity: %lf m/s, Distance: %lf m.\n", velocity, distance);
    }

    return 0;
}