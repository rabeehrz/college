#include<stdio.h>
#define MAX_SIZE 100

void bubblesort(int arr[], int n) {
	int i, j, temp, k, swap;
	for(i = 0; i < n-1; i++) {
		swap = 0;
		for(j = 0; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap = 1;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if(!swap) {
			break;
		}
		for(k = 0; k < n; k++) {
                        printf("%d ", arr[k]);
                }
		printf("\n");
	}
}

void selectionsort(int arr[], int n) {
        int i, j, k, temp, swap;
        for(i = 0; i < n-1; i++) {
		swap = 0;
                for(j = i+1; j < n; j++) {
                        if(arr[j] < arr[i]) {
				swap = 1;
                                temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
		if(!swap) {
			break;
		}
		for(k = 0; k < n; k++) {
                        printf("%d ", arr[k]);
                }
                printf("\n");

        }
}

void main() {
	int option, arr[MAX_SIZE], n, i;
	printf("\nSorting...\n\n1.Bubble Sort\n2. Selection Sort\n\nChoose an option: ");
	scanf("%d", &option);
	if(option != 1 && option != 2) {
		printf("ERROR: Invalid option");
	} else {
		printf("Enter the number of elements: ");
		scanf("%d", &n);
		printf("Enter the elements: ");
		for(i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		if(option == 1) {
			bubblesort(arr, n);
		} else {
			selectionsort(arr, n);
		}
		printf("\nThe sorted list: ");
		for(i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}

		printf("\n");
	}
}

