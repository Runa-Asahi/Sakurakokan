#include <bits/stdc++.h>
using namespace std;
struct edge{
    int x,y;
};
vector<vector<edge>> mp(5005);
int dfs(int x){
    int len = mp[x].size();
    
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        mp[a].push_back({a,b});
        mp[b].push_back({a,b});
    }
    for(int i=1;i<=n;i++){
        int len = mp[i].size();
        for(int j=1;j<=len;j++){
            mp[i].erase(j);
            dfs(i);
        }
    }
}