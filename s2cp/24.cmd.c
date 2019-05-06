#include<stdio.h>
#include<stdlib.h>

void main(int argc, char * argv[]) {
    float average;
    int i, sum = 0;
    if(argc > 1) {
        for(i = 1; i < argc; i++) {
            sum += atoi(argv[i]);
        }
        average = (float) sum / (argc - 1);
        printf("Average is %.2f.", average);
    }
}