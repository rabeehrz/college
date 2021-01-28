#include <stdio.h>
#include <stdlib.h>

void scan(int Ar[20], int n, int start);
void bubble_sort(int Ar[20], int n);

int main()
{
  int diskQueue[20], n, start, i;
  printf("Enter the size of Queue: ");
  scanf("%d", &n);
  printf("Enter the Queue: ");
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &diskQueue[i]);
  }
  printf("Enter the initial head position: ");
  scanf("%d", &start);
  diskQueue[0] = start;
  ++n;
  bubble_sort(diskQueue, n);
  scan(diskQueue, n, start);

  return 0;
}

void scan(int Ar[20], int n, int start)
{
  int i, pos, diff, seekTime = 0, current;
  for (i = 0; i < n; i++)
  {
    if (Ar[i] == start)
    {
      pos = i;
      break;
    }
  }
  for (i = pos; i < n - 1; i++)
  {
    diff = abs(Ar[i + 1] - Ar[i]);
    seekTime += diff;
    printf("\n%d -> %d - Time: %d", Ar[i], Ar[i + 1], diff);
  }
  current = i;
  for (i = pos - 1; i >= 0; i--)
  {
    diff = abs(Ar[current] - Ar[i]);
    seekTime += diff;
    printf("\n%d -> %d - Time: %d", Ar[current], Ar[i], diff);
    current = i;
  }
  printf("\n\nTotal Seek Time: %d", seekTime);
  printf("\nAverage Seek Time = %f\n", (float)seekTime / (n - 1));
}

void bubble_sort(int Ar[20], int n)
{
  int i, j, tmp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (Ar[j] > Ar[j + 1])
      {
        tmp = Ar[j];
        Ar[j] = Ar[j + 1];
        Ar[j + 1] = tmp;
      }
    }
  }
}