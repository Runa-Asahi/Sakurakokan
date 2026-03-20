#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int parent[N],rnk[N];
int mp[N];
void init(int n){
    for(int i=1;i<=n;i++) parent[i]=i,rnk[i]=0;
}
int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
bool unite(int x,int y){
    int px = find(x),py = find(y);
    if(px==py) return false;
    if(rnk[px]<rnk[py])  swap(px,py);
    parent[py] = px;
    if(rnk[px]==rnk[py]) rnk[px]++;
    return true;
}
int main(){
    int n,m;cin>>n>>m;
    init(n);
    for(int i=1;i<=m;i++){
        int p,q;cin>>p>>q;
        unite(p,q);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        int tmp = find(i);
        if(mp[tmp]==0) {
            mp[tmp]=1;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}