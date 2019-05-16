// ALL TEST CASE PASSED 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void bubblesort(int a[][2], int n) {
     int i, j, temp[1][2];
     for(i = 0; i < n-1; i++) {
         for(j = 0; j < n-i-1; j++)  { 
            if(a[j][1] < a[j+1][1]) {
            temp[0][0] = a[j][0];
            temp[0][1] = a[j][1];
            a[j][0] = a[j+1][0];
            a[j][1] = a[j+1][1];
            a[j+1][0] = temp[0][0];
            a[j+1][1] = temp[0][1];
            }
         }
     }
}
int main() {

    int count[26][2], i, n, j;
    char string[10000000];
    for(i = 0; i < 26; i++) {
        count[i][0] = 0;
        count[i][1] = 0;
    }
    scanf("%d", &n);
    scanf("%s", string);
    for(i = 0; string[i] != '\0'; i++) {
        for(j = 0; j < 26; j++) {
            if(count[j][0] == string[i]) {
                count[j][1]++;
                break;
            } else if(count[j][0] == 0) {
                count[j][0] = string[i];
                count[j][1]++;
                break;
            }
        }
        
    }
    bubblesort(count, 26);
    for(i = 0; i < 26; i++) {
        if(count[i][0] == 0)
            break;
        printf("%c", count[i][0]);
    }
    return 0;
}

