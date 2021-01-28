#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int waits(int s) {
  return (--s);
}

int signals(int s) {
  return (++s);
}

void producer() {
  mutex = waits(mutex);
  full = signals(full);
  empty = waits(empty);
  x++;
  printf("\nProducer produces the item %d", x);
  mutex = signals(mutex);
}

void consumer() {
  mutex = waits(mutex);
  full = waits(full);
  empty = signals(empty);
  printf("\nConsumer consumes item %d", x);
  x--;
  mutex = signals(mutex);
}

int main() {
  int n;
  printf("\n1.Producer\n2.Consumer\n3.Exit");

  while(1) {
    printf("\nEnter your choice: ");
    scanf("%d", & n);
    switch (n) {
    case 1:
      if ((mutex == 1) && (empty != 0)) producer();
      else
        printf("Buffer is full!!");
      break;
    case 2:
      if ((mutex == 1) && (full != 0))
        consumer();
      else
        printf("Buffer is empty!!");
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Invalid!");
      break;
    }
  }
  return 0;
}