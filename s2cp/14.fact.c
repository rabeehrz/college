#include<stdio.h>

long int fact(int n);

void main() {
	int n, r;
	printf("Enter the values of n and r: ");
	scanf("%d%d", &n, &r);
	printf("%ld\n", fact(n)/(fact(r)*fact(n-r)));
}

long int fact(int n) {
	if (n < 2)
		return 1;
	else
		return n*fact(n-1);
}
