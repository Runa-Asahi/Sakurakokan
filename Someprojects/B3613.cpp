#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
vector<vector<int>> t;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        t.resize(n+1);
        for(int i=1;i<=n;i++) t[i].clear();
        for(int i=1;i<=m;i++){
            int u,v;cin>>u>>v;
            t[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            sort(t[i].begin(),t[i].end());
            for(auto x:t[i]){
                cout<<x<<" ";
            }
            cout<<'\n';
        }
    }
}