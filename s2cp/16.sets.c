#include<stdio.h>

void bubblesort(int a[], int n) {
	int i, j, temp;
	for(i=0; i<n-1; i++) {
                for(j=0; j<n-i-1; j++) {
                        if(a[j]>a[j+1]) {
                                temp = a[j+1];
                                a[j+1] = a[j];
                                a[j] = temp;
                        }
                }
        }

}

void main() {
	int o, m, n, i, j;
	printf("\nSet Operations: \n1.Union\n2.Intersection\n3.Set Difference\nChoose an option: ");
	scanf("%d", &o);
	printf("Enter number of elements in Set 1: ");
	scanf("%d", &m);
	int a[m];
	printf("Enter elements: ");
	for(i=0; i<m; i++)
		scanf("%d", &a[i]);
	bubblesort(a,m);
	printf("Enter number of elements in Set 2: ");
        scanf("%d", &n);
        int b[n];
        printf("Enter elements: ");
        for(i=0; i<n; i++)
                scanf("%d", &b[i]);
	bubblesort(b,n);
	i = 0;
	j = 0;
	switch(o) {
		case 1:
			printf("Union: ");
			while(1) {
				if(a[i] < b[j]) {
		                        printf("%d ", a[i++]);
		                } else if(a[i] > b[j]) {
                		        printf("%d ", b[j++]);
                 		} else {
					j++;
				}
		                if(i==m) {
                		        while(j < n)
						printf("%d ", b[j++]);
                        		break;
                		} else if(j==n) {
                        		while(i < m)
                                		printf("%d ", a[i++]);
                        		break;
                		} else {
                        		continue;
               			}

			}
			printf("\n");
			break;
		case 2:
			printf("Intersection: ");
                        while(1) {
                                if(a[i] < b[j]) {
                                        i++;
                                } else if(a[i] > b[j]) {
					j++;
                                } else {
                                        printf("%d ", a[i++]);
                                        j++;
                                }
                                if(i==m) {
                                        break;
                                } else if(j==n) {
                                        break;
                                } else {
                                        continue;
                                }

                        }
                        printf("\n");
			break;
		case 3:
			printf("Set Difference: ");
			while(1) {
                                if(a[i] < b[j]) {
                                        printf("%d ", a[i++]);
                                } else if(a[i] > b[j]) {
					j++;
                                } else {
					i++;
                                        j++;
                                }
                                if(j==n) {
                               		 while(i < m)
                                                printf("%d ", a[i++]);
                                         break;
                                } else {
                                        continue;
                                }

                        }
                        printf("\n");
			break;


	}
}
