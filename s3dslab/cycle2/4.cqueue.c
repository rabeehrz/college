#include<stdio.h>
#include<stdlib.h>

int* cq;
int front = -1, rear = -1, size, option, n;

int isFull() {
	if((front == 0 && rear == size-1) || (rear == front - 1))
		return 1;
	return 0;
}
void push(int n) {
	if (isFull()) {
		printf("\nQueue Full.\n");
		return ;
	}
	if(front == -1 && rear == -1) {
		front = 0;
		rear = 0;
	} else {
		rear = (rear + 1) % size;
	}
	cq[rear] = n;
	printf("\n%d inserted successfully!\n", n);
}

int isEmpty() {
	return (front == -1 && rear == -1) ? 1 : 0;
}

void pop() {
	if(isEmpty()) {
		printf("\nQueue empty.\n");
		return ;
	}
	printf("\n%d popped!\n", cq[front]);
	if(front == rear) {
		front = -1;
		rear = -1;
	} else {
		front = (front + 1) % size;
	}
}

void display() {
	int i;
	if(isEmpty()) {
		printf("\nQueue empty.\n");
		return ;
	}
	printf("\n");
	if(front <= rear) {
		for(i = front; i <= rear; i ++) {
			printf("%d ", cq[i]);
		}
	} else {
		for(i = front; i < size; i++) {
			printf("%d ", cq[i]);
		}

		for(i = 0; i <= rear; i++) {
			printf("%d ", cq[i]);
		}
	}
	printf("\n");
}

void main() {
	printf("Enter size: ");
	scanf("%d", &size);
	cq = (int *) malloc(size * sizeof(int));
	printf("\n1.Push\n2.Pop\n3.Display\n");
	while(1) {
		printf("Choose an option: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("Enter an element: ");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				printf("Wrong option!\n");
		}
	}
}