#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> ans;
void dfs(int u,int from,int dep){
    if(t[u].empty()&&u!=1) return;
    ans[u]=dep;
    for(auto x:t[u]){
        if(x!=from)
        dfs(x,u,dep+1);
    }
}
int main(){
    int n;cin>>n;
    t.resize(n+1);
    ans.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(1,-1,1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}