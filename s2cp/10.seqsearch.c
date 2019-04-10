#include <stdio.h>

void main() {
    int n,i,k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++) {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter number to search: ");
    scanf("%d", &k);
    for(i=0; i<n; i++) {
        if(a[i] == k) {
            printf("%d is present in the array at index %d\n", k, i);
            break;
        }
    }
    if(i==n) {
        printf("%d not found in array.\n", k);
    }
    
}
