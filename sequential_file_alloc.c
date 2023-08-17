#include <stdio.h>

struct sector {
    int used, next;
} s[100];
int nFree, sNo;

void sequential() {
    int nFiles, curBlock = 0;
    printf("Enter number of files: ");
    scanf("%d", &nFiles);

    while (nFiles-- && nFree) {
        printf("\nFile %d:\nStarting position: %d", nFiles, curBlock);
        
        int nBlocks;
        printf("\nEnter number of Blocks in file: ");
        scanf("%d", &nBlocks);

        if (nBlocks <= nFree) {
            for (int j = curBlock; j < curBlock + nBlocks; j++)
                s[j].used = 1, printf(j == curBlock ? "%d" : "---> %d", j);
            printf("\nFile was successfully allocated.\n"), curBlock += nBlocks, nFree -= nBlocks;
        } else {
            printf("\nFile allocation failed due to insufficient free sectors.\n");
            break;
        }
    }
}

int main() {
    printf("Enter number of sectors in Disk: ");
    scanf("%d", &sNo);

    for (int i = 0; i < sNo; i++) s[i].used = 0, s[i].next = (i + 1) % sNo;
    nFree = sNo, sequential();
    return 0;
}

