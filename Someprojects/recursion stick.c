#include <stdio.h>

int solve(int n, int k){
    if(n<=k){
        return 1;
    }
    return solve((int)(n*2.0/5.0+0.5),k)+solve(n-(int)(n*2.0/5.0+0.5),k);
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d\n",solve(n,k));
    return 0;
}