#include <stdio.h>


int fact(int n) {
    int i,result=1;
    for(i=2; i<=n; i++) {
        result *= i;
    }
    return result;
}

void main() {
    int o, n, i, j, k;
    printf("\nPattern Printer\n\n1.Floyd's Triangle\n2.Binary Pattern\n3.Reverse Pattern\n4.Pascal's triangle\n5.Star Pattern\n\nChoose an option: ");
    scanf("%d", &o);
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    switch (o)
    {
        case 1:
            i = 1;
            while(i <= n) {
                j = i;
                k = i;
                while(j>0) {
                    printf("%d ", k);
                    k++;
                    j--;
                }
                i++;
                printf("\n");
            }
            break;
        case 2:
            i = 1;
            while(i <= n) {
                j = i;
                k = (i%2) ? 0 : 1;
                while(j>0) {
                    printf("%d ", k);
                    k = (k==1) ? 0 : 1;
                    j--;
                }
                i++;
                printf("\n");
            }
            break;
        case 3:
            i = n;
            while(i > 0) {
                j = i;
                while(j > 0) {
                    printf("%d ", j);
                    j--;
                }
                i--;
                printf("\n");
            }
            break;
        case 4:
            i = 0;
            while(i <= n) {
                k = n-i;
                while(k>0) {
                    printf(" ");
                    k--;
                }
                for(j = 0; j <= i; j++) {
                    printf("%d ", fact(i)/(fact(j)*fact(i-j)));
                }
                i++;
                printf("\n");
            }
            break;
        case 5:
            i = n;
            while(i > 0) {
                j = i;
                k = 0;
                while(k < n-i) {
                    printf(" ");
                    k++;
                }
                while(j > 0) {
                    printf("* ");
                    j--;
                }
                i--;
                printf("\n");
            }
            break;
        default:
            printf("Invalid Option!\n");
            break;
    }
}

