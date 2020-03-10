#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verbose = 1;

double* read_stats() {
    /* Reads in the angle, height and velocity of the throw in an double arr[3]*/
    static double stats[3] = {0, 0, 0};

    printf("Hello. You are here to throw a stone.\n");
    printf("At which angle do you want to throw it? (deg)\n");
    scanf("%lf", &stats[0]);
    printf("How far above the ground are you? (meters)\n");
    scanf("%lf", &stats[1]);
    printf("And how fast do you throw it? (meters/second)\n");
    scanf("%lf", &stats[2]);

    return stats;
}

double quadratic(double a, double b, double c) {
    b = b/a;
    c = c/a;
    double wurzel = pow(b,2)/4 - c;
    if(wurzel < 0) {
        printf("There's no solution to this quadratic.");
        return 0;
    }
    double solution = -b/2 + sqrt(wurzel);
    double other_sol = -b/2 - sqrt(wurzel);
    if(other_sol > solution) {
        solution = other_sol;
    }
    return solution;
}

double throw(double* ptr, int ptr_len) {
    double distance = 0;
    double angle = *ptr, height = *(ptr+1), velocity = *(ptr+2);
    double vx = velocity*cos(angle);
    double vy = velocity*sin(angle);
    double g = 9.86;

    double time = quadratic(-g/2, vy, height);

    float step_len = 0.1;
    for(int i=1; i*step_len<time; i++) {
        double step = i*step_len;
        printf("%d. (x, y): (%lf, %lf)\n", i, vx*step, height + vy*step + g/2*pow(step,2));
    }
    return vx*time;
}

int main(int argc, char* argv[]) {
    double stats[3]; /* angle, height, velocity */
    int stats_len = 3;
    if(argc == 4) {
        verbose = 0;
        for(int i=1; i<argc; i++){
            stats[i-1] = atof(argv[i]);
        }
    }
    else {
        double* temp = read_stats();
        for(int i=0; i<stats_len; i++){
            stats[i] = *(temp+i);
        }
    }

    stats[0] = stats[0] * M_PI / 180;

    double distance = throw(stats, stats_len);
    printf("You threw it as far as %lf meters!", distance);

    return 0;
}