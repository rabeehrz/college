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
int saddle(int a[][100], int n) {
    int i, j, k;
    for(i = 0; i < n; i++) {
        int min = a[i][0], minc = 0;
        for(j = 1; j < n; j++) {
            if(min > a[i][j]) {
                min = a[i][j];
                minc = j;
            }
        }

        for(k = 0; k <n; k++) {
            if(min < a[k][minc])
                break;
        }
        if(k == n) {
            return min;
        }
    }
    return -1;
}
void main() {
    int n, i, j, k, sad, a[100][100], temp;
    printf("Enter size of Matrix: ");
    scanf("%d", &n);
    readMatrix(a, n);
    sad = saddle(a, n);
    if(sad == -1) {
        printf("No Saddle Point.\n");
    } else {
        printf("Saddle point is: %d\n", sad);
    }
    printf("Upper diagonal elements: \n");
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\nLower diagonal elements: \n");
    for(i = n-1; i > 0; i--) {
        for(j = i-1; j > -1; j--) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\nInterchanging Row 1 and Row 2: \n");
    for(i = 0; i < n; i++) {
        temp = a[0][i];
        a[0][i] = a[1][i];
        a[1][i] = temp;
    }
    printMatrix(a, n);
    printf("Interchanging Column 1 and Column 2: \n");
    for(i = 0; i < n; i++) {
        temp = a[i][0];
        a[i][0] = a[i][1];
        a[i][1] = temp;
    }
    printMatrix(a, n);
}