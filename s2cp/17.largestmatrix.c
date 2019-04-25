#include<stdio.h>

void main() {
	int m, n, i, j;
	printf("Enter number of rows and column: ");
	scanf("%d%d", &m, &n);
	int a[m][n];
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int largest = a[0][0];
	int row = 0;
	int column = 0;
	for(i = 0; i < m; i++) {
                for(j = 0; j < n; j++) {
			if(a[i][j] > largest) {
				largest = a[i][j];
				row = i;
				column = j;
			}
                }
        }
	printf("Largest: %d at (%d,%d)\n", largest, row+1, column+1);

}
