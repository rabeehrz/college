#include <stdio.h>

void bubblesort(int a[], int s);

void main() {
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++) {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &a[i]);
    }
    
    bubblesort(a, sizeof(a));
    printf("\n");
}

void bubblesort(int a[], int s) {
    int i,j,temp;
    s = s / sizeof(a[0]);
    for(i=0; i < s-1; i++) {
        for(j=0; j < s-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(i=0; i < s; i++) 
        printf("%d ", a[i]);
}
