#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> ans;
vector<int> vis;
int main(){
    int n;cin>>n;
    t.resize(n+1);
    vis.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(t[i].begin(),t[i].end());
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u]=1;
        ans.push_back(u);
        for(auto x:t[u]){
            if(!vis[x]){
                q.push(x);
            }
        }
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}
