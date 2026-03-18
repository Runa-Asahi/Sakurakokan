#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int parent[N],rnk[N];
void init(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i,rnk[i]=0;
    }
}
int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
void unite(int x,int y){
    int px = find(x),py = find(y);
    if(px == py) return;
    if(rnk[px]<rnk[py]) swap(px,py);
    parent[py]=px;
    if(rnk[x]==rnk[py]) rnk[px]++;
}
bool same(int x,int y){
    return find(x)==find(y);
}
int main(){
    int N,M;cin>>N>>M;init(N);
    while(M--){
        int Z;cin>>Z;
        int x,y;cin>>x>>y;
        if(Z==1){
           unite(x,y); 
        }else{
            if(same(x,y)) cout<<"Y"<<'\n';
            else cout<<"N"<<'\n';
        }
    }
}