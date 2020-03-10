#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double quadratic(double b, double c) {
    /* Enter the coefitions of the quadratic x^2 + bx + c. It returns the first solution*/
    return -b/2 + sqrt(pow(b,2)-c);
}

double throw(double angle, double height, double velocity) {
    double vy = sin(angle)*velocity;
    double vx = cos(angle)*velocity;
    double g = 9.86;

    double time = quadratic(-2*vy/g, -2*height/g);

    return time*vx;
}

int main(int argc, char* argv[]) {
    double angle = 0;
    double velocity = 0;
    double height = 0;

    printf("Hello. You are here to throw a stone.\n");
    printf("At which angle do you want to throw it? (deg)\n");
    scanf("%lf", &angle);
    printf("How far above the ground are you? (meters)\n");
    scanf("%lf", &height);

    angle = angle * M_PI / 180;

    printf("And how fast do you throw it? (meters/second)\n");
    scanf("%lf", &velocity);

    double distance = throw(angle, height, velocity);

    printf("You threw it as far as %lf meters!", distance);

    return 0;    
}