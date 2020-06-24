#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

float fnc(float x);
void giveInput(float* distance);
float precision = 1E-7;
int max_trapezoids = 65536; /* 2**16 */
float trapint(float value, float prec);

int main() {
    float t = 0.;

    giveInput(&t);
    
    float result = trapint(t, precision);

    printf("The Integral was evaluated to be %.3f.", result);

    return 0;
}

float fnc(float x) {
    return expf(-x*x/2.)/sqrtf(2*M_PI);
}

void giveInput(float* distance) {
    printf("Enter the number with which you want to evaluate the Integral (float): ");
    scanf("%f", distance);
    return;
}

float trapint(float value, float prec) {
    float areasum = 2.;
    float old_areasum = 3.;
    int numTrap = 1;
    while(fabsf(areasum - old_areasum) > prec) {
        old_areasum = areasum;
        areasum = 0.;

        numTrap = numTrap*2;

        float delta = 2*value/((float) numTrap);

        float* fncarray = (float*) malloc((numTrap+1)*(sizeof(float)));
        for(int i = 0; i<numTrap+1; i++) {
            fncarray[i] = fnc(-value+i*delta);
        }

        for(int i = 0; i<numTrap; i++) {
            areasum += (fncarray[i]+fncarray[i+1])*delta/2;
        }

        free(fncarray);
    }
    
    return areasum;
}