#include<stdio.h>
#include<math.h>

void main() {
	float a, b, c, x, y, d;
	printf("Enter coeficcients: ");
	scanf("%f%f%f", &a, &b, &c);
	d = pow(b,2) - 4*a*c;
	if(d < 0) {
		x = -(b)/(2*a);
		y = (sqrt(-(d)))/(2*a);
		printf("Roots are %f + %fi and %f - %fi\n", x, y, x, y);
	} else {
		x = (-b + sqrt(d))/(2*a);
		y = (-b - sqrt(d))/(2*a);
		printf("Roots are %f and %f\n", x, y);
	}

}
