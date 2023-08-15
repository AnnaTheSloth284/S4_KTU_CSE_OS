#include <stdio.h>
#include <math.h>

//Sort in increasing order of arrival time
void sort(int n, int pid[n], int at[n], int bt[n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(at[i]>at[i+1]){
                int temp1 = at[i];
                at[i] = at[i+1];
                at[i+1] = temp1;

                temp1 = bt[i];
                bt[i] = bt[i+1];
                bt[i+1] = temp1;
                
                temp1 = pid[i];
                pid[i] = pid[i+1];
                pid[i+1] = temp1;
            }
        }
    }
}

// To calculate average wt and tat
void calc(int n, int wt[n], int tat[n]){
    float tot_wt =0, tot_tat=0;
    for(int i = 0; i<n;i++){
        tot_wt += wt[i];
        tot_tat += tat[i];
    }
    tot_wt = tot_wt / n;
    tot_tat = tot_tat / n;
    printf("\nAverage waiting time: %f\nAverage turnaround time: %f\n", tot_wt, tot_tat);
}


// FCFS Scheduling Algorithm
void fcfs(int n, int at[n], int bt[n]){
    sort(n, at, bt);
    int st[n],ct[n],tat[n],wt[n];
    st[0] = at[0];
    ct[0] = bt[0];
    wt[0] = 0;
    tat[0] = ct[0];
    for(int i = 1; i<n;i++){
        st[i] = fmax(at[i],ct[i-1]);
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        if(wt[i]<0) wt[i]=0;
    }
    //Print
    printf("\nFCFS Scheduling:\n");
    printf("Process\tArrival Time\tBurst Time\tStarting Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], st[i], ct[i], tat[i], wt[i]);
    }
    calc(n,wt,tat);
}


int main() {
    int n;
    int qua;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n];
    printf("Enter the pid, arrival time and burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        //printf("Process %d: ", i + 1);
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }
    fcfs(n, at, bt);
    return 0;
}
