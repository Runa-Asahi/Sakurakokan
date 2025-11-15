#include <stdio.h>

long long combination(int m,int n){
    if(n<0) return 0;
    else if(n==0) return 1;
    else if(n==1) return m;
    else if(n==m) return 1;
    else if(m<2*n){
        return (long long)combination(m,m-n);
    }
    else if(m>=2*n){
        return (long long)combination(m-1,n-1)*m/n;
    }
    return -1;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    long long res = combination(m,n);
    printf("%lld\n",res);
    return 0;
}