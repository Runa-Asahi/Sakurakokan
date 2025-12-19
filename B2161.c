#include <stdio.h>
int arr[15];
int main(){
    int n,idx=0;
    scanf("%d",&n);
    if(n==0){
        return 0*printf("0");// Special case for 0
    }
    while(n!=0){
        arr[idx]=n%2;
        n/=2;
        idx++;
    }
    for(int i=idx-1;i>=0;i--){
        printf("%d",arr[i]);
    }
    return 0;
}