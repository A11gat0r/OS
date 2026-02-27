#include<stdio.h>
void main(){
int n;
printf("enter num of elements:\n");
scanf("%d",&n);
int a[n];
printf("enter elements:\n");
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
int min=a[0],x=0;
for(int i=1;i<n;i++){
    if(min>a[i]){
        min=a[i];
        x=i;
    }

}
printf("min element:%d\tposition:%d",min,x);

}
