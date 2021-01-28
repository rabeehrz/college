#include<stdio.h>
#include<stdlib.h>

void getAllocation(int partitionSize[], int partitionNo, int processSize[], int processNo) {

    int internalFragmentation = 0;
    int externalFragmentation = 0;
    int remainingMemory = 0;
    int memoryAllocated, partitionAllocated[100];
    int externalFragmentationProcess[100];

    for(int i = 0; i < partitionNo; i++) {
        partitionAllocated[i] = 0; // Initially none of the partitions are allocated
        remainingMemory += partitionSize[i];
    }

    for(int i = 0; i < processNo; i++) {
        externalFragmentationProcess[i] = 0; // Initially assumes that external fragmentation will not occur
        memoryAllocated = 0;
        for(int j = 0; j < partitionNo; j++) {

            if(partitionAllocated[j]) {
                continue;
            }

            if(processSize[i] <= partitionSize[j]) {
                memoryAllocated = 1;
                partitionAllocated[j] = 1;
                remainingMemory -= partitionSize[j];

                int fragmentation = partitionSize[j] - processSize[i];
                internalFragmentation += fragmentation;

                printf("P%d(%d) -> %d - Internal Fragmentation(%dK)\n", i+1, processSize[i], partitionSize[j], fragmentation);
                break;
            }
        }
        // Condition for external fragemntatio
        if(!memoryAllocated && remainingMemory >= processSize[i]) {
            externalFragmentationProcess[i] = 1;
            externalFragmentation += processSize[i];
        }
    }

    printf("Total internal fragmentation : %d\n", internalFragmentation);
    if(externalFragmentation) {
        printf("Following process caused external fragmentation : \n");
        for(int i = 0; i < processNo; i++) {
            if(externalFragmentationProcess[i]) {
                printf("P%d\t", i+1);
            }
        }
        printf("\nTotal external fragmentation : %d\n", externalFragmentation);
    }
}

void printFirstFitAllocation(int partitionSize[], int partitionNo, int processSize[], int processNo) {

    printf("_First Fit Policy__\n");
    printf("Resultant Allocation : \n");

    getAllocation(partitionSize, partitionNo, processSize, processNo);
}

int comparator1(const void *p, const void *q) 
{ 
    // Get the values at given addresses 
    int l = *(const int *)p; 
    int r = *(const int *)q; 

    return l-r;
} 

void printBestFitAllocation(int partitionSize[], int partitionNo, int processSize[], int processNo) {

    // Sort the partitions array in ascending order
    qsort((void *)partitionSize, partitionNo, sizeof(partitionSize[0]), comparator1);

    printf("_Best Fit Policy__\n");
    printf("Resultant Allocation : \n");

    getAllocation(partitionSize, partitionNo, processSize, processNo);
}

int comparator2(const void *p, const void *q) 
{ 
    // Get the values at given addresses 
    int l = *(const int *)p; 
    int r = *(const int *)q; 

    return r-l;
} 

void printWorstFitAllocation(int partitionSize[], int partitionNo, int processSize[], int processNo) {

    // Sort the partitions array in descending order
    qsort((void *)partitionSize, partitionNo, sizeof(partitionSize[0]), comparator2);
    
    printf("_Worst Fit Policy__\n");
    printf("Resultant Allocation : \n");

    getAllocation(partitionSize, partitionNo, processSize, processNo);
    
}

void main() {
    int partitionNo, processNo;
    int partitionSize[100], processSize[100];

    printf("Enter the number of fixed memory partitions : ");
    scanf("%d", &partitionNo);

    for(int i = 0; i < partitionNo; i++) {
        printf("Enter the memory available for partition %d : ", i+1);
        scanf("%d", &partitionSize[i]);
    }

    printf("Enter the number of proccess : ");
    scanf("%d", &processNo);

    for(int i = 0; i < processNo; i++) {
        printf("Enter the memory requirement of process %d : ", i+1);
        scanf("%d", &processSize[i]);
    }

    printFirstFitAllocation(partitionSize, partitionNo, processSize, processNo);
    printBestFitAllocation(partitionSize, partitionNo, processSize, processNo);
    printWorstFitAllocation(partitionSize, partitionNo, processSize, processNo);

}