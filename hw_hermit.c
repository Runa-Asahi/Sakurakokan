#include <stdio.h>

double Hermite(int n,int x){
    if(n==0) return 1.0;
    else if(n==1) return 2.0*x;
    else{
        return 2.0*x*Hermite(n-1,x)-2.0*(n-1)*Hermite(n-2,x);
    }
}

int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    printf("%.2lf",Hermite(n,x));
}