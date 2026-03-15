#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int tmd[N];
int vl[N];
int T,M;int value=0;
int table[N][1200];
int dfs(int pos,int time){
    int v=0;
    if(pos>M){
        return v;
    }
    if(time>T){
        return v;
    }
    if(table[pos][time]) {
        v = table[pos][time];
        return v;
    }
    v = dfs(pos + 1, time);
    if (time + tmd[pos + 1] <= T) {
        v = max(v, dfs(pos + 1, time + tmd[pos + 1]) + vl[pos + 1]);
    }
    table[pos][time]=v;
    return v;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T>>M;
    for(int i=1;i<=M;i++){
        int t,m;cin>>t>>m;
        tmd[i]=t;
        vl[i]=m;
    }
    value = dfs(0,0);
    cout<<value<<'\n';
}