#include<stdio.h>
#include<stdlib.h>
void main(int argc, char * argv[]) {
    FILE *fp;
    char * ch;
    char ch1;
    int i = 1, lines = 0, count;
    ch = argv[1];
    if(*ch == '-') {
        ch++;
        lines = atoi(ch);
    } else {
        lines = 10;
    }
    for(i = 1; i < argc; i++) {
        count = 0;
        if(*argv[1] == '-' && i==1)
            continue;
        printf("==> %s <==\n", argv[i]);
        fp = fopen(argv[i], "r");
        while((ch1=getc(fp)) != EOF && count < lines) {
            printf("%c", ch1);
            if(ch1 == '\n')
                count++;
        }
        printf("\n");
    }
}