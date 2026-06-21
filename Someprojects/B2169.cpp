#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> ans;
void dfs(int root,int from){
    if(!t[root].empty()){
        sort(t[root].begin(),t[root].end());
    }
    ans.push_back(root);
    for(auto x:t[root]){
        if(x!=from){
            dfs(x,root);
        }
    }
}
int main(){
    int n;cin>>n;
    t.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int empty_node = -1;
    int root=1;
    dfs(root,empty_node);
    for(auto x:ans) cout<<x<<" ";
}
