#include <stdio.h>
#include <math.h>

int main() {
    float input = 0;

    printf("Enter a non-negative number: ");
    scanf("%f", &input);

    if(input < 0) {
        printf("Your number was negative (You shouldn't do that!).");
        return 1;
    }

    float wurzel = sqrt(input);

    printf("Die Wurzel ist %f.\n", wurzel);

    return 0;
}