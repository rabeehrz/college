#include <stdio.h>
#include <string.h>
void main() {
    char name[100][24], temp[24];
    int i, j, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter name of %d students: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }
    for (i = 0; i < n - 1 ; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(name[i], name[j]) > 0) {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    } 
    printf("Sorted List: \n");
    for (i = 0; i < n; i++) {
        printf("%s\n", name[i]);
    }
}