#include<stdio.h>

void main(){
int n,f=0;
printf("enter num of elements:\n");
scanf("%d",&n);
int a[n];
printf("enter elements:\n");
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]==a[j]){
            printf("duplicates present");
            f=1;
            break;
        }
    }
}
if(f==0)printf("no duplicates");}
