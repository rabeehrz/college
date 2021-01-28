#include<stdio.h>

#define resources 3

int getNextProcess(int required[][resources], int available[], int completed[], int n) {
    int process = -1;
    for(int i = 0; i < n; i++) {
        if(!completed[i]) {
            int allowable = 1;
            for(int j = 0; j < resources; j++) {
                if(required[i][j] > available[j]) {
                    allowable = 0;
                    break;
                }
            }
            if(allowable) {
                process = i;
                return process;
            }
        }
    }
    return process;
}

int main() {
    int n; //Number of Processes
    int allocation[10][resources], max[10][resources], required[10][resources];
    int totalResource[] = {10, 5, 7};
    int available[resources];
    int completed[10];
    int safeSequence[10];

    for(int i = 0; i < resources; i++) {
        available[i] = totalResource[i];
    }

    printf ("Enter the number of process : "); 
    scanf("%d", &n);

    printf ("Enter the maximum required resources matrix :\n"); 
    for(int i=0; i<n; i++){
        for(int j = 0; j < resources; j++) { 
            scanf("%d", &max[i][j]);
        }
        completed[i] = 0;
    }

    printf("Enter the current allocation matrix: ");
    for(int i = 0; i < n; i++) {
        for(int j =0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
            available[j] -= allocation[i][j];
            required[i][j] = max[i][j] - allocation[i][j];
        }
    }

   int completedProcess = 0;
   while(completedProcess < n) {
       int nextProcess = getNextProcess(required, available, completed, n);
       if(nextProcess == -1) {
           break;
       }
       safeSequence[completedProcess] = nextProcess;
       completedProcess++;
        for(int i = 0; i < resources; i++) {
            available[i] += allocation[nextProcess][i];
        }
   }

   if(completedProcess != n) {
       printf("System went into an unsafe state.\n");
   } else {
       printf("System is in a safe state\n");
       printf("Safe sequence is the following: \n");
       for(int i = 0; i < n-1; i++) {
           printf("P%d -> ", safeSequence[i]);
       }
       printf("P%d\n", safeSequence[n-1]);
   }
   return 0;
}