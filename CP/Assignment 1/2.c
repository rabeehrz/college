#include<stdio.h>
#define MAX 100

struct student{
        char name[24];
        int rollno;
        int marks[4];
        int totalmarks;
};

void bubblesort(struct student s[], int n) {
    int i, j, k;
    struct student temp; 
    for (i = 0; i < n-1; i++) {     
        for (j = 0; j < n-i-1; j++) {
            if (s[j].totalmarks < s[j+1].totalmarks) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;                
            }
        }
    }
}

void main() {
    struct student s[MAX];
    int n, i, j, rank = 1;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter roll no. and name of student %d: ", i+1);
        scanf("%d%s", &s[i].rollno, s[i].name);
        printf("Enter marks of 4 subjects: ");
        for(j = 0; j < 4; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].totalmarks += s[i].marks[j];
        }
    }
    printf("\n");
    bubblesort(s, n);
    printf("Rank\tRoll No\tName\tTotal Marks\n");
    printf("%d\t%d\t%s\t%d\n", rank, s[0].rollno ,s[0].name, s[0].totalmarks);
    for(i = 1; i < n; i++) {
        if((s[i].marks[0] >= 40) && (s[i].marks[1] >= 40) && (s[i].marks[2] >= 40) && (s[i].marks[3] >= 40)) {
            if(s[i].totalmarks == s[i-1].totalmarks) {
                printf("%d\t%d\t%s\t%d\n", rank, s[i].rollno, s[i].name, s[i].totalmarks);
            } else {
                printf("%d\t%d\t%s\t%d\n", ++rank, s[i].rollno, s[i].name, s[i].totalmarks);
            }
        }
    }
}