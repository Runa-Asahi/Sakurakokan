#include <stdio.h>
#define N 105

int arr[N];

int find_target(int *arr,int index,int target,int n){
    if(index>=n) return -1;
    if(arr[index]==target) return index;
    return find_target(arr,index+1,target,n);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;scanf("%d",&target);
    if(find_target(arr,0,target,n)!=-1){
        printf("%d",find_target(arr,0,target,n));
    }
    else {
        printf("NULL");
    }
    return 0;
}