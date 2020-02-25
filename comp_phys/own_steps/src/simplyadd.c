#include <stdio.h>
#include <math.h>

float main(){
	float a;
	float b;
	
	printf("Enter the first number: ");
	scanf("%f", &a);
	printf("Enter the second number: ");
	scanf("%f", &b);
	
	float c = a + b;
	
	printf("The result is: %f", c);
	
	return c;
}
