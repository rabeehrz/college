#include<stdio.h>

void main() {

	int n, i, k, larg, seclarg;
	printf("Enter total no. of numbers: ");
	scanf("%d", &n);
	for(i=0; i < n; i++) {
		printf("Enter Number %d: ", i+1);
		scanf("%d", &k);
		if(i == 0) {
			larg = seclarg = k;
		} else {
			if(k>larg) {
				seclarg = larg;
				larg = k;
			} else if(k>seclarg) {
				seclarg = k;
			} else {
				continue;
			}
		}
	}
	printf("Second Largest: %d\n", seclarg);

}
