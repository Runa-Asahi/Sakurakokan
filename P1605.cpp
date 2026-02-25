#include <bits/stdc++.h>
using namespace std;
int N,M,T;
int SX,SY,FX,FY;
bool obstacle[10][10];
int pathcnt=0;
int ax[]={0,1,0,-1};//上右下左
int ay[]={1,0,-1,0};
void dfs(int x,int y){
    if(x==FX && y==FY){
        pathcnt++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x+ax[i],ny = y+ay[i];
        if(nx<=0 || nx>N || ny<=0 || ny>M) continue;
        if(obstacle[nx][ny]) continue;
        obstacle[nx][ny]=true;
        dfs(nx,ny);
        obstacle[nx][ny]=false;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>N>>M>>T;
    cin>>SX>>SY>>FX>>FY;
    for(int i=1;i<=T;i++){
       int x,y;cin>>x>>y;
       obstacle[x][y]=true;
    }
    obstacle[SX][SY]=true;
    dfs(SX,SY);
    cout<<pathcnt<<endl;
}