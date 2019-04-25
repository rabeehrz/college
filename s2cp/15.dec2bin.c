#include <stdio.h>

int binary(int decimal);

void main() {
	int n;
	printf("Enter the decimal value: ");
	scanf("%d", &n);
	printf("%d\n", binary(n));
}

int binary(int decimal) {
	if(decimal==0) {
		return 0;
	} else {
		return decimal % 2 + 10 * binary(decimal/2);
	}
}
