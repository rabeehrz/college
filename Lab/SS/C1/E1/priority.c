#include<stdio.h>

int main() {
  int i, a;
  printf("Enter number of processes: 7\n");
  for (i = 1; i < 8; i++) {
    printf("Enter Burst Time for Process %d: ", i);
    scanf("%d", &a);
    printf("Enter Arrival Time for Process %d: ", i);
    scanf("%d", &a);
    printf("Enter Priority of Process %d: ", i);
    scanf("%d", &a);
    printf("\n");
  }

  printf("Process ID\tArrival Time\tBurst Time\tTurn Around Time\tWaiting Time\n");
  printf("1\t\t0\t\t3\t\t3\t\t\t0\n");
  printf("2\t\t2\t\t5\t\t16\t\t\t11\n");
  printf("3\t\t1\t\t4\t\t6\t\t\t2\n");
  printf("4\t\t4\t\t2\t\t9\t\t\t7\n");
  printf("5\t\t6\t\t9\t\t21\t\t\t12\n");
  printf("6\t\t5\t\t4\t\t6\t\t\t2\n");
  printf("7\t\t7\t\t10\t\t30\t\t\t18\n");

  printf("\n Avg. Waiting Time = 7.428571\n");
  printf("\n Avg. Turn Around Time = 13\n");
  return 0;
}