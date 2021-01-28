#include <stdio.h>
#include <stdlib.h>

int main()
{
  int diskQueue[20], n, i, seekTime = 0, diff;
  printf("Enter the size of Queue: ");
  scanf("%d", &n);
  printf("Enter the Queue: ");
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &diskQueue[i]);
  }
  printf("Enter the initial head position: ");
  scanf("%d", &diskQueue[0]);
  for (i = 0; i < n; i++)
  {
    diff = abs(diskQueue[i + 1] - diskQueue[i]);
    seekTime += diff;
    printf("\n%d -> %d - Time: %d", diskQueue[i], diskQueue[i + 1], diff);
  }
  printf("\n\nTotal Seek Time: %d", seekTime);
  printf("\nAverage Seek Time = %f\n", (float)seekTime / n);
  return 0;
}