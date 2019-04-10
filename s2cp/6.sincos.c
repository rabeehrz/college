#include <stdio.h>
#include <math.h>

int fact(int);

void main() {
    float x, a, sinval, cosval;
    int c = 0;
    printf("Enter the angle: ");
    scanf("%f", &a);
    x = a*3.142/180;
    while (c < 17) {
        sinval += pow(-1, c)*(pow(x,2*c+1)/fact(2*c+1));
        cosval += pow(-1, c)*(pow(x,2*c)/fact(2*c));
        c++;
    }
    printf("Sin %f: %f\nCos %f: %f\n", a, sinval, a, cosval);
}

int fact(int n) {
    int i,result=1;
    for(i=2; i<=n; i++) {
        result *= i;
    }
    return result;
}