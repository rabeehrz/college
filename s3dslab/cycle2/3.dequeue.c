#include<stdio.h>
#define MAX_SIZE 100
int dq[MAX_SIZE], n, option, i, left = -1, right = -1, size, qsize;

void printvars() {
	printf("\nleft = %d, right = %d, size = %d, qsize = %d\n", left, right, size, qsize);
}

int isFull() {
	if(qsize >= size) {
		return 1;
	}
	return 0;
}

void insertRight(int element) {
	if(isFull()) {
		printf("Right overflow\n");
		return ;
	}
	if(right == -1) {
		left++;
	}
	dq[++right] = element;
	qsize++;
	printf("%d successfully inserted!\n", element);
}

void insertLeft(int element) {
	if(isFull()) {
		printf("Queue Full!");
		return ;
	}
	if(left == 0) {
            left = size - 1;
            dq[left] = element;
			return ;
        } else if(left == -1) {
			dq[++left] = element;
			right++;
	} else {
		dq[--left] = element;
	}
	qsize++;
	printf("%d successfully inserted!\n", element);
}

int isEmpty() {
	if(qsize <= 0)
		return 1;
	return 0;
}

void popRight() {
	if(isEmpty()) {
		printf("Nothing to Pop!\n");
		return ;
	}
	printf("%d popped!\n", dq[right]);
	right--;
	if(right < left) {
		right = -1;
		left = -1;
	}
	qsize--;
}

void popLeft() {
	if(isEmpty()) {
		printf("Nothing to Pop!\n");
		return ;
	}
	printf("%d popped!\n", dq[left]);
	left++;
	if(left > right) {
		right = -1;
		left = -1;
	}
	qsize--;
}

void display() {
	int k;
	if(isEmpty()) {
		printf("List empty!\n");
	} else {
		if(left <= right) {
			for(k = left; k <= right; k++) {
				printf("%d ", dq[k]);
			}
		} else {
			for(k = left; k < size; k++) {
				printf("%d ", dq[k]);
			}
			for(k = 0; k <= right; k++) {
				printf("%d ", dq[k]);
			}
		}
		printf("\n");
	}
}

void main() {
	printf("\n\n1.Input Restricted DEQUE\n2.Output Restricted DEQUE\n\nChoose an option: ");
	scanf("%d", &option);
	printf("Enter size: ");
	scanf("%d", &size);
	switch(option) {
		case 1:
			while(1) {
				printf("1.Insert\n2.Pop left\n3.Pop right\n4.Display\n\nChoose an option: ");
				scanf("%d", &option);
				switch(option) {
					case 1:
						printf("Enter element to insert: ");
						scanf("%d", &n);
						insertRight(n);
						break;
					case 2:
						popLeft();
						break;
					case 3:
						popRight();
						break;
					case 4:
						display();
						break;
					case 5:
						printvars();
						break;
					default:
						printf("Invalid option!\n");

				}
			}
			break;
		case 2:
			while(1) {
				printf("1.Insert Left\n2.Insert right\n3.Pop\n4.Display\n\nChoose an option: ");
				scanf("%d", &option);
				switch(option) {
					case 1:
						printf("Enter element to insert: ");
						scanf("%d", &n);
						insertLeft(n);
						break;
					case 2:
						printf("Enter element to insert: ");
						scanf("%d", &n);
						insertRight(n);
						break;
					case 3:
						popLeft();
						break;
					case 4:
						display();
						break;
					case 5:
						printvars();
						break;
					default:
						printf("Invalid option!\n");

				}
			}
			break;
		default:
			printf("Invalid option!\n");
	}

}
