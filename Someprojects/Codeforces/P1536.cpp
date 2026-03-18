#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int parent[MAXN],rnk[MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;rnk[i]=0;
    }
}
int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
void unite(int x,int y){
    int px = find(x),py = find(y);
    if(px==py) return;
    if(rnk[px]<rnk[py]) swap(px,py);
    parent[py] = px;
    if(rnk[px]==rnk[py]) rnk[px]++;
}
bool same(int x,int y) { return find(x)==find(y); }
int main(){
    int n;
    while(cin>>n && n!=0){
        init(n);
        int m;cin>>m;
        for(int i=1;i<=m;i++){
            int x;int y;cin>>x>>y;
            unite(x,y);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(find(i)==i) cnt++;
        }
        cnt--;
        cout<<cnt<<'\n';
    }   
}