#include <bits/stdc++.h>
using namespace std;
int n,k;int ans[10];
void dfs(int depth){
    if(depth>n){
        for(int i=1;i<=n;i++){
            if(i<n) cout<<ans[i]<<" ";
            else cout<<ans[i];
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=k;i++){
        ans[depth]=i;
        dfs(depth+1);
        ans[depth]=0;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    dfs(1);
    return 0;
}