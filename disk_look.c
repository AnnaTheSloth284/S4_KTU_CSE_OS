#include <stdio.h>
#include <stdlib.h>

int main() {
    int nd, nr;
    
    printf("Enter no of disks: ");
    scanf("%d", &nd);
    
    // Requests
    printf("Enter no of requests: ");
    scanf("%d", &nr);
    int requests[nr];
    
    printf("Enter the requests string: ");
    for (int i = 0; i < nr; i++)
        scanf("%d", &requests[i]);
    
    // Where the head currently is
    int head;
    printf("Current position of head: ");
    scanf("%d", &head);
    
    // Seek time
    int st, totst = 0;
    
    // CSCAN
    // Sort requests in ascending order
    for (int i = 0; i < nr - 1; i++) {
        for (int j = 0; j < nr - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    
    int cr;
    
    // Find index where current head is located
    int head_index = 0;
    while (head_index < nr && requests[head_index] < head) {
        head_index++;
    }
    
    // Handle requests in the direction of increasing cylinders
    for (int j = head_index; j < nr; j++) {
        cr = requests[j];
        st = abs(cr - head);
        printf("Head moves from cylinder %d to cylinder %d\nSeek Time = %d\n\n", head, cr, st);
        totst += st;
        head = cr;
    }

    // Handle remaining requests in the direction of decreasing cylinders
    for (int j = head_index - 1; j >=0 ; j--) {
        cr = requests[j];
        st = abs(cr - head);
        printf("Head moves from cylinder %d to cylinder %d\nSeek Time = %d\n\n", head, cr, st);
        totst += st;
        head = cr;
    }
    
    printf("Total head movement = %d\n", totst);
    
    return 0;
}
