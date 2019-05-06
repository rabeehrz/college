#include<stdio.h>

void main(int argc, char * argv[]) {
    FILE *fp1, *fp2;
    char ch;
    if(argc < 3) {
        printf("USAGE: %s source destination\n", argv[0]);
    } else {
        fp1 = fopen(argv[1], "r");
        fp2 = fopen(argv[2], "w");
        while((ch=getc(fp1)) != EOF) {
            putc((ch >= 'a' && ch <= 'z') ? ch - 32 : ch, fp2);
        }
        fclose(fp1);
        fclose(fp2);
    }
}