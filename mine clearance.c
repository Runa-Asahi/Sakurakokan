#include <stdio.h>
#include <stdbool.h>
char a[1002][1002];

bool is_mine(char c){
    if(c == '*'){
        return true;
    }
    return false;
}

int ax[8] = {-1,-1,-1,0,0,1,1,1};
int ay[8] = {-1,0,1,-1,1,-1,0,1};

void print(char *c){
    int cnt = 0;
    for(int i=0;i<8;i++){
        char an = *(c+ay[i]+ax[i]*1002);
        if(an == '\0'){
            continue;
        }
        if(is_mine(an)){
            cnt++;
        }
    }
    printf("%d",cnt);
    return;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(is_mine(a[i][j])){
                printf("*");
            }else{
                print(&a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}