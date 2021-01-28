#include <stdio.h>

void readMatrix(int arr[50][50], int n, int m) {
  int i,j;
  for(i = 0; i < n; i++) {
    printf("P[%d]: ", i);
    for(j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}

int main() 
{ 

	int n, m, i, j, k, q, alloc[50][50], max[50][50], avail[50]; 
	n = 5;
	m = 3;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  printf("Enter number of resources: ");
  scanf("%d", &m);
	// int alloc[5][3] = { { 0, 1, 0 },
	// 					{ 2, 0, 0 }, // P1 
	// 					{ 3, 0, 2 }, // P2 
	// 					{ 2, 1, 1 }, // P3 
	// 					{ 0, 0, 2 } }; // P4 

	// int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix 
	// 				{ 3, 2, 2 }, // P1 
	// 				{ 9, 0, 2 }, // P2 
	// 				{ 2, 2, 2 }, // P3 
	// 				{ 4, 3, 3 } }; // P4 
  printf("\nEnter the allocation matrix:\n");
  readMatrix(alloc, n ,m);
  printf("\nEnter the max matrix:\n");
  readMatrix(max, n ,m);
  printf("\nEnter the available resources: ");
  for(q = 0; q < m; q++) {
    scanf("%d", &avail[q]);
  }

	// int avail[3] = { 3, 3, 2 }; // Available Resources 

	int f[n], ans[n], ind = 0, flag; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				flag = 0; 
				for (j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 
  if(flag) {
    printf("NOT IN SAFE STATE\n");
  } else {
    printf("Following is a Safe Sequence\n"); 
    for (i = 0; i < n - 1; i++) 
      printf(" P%d ->", ans[i]); 
    printf(" P%d\n", ans[n - 1]); 
  }

	return (0); 

	// This code is contributed by Deep Baldha (CandyZack) 
} 
