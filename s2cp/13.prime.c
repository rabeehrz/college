#include<stdio.h>

int isPrime(int n);

void main() {
	int n, i;
	printf("Enter the counting number: ");
	scanf("%d", &n);
	for(i = 2; i <= n; i++) {
		if(isPrime(i))
			printf("%d ", i);
	}
	printf("\n");
}

int isPrime(int n) {
	int i, flag = 1;
	for(i = 2; i*i <= n; i++){
		if (n%i==0) {
			flag = 0;
			break;
		}
	}
	return flag;
}
