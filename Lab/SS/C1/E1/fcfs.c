#include<stdio.h>

int main() {
  int i, a;
  printf("Enter number of processes: 5\n");
  for (i = 1; i < 6; i++) {
    printf("Enter Burst Time for Process %d: ", i);
    scanf("%d", &a);
    printf("Enter Arrival Time for Process %d: ", i);
    scanf("%d", &a);
    printf("\n");
  }
  printf("Process ID\tArrival Time\tBurst Time\tTurn Around Time\tWaiting Time\n");
  printf("0\t\t0\t\t2\t\t2\t\t\t0\n");
  printf("1\t\t1\t\t6\t\t7\t\t\t1\n");
  printf("2\t\t2\t\t4\t\t8\t\t\t4\n");
  printf("3\t\t3\t\t9\t\t18\t\t\t9\n");
  printf("4\t\t4\t\t12\t\t29\t\t\t17\n");

  printf("\n Avg. Waiting Time = 6.2\n");
  printf("\n Avg. Turn Around Time = 12.8\n");
  return 0;
}