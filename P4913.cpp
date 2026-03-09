#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct node{
    int l,r;
};
node a[N];int ans=0;
void dfs(int pos,int depth){
    if(a[pos].l==0 && a[pos].r ==0){
        ans=max(ans,depth);
        return;
    }
    dfs(a[pos].l,depth+1);
    dfs(a[pos].r,depth+1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
    }
    dfs(1,1);
    cout<<ans<<endl;
}