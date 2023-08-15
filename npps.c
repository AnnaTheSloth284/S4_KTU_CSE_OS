#include <stdio.h>

// Sort in increasing order of arrival time
void sort(int n, int pid[], int at[], int bt[], int prio[]) {
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

                temp = prio[j];
                prio[j] = prio[j + 1];
                prio[j + 1] = temp;
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

// Priority Scheduling Algorithm
void priority_fn(int n, int pid[], int at[], int bt[], int prio[]) {
    sort(n, pid, at, bt, prio); // Sort based on arrival time
    int wt[n], tat[n];
    int ct[n];
    int rbt[n];
    for (int i = 0; i < n; i++)
        rbt[i] = bt[i];
    int currentt = 0;
    int completed = 0;
    while (completed != n) {
        int highestprioj = -1;
        int highestprio = 999999;
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentt && prio[i] < highestprio && rbt[i] > 0) {
                highestprio = prio[i];
                highestprioj = i;
            }
        }
        if (highestprioj == -1) {
            currentt++;
        } else {
            currentt += rbt[highestprioj];
            ct[highestprioj] = currentt;
            rbt[highestprioj] = 0;
            completed++;
        }
    }

    //Print
    printf("\nPriority Scheduling:\n");
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], prio[i], ct[i], tat[i], wt[i]);
    }
    calc(n, wt, tat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], prio[n];
    printf("Enter the pid, arrival time, burst time, and priority of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &pid[i], &at[i], &bt[i], &prio[i]);
    }
    priority_fn(n, pid, at, bt, prio);
    return 0;
}
