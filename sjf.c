#include<stdio.h>

void main(){
    int n, i, j, current_time = 0, completed_count = 0;
    int AT[20], BT[20], CT[20], TAT[20], WT[20], PID[20], completed[20] = {0};
    float total_WT = 0, total_TAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        PID[i] = i + 1;
        printf("Enter Arrival time and Burst time for P%d: ", PID[i]);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    while(completed_count < n) {
        int idx = -1;
        int min_bt = 10000000;
        for(i = 0; i < n; i++) {
            if(AT[i] <= current_time && completed[i] == 0) {
                if(BT[i] < min_bt) {
                    min_bt = BT[i];
                    idx = i;
                }
                if(BT[i] == min_bt) {
                    if(AT[i] < AT[idx]) {
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1) {
            CT[idx] = current_time + BT[idx];
            TAT[idx] = CT[idx] - AT[idx];
            WT[idx] = TAT[idx] - BT[idx];

            total_WT += WT[idx];
            total_TAT += TAT[idx];
            current_time = CT[idx];
            completed[idx] = 1;
            completed_count++;
        } else {
            current_time++;
        }
    }
    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", PID[i], AT[i], BT[i], CT[i], WT[i], TAT[i]);
    }

    printf("\nAverage waiting time: %.2f", total_WT / n);
    printf("\nAverage Turnaround time: %.2f\n", total_TAT / n);
}
