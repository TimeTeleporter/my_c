#include <stdio.h>
#include <math.h>

int main() {
	double height, gravity = 9.81;
	
	printf("Wie viele Meter sind Sie ueber dem Boden? ");
	scanf("%lf", &height);
	
	double time = sqrt(2*height/gravity);
	
	printf("Ihre Fallzeit betraegt %lf Sekunden.\n",time);
	
	return 0;
}