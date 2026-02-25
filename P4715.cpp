#include <bits/stdc++.h>
using namespace std;
string s = "yizhong";
char table[105][105];
char ans[105][105];
int ax[]={0,1,1,1,0,-1,-1,-1};
int ay[]={1,1,0,-1,-1,-1,0,1};
bool isword = false;
int n;
void dfs(int x,int y,int cnt,int dir){
    if(cnt==7){
        isword=true;
        ans[x][y]=s[cnt-1];
        return;
    }
    int tx=x+ax[dir];
    int ty=y+ay[dir];
    if(tx<1||tx>n||ty<1||ty>n) return;
    if(table[tx][ty]!=s[cnt]) return;
    dfs(tx,ty,cnt+1,dir);
    if(isword){
        ans[x][y]=s[cnt-1];
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>table[i][j];
        }
    }
    memset(ans,'*',sizeof(ans));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(table[i][j]=='y'){
                int cnt=1;
                for(int k=0;k<8;k++){
                    dfs(i,j,cnt,k);
                    isword=false;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}