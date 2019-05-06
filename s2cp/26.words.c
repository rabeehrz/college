#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 256
void main() {
    FILE *fp;
    char ch, pch;
    int words = 0, sentences = 0;
    fp = fopen("26.txt", "r");
    while((ch=getc(fp)) != EOF) {
        if(ch == '\n')
            sentences++;
        if((ch == ' ' || ch == '\t' || ch == '\n') && (pch != ' ' && pch != '\t' && pch != '\n'))
            words++;
        pch = ch;
    }
    fclose(fp);
    if(pch != '\n') {
        sentences++;
        if(pch != ' ' || pch != '\t')
            words++;
    }
    printf("Words: %d\nSentences: %d", words, sentences);
}