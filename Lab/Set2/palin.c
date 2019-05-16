// Test Case #7 Timeout. Rest pass!

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPalin(long long int n) {
    unsigned long long int a, sum = 0;
    a = n;
    while(a > 0) {
        sum = sum*10 + (a%10);
        a/=10;
    }
    if(n == sum) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long int n, n1, n2;
    scanf("%lld", &n);
    if(isPalin(n)) {
        printf("no pal");
    } else {
        n1 = n + 1;
        n2 = n - 1;
        while(!isPalin(n1) && !isPalin(n2)) {
            n1++;
            n2--;
        }
        if(isPalin(n1) && isPalin(n2)) {
            printf("%lld", n2);
        } else {
            printf("%lld", (isPalin(n1)) ? n1:n2);
        }
    }
    return 0;
}

