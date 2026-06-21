#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s,t;cin>>n>>m>>s>>t;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
    vector<int> a(n+1,INT_MAX);
    vector<int> vis(n+1); 
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w; 
        dist[u][v]=min(dist[u][v],w);
    }
    int minn=INT_MAX;
    int minx=0;
    vis[s]=1;a[s]=0;
    for(int i=1;i<=n;i++){
        if(dist[s][i]){
            minn = min(minn,dist[s][i]);
            if(minn=dist[s][i]) minx = i;
        } 
    }
    a[minx]=minn;
    while(a[t]==INT_MAX){
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            if(dist[minx][i]==INT_MAX) continue;
            a[i]=min(dist[minx][i]+minn,a[i]);
        }
        
    }
}