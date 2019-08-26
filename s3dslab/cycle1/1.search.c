#include<stdio.h>
#define MAX_SIZE 1000

void sort(int arr[], int n) {
	int i, j, temp;
	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int lsearch(int search, int arr[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		if(arr[i] == search) {
			return i;
		}
	}
	return -1;
}

int bsearchi(int search, int arr[], int left, int right) {
	int middle;
	while(left<=right) {
		middle = (left + right)/2;
		if(arr[middle] == search) {
			return middle;
		} else if(arr[middle] <= search) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}
	return -1;
}

int bsearchr(int search, int arr[], int left, int right) {
        int middle;
        middle = (left + right)/2;
	if(left > right) {
		return -1;
	}
        if(arr[middle] == search) {
                return middle;
        } else if(arr[middle] <= search) {
		return bsearchr(search, arr, middle + 1, right);
        } else {
		return bsearchi(search, arr, left, middle - 1);
        }
}

void readElems(int arr[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
}


void main() {
	int arr[MAX_SIZE], n, search, option, result;
	printf("\n1. Linear search\n2. Binary Search(Iterative)\n3. Binary Search(Recursive)\nChoose an option: ");
	scanf("%d", &option);
	switch(option) {
		case 1:
			printf("Enter number of elements: ");
			scanf("%d", &n);
			printf("Enter the numbers: ");
			readElems(arr, n);
			printf("Enter the number to be searched: ");
			scanf("%d", &search);
			result = lsearch(search, arr, n);
			if(result == -1) {
				printf("The number %d was not found.\n", search);
			} else {
				printf("The number %d was found at index %d.\n", search, result + 1);
			}
			break;
		case 2:
                        printf("Enter number of elements: ");
                        scanf("%d", &n);
                        printf("Enter the numbers: ");
                        readElems(arr, n);
                        printf("Enter the number to be searched: ");
                        scanf("%d", &search);
			sort(arr, n);
                        result = bsearchi(search, arr, 0, n-1);
                        if(result == -1) {
                                printf("The number %d was not found.\n", search);
                        } else {
                                printf("The number %d was found at index %d.\n", search, result + 1);
                        }
                        break;
		case 3:
                        printf("Enter number of elements: ");
                        scanf("%d", &n);
                        printf("Enter the numbers: ");
                        readElems(arr, n);
                        printf("Enter the number to be searched: ");
                        scanf("%d", &search);
			sort(arr,n);
                        result = bsearchr(search, arr, 0, n-1);
                        if(result == -1) {
                                printf("The number %d was not found.\n", search);
                        } else {
                                printf("The number %d was found at index %d.\n", search, result + 1);
                        }
                        break;
		default:
			printf("Invalid Option!\n");
			break;
	}
}
