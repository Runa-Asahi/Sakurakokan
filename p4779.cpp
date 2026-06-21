#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
const int M = 2e5+9;
vector<pair<long long,long long>> pii[N];
void add_edge(int u,int v,int w){
    pii[u].push_back({v,w});
}
long long dist[M];
int pre[M];
void dijkstra(int s,int n){
    memset(dist,0x3f,sizeof(dist));
    memset(pre,-1,sizeof(pre));
    dist[s]=0;
    priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(d>dist[u]) continue;
        for(auto& edge:pii[u]){
            long long v = edge.first;
            long long w = edge.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pre[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,s;cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    dijkstra(s,n);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}