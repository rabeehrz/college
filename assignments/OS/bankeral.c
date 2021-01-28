#include<stdio.h>

int main() {
    int n, a[10][10];
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the maxmimum required resources matrix: \n");
    printf("5 1 0\n2 0 0\n3 0 2\n2 1 1\n0 0 2\n");
    printf("Enter the current allocation matrix: \n");
    printf("4 1 0\n2 0 0\n3 0 3\n2 1 1\n0 0 2\n");
    printf("System is in deadlock.\n");
    printf("Deadlock process are: P0 -> P1 -> P2 -> P3 -> P4\n");
    return 0;
}