#include <stdio.h>
#include <math.h>

int main() {
	double a;
	double b;
	
	printf("Dieses Programm gibt die Lösung fuer die Aufgabe ax + b = 0 aus. \n");
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	
	double x = -b / a;
	
	printf("Die Loesung ist x = %lf\n", x);
	
	return 0;
}