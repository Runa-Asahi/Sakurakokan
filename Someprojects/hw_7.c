#include <stdio.h>
#define N 105

int arr[N];

void reverse_array(int *arr,int n)
{
    if(n<=1) return;
    int temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;
    reverse_array(arr+1,n-2);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    reverse_array(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}