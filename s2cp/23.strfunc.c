#include<stdio.h>

#define MAX_SIZE 100

int stringlen(char *s1) {
    int i = 0;
    while(*s1++)
        i++;
    return i;
}

char * stringcpy(char *s2, char *s1) {
    while((*s2 = *s1)) {
        s1++;
        s2++;
    }
    return s2;
}

int stringcmp(char *s1, char *s2) {
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1-*s2;
}

char * stringcat(char *s1, char *s2) {
    char *rtrn = s1;
    while(*s1)
        s1++;
    
    while((*s1++ = *s2++));
    *s1 = '\0';
    return rtrn;
}

void main() {
    int option;
    char string1[MAX_SIZE], string2[MAX_SIZE];
    printf("String Library Functions Implementation\n\n");
    printf("1. String length\n2. String copy\n3. String compare\n4. String concatenation\nChoose an option: ");
    scanf("%d", &option);
    printf("\n");
    switch(option) {
        case 1:
            printf("Enter the string: ");
            scanf("%s", string1);
            printf("String length is %d.\n", stringlen(string1));
            break;
        case 2:
            printf("Enter string 1: ");
            scanf("%s", string1);
            stringcpy(string2, string1);
            printf("String has been copied. New string is %s\n", string2);
            break;
        case 3:
            printf("Enter string 1: ");
            scanf("%s", string1);
            printf("Enter string 2: ");
            scanf("%s", string2);
            printf("String compare: %d\n", stringcmp(string1, string2));
            break;
        case 4:
            printf("Enter string 1: ");
            scanf("%s", string1);
            printf("Enter string 2: ");
            scanf("%s", string2);
            stringcat(string1, string2);
            printf("String concatenation: %s\n", string1);
            break;
        default:
            printf("Wrong option! Try again.");
            
    }
}