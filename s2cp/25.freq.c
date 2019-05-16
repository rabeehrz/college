#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 256
void main() {
    FILE *fp;
    char ch;
    int frequency[MAX_SIZE] = {0}, i;
    fp = fopen("25.txt", "r");
    while((ch=getc(fp)) != EOF)
        frequency[ch]++;
    fclose(fp);
    for(i = 0; i < MAX_SIZE; i++) {
        if(frequency[i] > 0) {
            if(i != '\0')
                printf("%c: %d\n", i, frequency[i]);
        }
    }
}