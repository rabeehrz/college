#include<stdio.h>
#include<math.h>

void main() {
	int a,decimal,multiplier;
	multiplier=1;
	printf("Enter binary number: ");
	scanf("%d", &a);
	while(a>0) {
		decimal += a%10*multiplier;
		multiplier*=2;
		a/=10;
	}
	printf("%d\n", decimal);
}
