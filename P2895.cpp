#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int table[305][305];
int ax[] = {-1, 0, 1, 0};
int ay[] = {0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    fill(&table[0][0],&table[0][0]+305*305,INF);
    int M;cin>>M;
    for(int i=1;i<=M;i++){
        int x,y,t;cin>>x>>y>>t;
        if(t<table[x][y]) table[x][y]=t;
        for(int j=0;j<4;j++){
            int nx = x+ax[j], ny = y+ay[j];
            if(nx<0 || nx>304 || ny<0 || ny>304) continue;
            if(t<table[nx][ny]) table[nx][ny]=t;
        }
    }
    queue<pair<int,pair<int,int>>> q;
    bool visited[305][305] = {false,};
    q.push({0, {0,0}});
    visited[0][0] = true;
    int ans = -1;
    if(table[0][0]==0){
        cout<<-1<<'\n';
        return 0;
    }
    while(!q.empty()){
        int nx = q.front().second.first, ny = q.front().second.second, t = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nnx = nx+ax[i], nny = ny+ay[i];
            if(nnx<0 || nnx>304 || nny<0 || nny>304) continue;
            if(!visited[nnx][nny] && t+1<table[nnx][nny]) {
                q.push({t+1, {nnx, nny}});
                visited[nnx][nny] = true;
            }
        }
        if(table[nx][ny]==INF){
            ans = t;
            break;
        }
    }
    cout<<ans<<'\n';
}