#include <stdio.h>

void main() {
    long int n, largest;
    printf("Enter the number: ");
    scanf("%ld", &n);
    largest = n%10;
    n/=10;
    while(n>0) {
        if(n%10 > largest)
            largest = n%10;
        n/=10;
    }  
    printf("Largest digit: %ld\n", largest);
}
