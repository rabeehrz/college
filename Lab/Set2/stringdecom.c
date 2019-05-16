// ALL TEST CASE PASSED

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, count;
    char message[1000];
    scanf("%s", message);
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= '0' && message[i] <= '9') {
            continue;
        } else if(!(message[i+1] >= '0' && message[i+1] <= '9')) {
            printf("%c", message[i]);
        } else {
            count = atoi(&message[i+1]);
            for(j = 0; j < count; j++)
                printf("%c", message[i]);
        }
    }
    return 0;
}
