#include<stdio.h>
#define MAX_SIZE 4

int arr[MAX_SIZE], n, option, top = -1, i;
char ch;

void main() {
	printf("\nStack Program\n\n1.Push\n2.Pop\n3.Display");
	while(1) {
		printf("\n\nChoose an option:");
		scanf("%d", &option);
		switch(option) {
			case 1:
				if(top == MAX_SIZE-1) {
					printf("Stack Full.\n");
				} else {
					printf("Enter no. to push: ");
					scanf("%d", &n);
					arr[++top] = n;
					printf("%d inserted to stack.\n", n);
				}
				break;
			case 2:
				if(top == -1) {
					printf("Stack Empty.\n");
				} else {
					printf("%d removed from stack.\n", arr[top--]);
				}
				break;
			case 3:
				if(top == -1) {
					printf("Stack Empty.\n");
				} else {
					for(i = top; i >= 0; i--) {
						printf("%d\n", arr[i]);
					}
				}
				break;
			default:
				printf("Invalid Option.\n");
		}
	}
}