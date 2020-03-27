/*                                        */
/* This is a program by Immanuel Albrecht */
/*                                        */

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

/* Declarations */
int sign(float input);
float factorial(int n);
float mysqrt(float ofnumber, float precision);

int main() {
    float sign_input = 0;
    printf("Das Vorzeichen von (float): ");
    scanf("%f", &sign_input);
    int vorzeichen = sign(sign_input);
    printf("%d\n", vorzeichen);

    int fac_input = 0;
    printf("n? (int) ");
    scanf("%d", &fac_input);
    float fac = factorial(fac_input);
    printf("%f\n", fac);

    /*
    float sqrt_input = 0.;
    float sqrt_precision = 0.;
    printf("Die Wurzel einer positiven Zahl (unsigned float): ");
    scanf("%f", &sqrt_input);
    printf("Precision (e.g. 0.0000001): ");
    scanf("%f", &sqrt_precision);
    float sqrt_result = mysqrt(sqrt_input, sqrt_precision);
    printf("%f", sqrt_result);
    */

    return 0;
}

int sign(float input) {
    if(input > 0) return 1;
    if(input == 0) return 0;
    if(input < 0) return -1;
}

float factorial(int n) {
    float result = 1;
    for(int i = 1; i<=n; i++) {
        result = result*i;
    }
    return result;
}
/*
float mysqrt(float ofnumber, float precision) {
    float x = abs(ofnumber);
    sqrt()
}
*/