#include <stdio.h>
#include <math.h>

int main() {
    char names[] = {'a', 'b', 'c'};
    float arr[] = {0, 0, 0};
    int arr_size = 3;

    printf("This program solves the quadratic equation ax^2 + bx + c = 0.\n");

    for(int i=0; i<arr_size; i++) {
        printf("%c?\n", names[i]);
        scanf("%f", &arr[i]);
    }

    arr[1] = -arr[1]/(2*arr[0]);
    arr[2] /= arr[0];

    float wurzel = pow(arr[1], 2) - arr[2];
    if(wurzel < 0) {
        printf("This quadratic equation doesn't have a real solution.\n");
    }
    else if (wurzel == 0) {
        printf("It has one solution with x = %f.\n", arr[1]);
    }
    else {
        printf("The quadratic has two solutions with x = %f\n", arr[1]+sqrt(wurzel));
        printf("and x = %f", arr[1]-sqrt(wurzel));
    }

    return 0;
}