#include<stdio.h>
#define MAX 100

void bubblesort(int a[][MAX], int m, int n) {
    int i, j, k, temp; 
    for(k = 0; k < m; k++) {
        for (i = 0; i < n-1; i++) {     
            for (j = 0; j < n-i-1; j++) {
                if (a[k][j] > a[k][j+1]) {
                    temp = a[k][j];
                    a[k][j] = a[k][j+1];
                    a[k][j+1] = temp;
                }
            }
        }
    }
}
void printMatrix(int a[][MAX], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }
}
void readMatrix(int a[][MAX], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) 
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void main() {
    int a[MAX][MAX], m, n, i;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);
    readMatrix(a, m, n);
    bubblesort(a, m, n);
    printf("Sorted Matrix: \n");
    printMatrix(a, m, n);
}