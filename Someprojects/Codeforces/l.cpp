#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n+1][n+1];
    memset(a,0,sizeof(a));
    int dist[n+1];
    int vis[n+1];
    memset(dist,0,sizeof(dist));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dist[1]=0;
    int minn=INT_MAX;
    int minx=0;
    vis[1]=true;
    for(int i=2;i<=n;i++){
        if(a[1][i]==0) dist[i]=INT_MAX;
        else dist[i]=a[1][i];
        minn = min(minn,dist[i]);
        if(minn==dist[i]) minx = i;
    }
    vis[minx]=true;
    while(!vis[n]){
        for(int i=2;i<=n;i++){
            if(a[minx][i]==0) continue;
            if(vis[i]) continue;
            dist[i]=min(dist[i],dist[minx]+a[minx][i]);
        }
        minn = INT_MAX;
        for(int j=1;j<=n;j++){
                if(vis[j]) continue;
                else {
                    minn=min(minn,dist[j]);
                    if(minn==dist[j]) minx=j;
                }
            }
        vis[minx]=true;

    }
    cout<<dist[n]<<'\n';
}