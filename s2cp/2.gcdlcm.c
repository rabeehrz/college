#include <stdio.h>
void main() {
	while(1) {
		int x,y,a,b;
		printf("Enter two numbers: ");
		scanf("%d%d", &x, &y);
		a = x;
		b = y;
		while(y>0) {
			int temp;
			temp = x;
			x = y;
			y = temp%x;
		}

		printf("HCF is %d\n", x);
		printf("LCM is %d\n", a*b/x);
	}
}
