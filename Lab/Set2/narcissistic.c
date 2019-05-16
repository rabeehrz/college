// ALL TEST CASE PASSED!

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long int power(long int x, long int n) {
    if(n == 0) {
        return 1;
    } else {
        return x * power(x, n-1);
    }
}

int isArm(long int n) {
    long int sum = 0, a, p = 0;
    a = n;
    while(a > 0) {
        p++;
        a/=10;
    }
    a = n;
    while(a > 0) {
        sum += power(a%10, p);
        a/=10;
    }
    if(n == sum) {
        return 1;
    } else {
        return 0;
    }
}

int af(long int n) {
    int i, a = 0;
    for(i = 1; i <= n; i++) {
        if(isArm(i)) {
            a++;
        }
    }
    return a;
}

int bf(long int n) {
    int i, b = 0;
    for(i = n; i <= n*n; i++) {
        if(isArm(i)) {
            b++;
        }
    }
    return b;
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int n;
    scanf("%ld", &n);
    printf("%d", af(n)-bf(n));
}

