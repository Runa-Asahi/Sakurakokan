#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
const int MAXN = 1e5+9;
int parent[N],rnk[N];
struct rd{
    int x,y,t;
};
bool cmp(rd x,rd y){
    return x.t<y.t;
}
rd road[MAXN];
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
bool same(int x,int y) {return find(x)==find(y);}
int main(){
    int N,M;cin>>N>>M;
    init(N);
    for(int i=1;i<=M;i++){
        int x,y,t;cin>>x>>y>>t;
        road[i].x = x;
        road[i].y = y;
        road[i].t = t;
    }
    sort(road+1,road+M+1,cmp);
    int cnt=N;bool f = true;
    for(int i=1;i<=M;i++){
        bool flag = unite(road[i].x,road[i].y);
        if(flag) cnt--;
        if(road[i+1].t==road[i].t) continue;
        else{
            if(cnt==1) {
                f = false;
                cout<<road[i].t<<'\n';
                break;
            }
        }
    }
    if(f) cout<<"-1"<<'\n';
}