#include<stdio.h>
#include<stdlib.h>
int main()
{
    int nd, nr;
    
    printf("Enter no of disks: ");
    scanf("%d",&nd);
    
    //Requests
    printf("Enter no of requests: ");
    scanf("%d",&nr);
    int requests[nr];
    
    printf("Enter the requests string: ");
    for(int i=0;i<nr;i++) scanf("%d",&requests[i]);
    
    //Where the head currently is
    int head;
    printf("Current position of head: ");
    scanf("%d",&head);
    
    //Current request being handled
    int cr;
    
    //Seek time
    int st, totst = 0;
    
    //FCFS
    for(int i=0;i<nr;i++)
    {
        cr = requests[i];
        st = abs(cr-head);
        printf("Head moves from cylinder %d to cylinder %d\nSeek Time = %d\n\n",head,cr,st);
        totst += st;
        head = cr;
    }
    printf("Total head movement = %d\n",totst);
}
