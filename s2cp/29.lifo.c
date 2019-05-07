#include<stdio.h>
#include<stdlib.h>

typedef struct tag {
	int data;
	struct tag * next;
} node;

void lifo() {
	node * head = NULL;
	node *temp;
	int i, n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		temp = (node *) malloc(sizeof(node));
		printf("Enter number %d: ", i+1);
		scanf("%d", &(temp->data));
		if(head == NULL) {
			temp->next = NULL;
			head = temp;
		} else {
			temp->next = head;
			head = temp;
		}
	}
	while(head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

void fifo() {
        node * rear = NULL;
	node * front = NULL;
        node *temp;
        int i, n;
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
                temp = (node *) malloc(sizeof(node));
                printf("Enter number %d: ", i+1);
                scanf("%d", &(temp->data));
                if(front == NULL) {
                        temp->next = NULL;
                        front = temp;
			rear = temp;
                } else {
                        rear->next = temp;
                        rear = temp;
                }
        }
	rear->next = NULL;
	temp = front;
        while(temp != NULL) {
		printf("%d\n", temp->data);
                temp = temp->next;
        }
}

void main() {
	int option;
	printf("\nLinked List\n1.LIFO\n2.FIFO\nEnter an option: ");
	scanf("%d", &option);
	switch(option) {
		case 1:
			lifo();
			break;
		case 2:
			fifo();
			break;
		default:
			printf("Wrong Option.");
	}
}
