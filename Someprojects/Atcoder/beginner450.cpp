#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int X = 1e3+9;
char table[X][X];
int vis[X][X];
int ax[]={1,0,-1,0};
int ay[]={0,-1,0,1};
int cnt=1;int H,W;int c=0;
bool f = false;
void dfs(int i,int j){
    vis[i][j]=true;
    if(i==1 || i==H || j==1 || j==W) return;
    for(int k=0;k<4;k++){
        int ni = i+ax[k];
        int nj = j+ay[k];
        if(ni<1 || ni>H || nj<1 || nj>W) continue;
        if(vis[ni][nj] || table[ni][nj]=='#') continue;
        if(!vis[ni][nj] && table[ni][nj]=='.' && (ni==1 || ni==H || nj==1 || nj==W)){
            f = true;
        }
        vis[ni][nj]=cnt;
        dfs(ni,nj);  
    }
    return;
    cnt++;
}
int main(){
    cin>>H>>W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>table[i][j];
        }
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(table[i][j]=='#' || vis[i][j]) continue;
            else{
                dfs(i,j);
                f = false;
                if(!f) {
                    c++; 
                }
            }
        }
    }
    int maxn=0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            maxn = max(maxn,vis[i][j]);
        }
    }
    cout<<maxn-c<<'\n';
}