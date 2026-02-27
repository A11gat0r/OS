#include<stdio.h>
void main(){
int n,x,f=0;
printf("enter num of elements:\n");
scanf("%d",&n);
int a[n];
printf("enter elements:\n");
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("enter element:\n");
scanf("%d",&x);

for(int i=0;i<n;i++){
    if(a[i]==x){
        printf("found using linear search\n");
        f=1;
    }
}
int low=0,high=n-1,mid=(low+high)/2;

while(low<=mid&&high>=mid){
    if(a[mid]==x){
        printf("found using binary search");
        f=1;
        break;
    }
    else if(a[mid]<x){
        low=mid+1;
        mid=(low+high)/2;
    }
    else if(a[mid]>x){
        high=mid-1;
        mid=(low+high)/2;
    }

}
if(f==0)printf("element not found");

}
