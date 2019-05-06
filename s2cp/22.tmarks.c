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
        printf("Student %d\n", i+1);
        printf("Roll no: ");
        scanf("%d", &s[i].rollno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Enter marks of 4 subjects: ");
        for(j = 0; j < 4; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].totalmarks += s[i].marks[j];
        }
    }
    printf("\n");
    bubblesort(s, n);
    printf("Roll No\tName\tTotal Marks\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", s[i].rollno, s[i].name, s[i].totalmarks);
    }
}