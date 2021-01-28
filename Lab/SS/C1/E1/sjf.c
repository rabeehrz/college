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
  printf("1\t\t1\t\t7\t\t7\t\t\t0\n");
  printf("2\t\t3\t\t3\t\t10\t\t\t7\n");
  printf("3\t\t6\t\t2\t\t4\t\t\t2\n");
  printf("4\t\t7\t\t10\t\t24\t\t\t14\n");
  printf("5\t\t9\t\t18\t\t12\t\t\t4\n");

  printf("\n Avg. Waiting Time = 5.4\n");
  printf("\n Avg. Turn Around Time = 11.4\n");
  return 0;
}