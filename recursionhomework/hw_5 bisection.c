#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define N 105
int arr[N];
int vis[0x3fff];

int lower_bound(int *arr,int len,int target){
    int left=-1,right = len;
    while(left+1<right){
        int mid = left+(right-left)/2;
        if(target <= arr[mid]){
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return right;
}
int cmp(const void * a,const void * b){
    return *(int*)a - *(int*)b;
}
int main(){
    int n;int target;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(vis[arr[i]]==0) vis[arr[i]]=i;
    }
    qsort(arr,n,sizeof(int),cmp);
    scanf("%d",&target);
    if(target>arr[n-1]){
        printf("NULL");
        return 0;
    }
    int res = lower_bound(arr,n,target);
    if(arr[res]!=target){
        printf("NULL");
        return 0;   
    }
    printf("%d",vis[arr[res]]);
    return 0;
}