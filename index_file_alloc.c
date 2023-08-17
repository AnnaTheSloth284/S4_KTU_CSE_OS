#include <stdio.h>

struct sector {
    int used, next;
} s[100];
int nFree, sNo;

void indexed() {
    int nFiles, curBlock = 0, indexBlock[10][100], directory[10];
    printf("Enter number of files: ");
    scanf("%d", &nFiles);

    for (int i = 0; i < nFiles && nFree >= 2; i++) {
        printf("\n\nFile %d:", i);

        int indexPos;
        printf("\nEnter the location of index block: ");
        scanf("%d", &indexPos);

        if (s[indexPos].used) {
            printf("\nSpecified sector is already in use.\n");
            i--;
            continue;
        }

        s[indexPos].used = 1, directory[i] = indexPos, nFree--;

        int nBlocks;
        printf("Enter number of Blocks in file: ");
        scanf("%d", &nBlocks), indexBlock[i][0] = nBlocks;

        if (nBlocks <= nFree) {
            for (int j = 0; j < nBlocks; j++, curBlock = (curBlock + 1) % sNo) {
                while (s[curBlock].used) curBlock = (curBlock + 1) % sNo;
                s[curBlock].used = 1, indexBlock[i][j + 1] = curBlock;
            }
            nFree -= nBlocks, printf("\nThe file was successfully allocated.\n");
        } else {
            printf("\nThe file allocation failed due to insufficient free sectors.\n");
            break;
        }
    }

    printf("\n\nIndex Block:\n");
    for (int i = 0; i < nFiles; i++) {
        printf("\nFile %d: Index Block at Sector %d\n", i, directory[i]);
        for (int j = 0; j < indexBlock[i][0]; j++) printf("\t %d", indexBlock[i][j + 1]);
        printf("\n");
    }
}

int main() {
    printf("Enter number of sectors in Disk: ");
    scanf("%d", &sNo);

    for (int i = 0; i < sNo; i++) s[i].used = 0, s[i].next = (i + 1) % sNo;
    nFree = sNo, indexed();
    return 0;
}
