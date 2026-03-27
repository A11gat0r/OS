#include <stdio.h>
#include <math.h>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int n, time, cur = -1, nxt;
    int pid[10], b[10], p[10], rem[10], lcm_val = 1;
    double u = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the CPU burst times:\n");
    for(int i = 0; i < n; i++) { scanf("%d", &b[i]); pid[i] = i + 1; rem[i] = 0; }

    printf("Enter the time periods:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        lcm_val = (lcm_val * p[i]) / gcd(lcm_val, p[i]);
        u += (double)b[i] / p[i];
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i] > p[j]) {
                int t=p[i]; p[i]=p[j]; p[j]=t;
                t=b[i]; b[i]=b[j]; b[j]=t;
                t=pid[i]; pid[i]=pid[j]; pid[j]=t;
            }
        }
    }

    printf("LCM=%d\nRate Monotone Scheduling:\nPID\tBurst\tPeriod\n", lcm_val);
    for(int i = 0; i < n; i++) printf("%d\t%d\t%d\n", pid[i], b[i], p[i]);

    double bnd = n * (pow(2.0, 1.0 / n) - 1.0);
    printf("%f<=%f=>%s\nScheduling occurs for %d ms\n", u, bnd, u <= bnd ? "true" : "false", lcm_val);

    for(time = 0; time < lcm_val; time++) {
        nxt = -1;
        for(int i = 0; i < n; i++) {
            if(time % p[i] == 0) rem[i] = b[i];
            if(nxt == -1 && rem[i] > 0) nxt = i;
        }

        if(nxt != cur) {
            if(nxt == -1) printf("%dms onwards: CPU is idle\n", time);
            else printf("%dms onwards: Process %d running\n", time, pid[nxt]);
            cur = nxt;
        }

        if(cur != -1) rem[cur]--;
    }
    return 0;
}
