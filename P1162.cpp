#include <bits/stdc++.h>
using namespace std;
int table[35][35];int n;
int vis[35][35];
void dfs(int x,int y){
    if(x<0 || x>=n || y<0 || y>=n || table[x][y]==1 || vis[x][y]) return;
    vis[x][y]=1;
    table[x][y]=0;
    dfs(x+1,y);dfs(x-1,y);dfs(x,y+1);dfs(x,y-1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;cin>>a;
            if(a==1) table[i][j]=1;
            else table[i][j]=2;
        }
    }
    for(int i=0;i<n;i++){
        if(table[i][0]==0 || table[i][0]==1) continue;
        dfs(i,0);
    }
    for(int i=0;i<n;i++){
        if(table[i][n-1]==0 || table[i][n-1]==1) continue;
        dfs(i,n-1);
    }
    for(int i=0;i<n;i++){
        if(table[0][i]==0 || table[0][i]==1) continue;
        dfs(0,i);
    }
    for(int i=0;i<n;i++){
        if(table[n-1][i]==0 || table[n-1][i]==1) continue;
        dfs(n-1,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }
}