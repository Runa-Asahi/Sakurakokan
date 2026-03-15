#include <bits/stdc++.h>
using namespace std;
int table[200][200];
int path[200];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(table,0x3f3f3f3f,sizeof(table));
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int w,u,v;cin>>w>>u>>v;
        path[i] = w;
        if(u>0) {table[i][u] = 1;table[u][i] = 1;}
        if(v>0) {table[i][v] = 1; table[v][i] = 1;}
    }
    for(int i=1;i<=n;i++) table[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                table[i][j] = min(table[i][j],table[i][k]+table[k][j]);
            }
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        int total=0;
        for(int j=1;j<=n;j++){
            total+=table[i][j]*path[j];
        }
        ans = min(total,ans);
    }
    cout<<ans<<'\n';
}