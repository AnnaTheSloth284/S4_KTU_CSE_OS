#include <stdio.h>

struct sector {
    int used;
    int next;
};

struct sector s[100];
int nFree, sNo;

void linked() {
    int nFiles;
    printf("Enter the number of files: ");
    scanf("%d", &nFiles);

    for (int i = 0; i < nFiles && nFree > 0; i++) {
        int start;
        printf("\nFile %d: Enter Starting position: ", i);
        scanf("%d", &start);

        if (s[start].used) {
            printf("Sector already used\n");
            i--;
            continue;
        }

        int current = start, nBlocks;
        printf("Enter the number of Blocks in file: ");
        scanf("%d", &nBlocks);

        if (nBlocks <= nFree) {
            for (int j = 0; j < nBlocks; j++, current = s[current].next) {
                s[current].used = 1;
                if (current != start) printf("---> ");
                printf("%d ", current);
            }
            nFree -= nBlocks;
            printf("\nFile was successfully allocated.\n");
        } else {
            printf("File cannot be allocated due to insufficient free sectors.\n");
        }
    }
}

int main() {
    printf("Enter the number of sectors in Disk: ");
    scanf("%d", &sNo);

    for (int i = 0; i < sNo; i++) {
        s[i].used = 0;
        s[i].next = (i + 1) % sNo;
    }

    nFree = sNo;
    linked();
    return 0;
}
