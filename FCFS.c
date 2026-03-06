#include<stdio.h>
void main(){
    int n,at[10],bt[10],ct[10],tat[10],wt[10],rt[10],PID[10],current_time=0;
    float avg_WT,avg_TAT;
    printf("enter num of process");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        PID[i]=i+1;
        printf("enter at and bt");
        scanf("%d %d",&at[i],&bt[i]);

    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int temp;
            if(at[i]<at[j]){
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=PID[i];
                PID[i]=PID[j];
                PID[j]=temp;

            }
        }
    }
     for(int i=0;i<n;i++){
        if(current_time<at[i]){
            current_time=at[i];
        }
        ct[i]=current_time + bt[i];
        tat[i]=ct[i] - at[i];
        wt[i]=tat[i] - bt[i];
        current_time = ct[i];
        avg_WT += wt[i];
        avg_TAT +=tat[i];
    }
    avg_WT = avg_WT/n;
    avg_TAT = avg_TAT/n;

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",PID[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("Average waiting time is %.2f\n",avg_WT);
    printf("Average Turn around time is %.2f",avg_TAT);
}




