#include <stdio.h>
#include <stdlib.h>

int main() {
    int nb, np;
    
    //Get blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    
    int memoryblocks[nb];
    
    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &memoryblocks[i]);
    }
    
    //Get processes
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    
    int process[np];
    
    printf("Enter the process sizes:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &process[i]);
    }
    
    //Initialize allocation table
    int alloc[np][2];
    for (int i = 0; i < np; i++) {
        alloc[i][0] = i + 1;
        alloc[i][1] = -1;
    }
    
    //Allocate blocks
    for (int k = 0; k < np; k++) {
        for (int l = 0; l < nb; l++) {
            if (process[k] <= memoryblocks[l]) {
                alloc[k][1] = l;
                memoryblocks[l] -= process[k];
                break;
            }
        }
    }
    
    //Print allocation
    printf("Process Allocation:\n");
    for (int i = 0; i < np; i++) {
        printf("Process %d ", alloc[i][0]);
        if (alloc[i][1] != -1) {
            printf("allocated to memory block %d\n", alloc[i][1] + 1);
        } else {
            printf("not allocated\n");
        }
    }
    
    ////(Optional)Print remaining space in each block
    //printf("\nAvailable Spaces:\n");
    //for (int i = 0; i < nb; i++) {
    //    printf("Memory Block %d: %d\n", i + 1, memoryblocks[i]);
    //}
    
    return 0;
}
