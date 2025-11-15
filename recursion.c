#include <stdio.h>

int combination(int m,int n){
    if(n<0) return 0;
    else if(n==0) return 1;
    else if(n==1) return m;
    else if(m<2*n){
        return combination(m-n,n);
    }
    else if(m>=2*n){
        return combination(m-1,n-1)*(m-2*n)/n;
    }
    return -1;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int res = combination(m,n);
    printf("%d\n",res);
    return 0;
}