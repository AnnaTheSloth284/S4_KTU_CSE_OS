#include <stdio.h>

//Sort in increasing order of arrival time
void sort(int n, int pid[], int at[], int bt[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
}

// To calculate average wt and tat
void calc(int n, int wt[], int tat[]) {
    float tot_wt = 0, tot_tat = 0;
    for (int i = 0; i < n; i++) {
        tot_wt += wt[i];
        tot_tat += tat[i];
    }
    tot_wt = tot_wt / n;
    tot_tat = tot_tat / n;
    printf("Average waiting time: %f\nAverage turnaround time: %f\n", tot_wt, tot_tat);
}

// Round Robin Scheduling Algorithm
void round_robin(int n, int at[], int bt[], int qua) {
    int pid[n];
    for (int i = 0; i < n; i++)
        pid[i] = i + 1; // Assign unique process IDs
    
    sort(n, pid, at, bt); // Sort based on arrival time
    int st[n], ct[n], wt[n], tat[n];
    int rbt[n];
    for (int i = 0; i < n; i++)
        rbt[i] = bt[i];
    
    int currentt = 0;
    int completed = 0;
    
    //printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    while (completed != n) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentt && rbt[i] > 0) {
                flag = 1;
                if (rbt[i] > qua) {
                    currentt += qua;
                    rbt[i] -= qua;
                } else {
                    currentt += rbt[i];
                    rbt[i] = 0;
                    completed++;
                    ct[i] = currentt;
                    tat[i] = currentt - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
        if (flag == 0)
            currentt++;
    }
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    calc(n, wt, tat);
}

int main() {
    int n;
    int qua;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n];
    printf("Enter the arrival time and burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &qua);
    round_robin(n, at, bt, qua);
    return 0;
}
