#include <stdio.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    while(m%n!=0){
        int tmp = m;
        m = n;
        n = tmp % n;
    }
    printf("%d",n);
    return 0;
}