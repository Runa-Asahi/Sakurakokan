#include <stdio.h>

typedef struct{
    char name[20];
    int score1,score2,sumscore;
}student;

student students[15];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%s %d %d",students[i].name,&students[i].score1,&students[i].score2);
        students[i].sumscore = students[i].score1 + students[i].score2;
    }
    for(int i=1;i<=n;i++){
        printf("%s %d\n",students[i].name,students[i].sumscore);
    }
    return 0;
}