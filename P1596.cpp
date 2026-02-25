#include <bits/stdc++.h>
using namespace std;
char field[105][105];int ans=0;
bool visited[105][105];
int ax[]={0,1,1,1,0,-1,-1,-1};
int ay[]={1,1,0,-1,-1,-1,0,1};
int N,M;
void dfs(int x,int y){
    for(int i=0;i<8;i++){
        if(x+ax[i]<1 || x+ax[i]>N || y+ay[i]<1 || y+ay[i]>M) {
            continue;
        }
        int nx = x+ax[i],ny = y+ay[i];
        if(field[nx][ny]=='.' || visited[nx][ny]) {
            continue;
        }
        visited[nx][ny]=true;
        dfs(nx,ny);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>field[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(visited[i][j] || field[i][j]=='.') continue;
            visited[i][j]=true;
            dfs(i,j);
            ans++;
        }
    }
    cout<<ans<<'\n';
}