#include <stdio.h>

char* turn(int N, int b){
    for(int i=0;;i++){
        if(pow(b,i)<=N && pow(b,i+1)>=N){
            int tmp = pow(b,i+1)-N;
            char* res = turn(tmp,b);
            
        }
    }
    
}

int main(){
    int N,b;
    scanf("%d %d",&N,&b);
    int res=0;

    return 0;
}