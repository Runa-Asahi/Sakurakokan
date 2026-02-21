#include <bits/stdc++.h>
using namespace std;
int table[405][405];
int vis[405][405];
int dx[9]={0,-2,-2,2,2,1,-1,1,-1};
int dy[9]={0,-1,1,-1,1,2,-2,-2,2};
queue<int> row,col;
int main(){
    memset(table,-1,sizeof(table));
    int n,m;cin>>n>>m;//n行m列
    int x,y;cin>>x>>y;//起点
    table[x][y]=0;
    row.push(x);col.push(y);
    vis[x][y]=1;
    while(!row.empty() && !col.empty()){
        int r=row.front(),c=col.front();
        row.pop();col.pop();
        for(int i=1;i<=8;i++){
            int rr=r+dx[i],cc=c+dy[i];
            if(rr<1 || rr>n || cc<1 || cc>m) continue;
            if(vis[rr][cc]) continue;
            vis[rr][cc]=1;
            table[rr][cc]=table[r][c]+1;
            row.push(rr);col.push(cc);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<'\n';
    }
}