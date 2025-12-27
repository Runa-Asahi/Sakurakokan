#include <stdio.h>

char arr[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char res[36];
char* decimal(int n,int tar){
    int index = 0;
    while(n!=0){  
        res[index] = arr[n%tar];
        index++;
        n /= tar;
    }
    res[index] = '\0';
    for(int i=0;i<index/2;i++){
        char tmp = res[i];
        res[i] = res[index-1-i];
        res[index-1-i] = tmp;
    }
    return &res[0];
}

int main(){
    int n,target;
    scanf("%d %d",&n,&target);
    char* res = decimal(n,target);
    printf("%s\n",res);
    return 0;
}