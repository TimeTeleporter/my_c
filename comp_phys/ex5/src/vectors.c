#include <stdio.h>
#include <math.h>

void read_vec(double* vec, int vec_size) {
    for(int i = 0; i<vec_size; i++) scanf("%lf", vec+i);
    return;
}

int main() {
    unsigned short vec_size = 3;
    double vec1[3] = {0., 0., 0.};
    double vec2[3] = {0., 0., 0.};

    /* Input */
    printf("Please enter the %hu vector components of the first vector.\n", vec_size);
    read_vec(vec1, vec_size);
    printf("Please enter the %hu vector components of the second vector.\n", vec_size);
    read_vec(vec2, vec_size);

    /* Logic */
    double scalar = 0;
    for(int i = 0; i<vec_size; i++) scalar += vec1[i]*vec2[i];

    double vector[3] = {0., 0., 0.};
    for(int i = 0; i<vec_size; i++) vector[i] = vec1[(i+1)%3]*vec2[(i+2)%3] - vec2[(i+1)%3]*vec1[(i+2)%3];

    /* Return */
    printf("The scalar product is %lf\n", scalar);
    printf("The vector product is (%3.1lf, %3.1lf, %3.1lf)\n", vector[0], vector[1], vector[2]);

    return 0;
}