#include <stdio.h>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int n, time, lcm_val = 1, min_d, sel;
    int pid[10], b[10], d[10], p[10], rem[10], abs_d[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1; rem[i] = 0;
        printf("Process %d - Enter Burst, Deadline, Period: ", pid[i]);
        scanf("%d %d %d", &b[i], &d[i], &p[i]);
        lcm_val = (lcm_val * p[i]) / gcd(lcm_val, p[i]);
    }

    printf("\nPID\tBurst\tDeadline\tPeriod\n");
    for (int i = 0; i < n; i++) printf("%d\t%d\t%d\t\t%d\n", pid[i], b[i], d[i], p[i]);
    printf("Scheduling occurs for %d ms\n", lcm_val);

    for (time = 0; time < lcm_val; time++) {
        min_d = 999999;
        sel = -1;

        for (int i = 0; i < n; i++) {
            if (time % p[i] == 0) { rem[i] = b[i]; abs_d[i] = time + d[i]; }

            if (rem[i] > 0 && abs_d[i] < min_d) { min_d = abs_d[i]; sel = i; }
        }
        if (sel == -1) printf("%dms: CPU is idle.\n", time);
        else {
            printf("%dms: Task %d is running.\n", time, pid[sel]);
            rem[sel]--;
        }
    }
    return 0;
}
