#include <stdio.h>


void bubblesort(int a[], int s);
void main() {
    int n,i,k, first, last, middle;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++) {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &a[i]);
    }
    bubblesort(a, sizeof(a));
    printf("Enter number to k: ");
    scanf("%d", &k);
    first = 0;
    last = n - 1;
    middle = (first+last)/2;
    
    while (first <= last) {
        if (a[middle] < k)
            first = middle + 1;    
        else if (a[middle] == k) {
            printf("%d found at index %d.\n", k, middle);
            break;
        }
        else
            last = middle - 1;
    
        middle = (first + last)/2;
    }
    if (first > last)
        printf("%d is not present in the list\n", k);    
    
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
}