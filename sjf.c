#include <stdio.h>
#include <math.h>

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

void calc(int n, int wt[], int tat[]) {
    float tot_wt = 0, tot_tat = 0;
    for (int i = 0; i < n; i++) {
        tot_wt += wt[i];
        tot_tat += tat[i];
    }
    tot_wt /= n;
    tot_tat /= n;
    printf("Average waiting time: %f\nAverage turnaround time: %f\n", tot_wt, tot_tat);
}

void sjf(int n, int pid[], int at[], int bt[]) {
    sort(n, pid, at, bt);
    int st[n], ct[n], tat[n], wt[n];

    int currentt = 0;
    int completed = 0;
    int shortestbt = 999999;
    int shortestpid = -1;

    while(completed != n) {
        shortestbt = 999999; // Reset shortestbt inside the loop
        shortestpid = -1;    // Reset shortestpid inside the loop

        for (int i = 0; i < n; i++) {
            if (at[i] <= currentt && bt[i] > 0 && bt[i] < shortestbt) {
                shortestbt = bt[i];
                shortestpid = pid[i];
            }
        }

        if (shortestpid != -1) {
            for (int j = 0; j < n; j++) {
                if (pid[j] == shortestpid) {
                    st[j] = currentt;
                    ct[j] = currentt + bt[j];
                    tat[j] = ct[j] - at[j];
                    wt[j] = tat[j] - bt[j];
                    if (wt[j] < 0) wt[j] = 0;
                    currentt = ct[j];
                    bt[j] = 0; // Set burst time to 0 since the process is completed
                    completed++;
                    break;
                }
            }
        } else {
            currentt++; // No process found, increment time
        }
    }

    printf("\nSJF Scheduling:\n");
    printf("Process\tArrival Time\tBurst Time\tStarting Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], st[i], ct[i], tat[i], wt[i]);
    }
    calc(n, wt, tat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n];
    printf("Enter the arrival time and burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        pid[i] = i + 1; // Assign unique process IDs
    }
    sjf(n, pid, at, bt);
    return 0;
}
