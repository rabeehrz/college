#include<stdio.h>
#include<math.h>
#define MAX 100

void readMatrix(int a[][MAX], int m, int n) 
{
    int i, j;
    for (i = 0; i < m; i++) 
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
int isPerfectSquare(int x) 
{ 
    int s = sqrt(x); 
    return (s*s == x); 
} 
  
int isFibonacci(int n) 
{ 
    return (isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4)); 
} 

void main() {
    int a[MAX][MAX], m, n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);
    readMatrix(a, m, n);
    printf("The Fibonacci numbers are: \n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(isFibonacci(a[i][j]))
                printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}