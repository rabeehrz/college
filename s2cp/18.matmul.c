#include<stdio.h>
void readMatrix(int a[][100], int n) {
    int i, j;
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++) 
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void printMatrix(int mat[][100], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void addMatrix(int a[][100], int b[][100], int add[][100], int n) {
    int i, j;
    for(i = 0; i <n; i++) {
        for(j = 0; j < n; j++) {
            add[i][j] = a[i][j] + b[i][j];
        }
    }
}
void multiplyMatrix(int a[][100], int b[][100], int mul[][100], int n) {
    int i, j, k;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            mul[i][j] = 0;
            for(k = 0; k < n; k++) {
                mul[i][j] += a[i][j]*b[j][k];
            }
        }
    }
}
void main() {
    int a[100][100], b[100][100], add[100][100], mul[100][100], n;
    printf("Enter size of Matrix: ");
    scanf("%d", &n);
    readMatrix(a, n);
    readMatrix(b, n);
    addMatrix(a, b, add, n);
    multiplyMatrix(a, b, mul, n);
    printf("\nSum of two Matrix: \n");
    printMatrix(add, n);
    printf("\nProduct of two Matrix: \n");
    printMatrix(mul, n);
}