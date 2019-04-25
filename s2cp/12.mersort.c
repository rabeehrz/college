#include<stdio.h>

void main() {
        int n, m, i, j, k, a[100], b[100], c[100];
        printf("Enter the number of elements in Set 1: ");
        scanf("%d", &n);
        for(i=0; i<n; i++) {
                printf("Enter Number %d: ", i+1);
                scanf("%d", &a[i]);
        }
        printf("Enter the number of elements in Set 2: ");
        scanf("%d", &m);
        for(j=0; j<m; j++) {
                printf("Enter Number %d: ", j+1);
                scanf("%d", &b[j]);
        }
	i = 0;
	j = 0;
	k = 0;
	while(1) {
		if(a[i] < b[j]) {
			c[k] = a[i];
			i++;
		} else {
			c[k] = b[j];
			j++;
		}
		k++;
		if(i==n) {
			while(j < m) {
				c[k] = b[j];
				j++;
				k++;
			}
			break;
		} else if(j==m) {
			while(i < n) {
                                c[k] = a[i];
                                i++;
                                k++;
			}
			break;
		} else {
			continue;
		}
	}
	for(i=0; i < m+n; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");

}
