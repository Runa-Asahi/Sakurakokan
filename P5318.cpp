#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+9;
vector<pair<int,int>> pii[MAXN];
bool visp[MAXN];
bool vis[MAXN];
int n,m;
void add_edge(int u, int v, int w) {
    pii[u].push_back({v, w});
}
void dfs(int pos){
    if(pos>n) return;
    if(visp[pos]) return;
    cout<<pos<<" ";
    visp[pos] = true;
    for(auto [x,y]:pii[pos]){
        dfs(x);
        visp[x]=true;
    }
}
void bfs(int pre){
    queue<int> q;
    q.push(pre);
    vis[num]=true;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(auto [x,y]:pii[num]){
            if(!vis[x]) q.push(x);
        }
        cout<<num<<" ";
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        add_edge(x,y,1);
    }
    dfs(1);
    cout<<'\n';
    bfs(1);
}