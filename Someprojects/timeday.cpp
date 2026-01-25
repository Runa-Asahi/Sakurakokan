#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;ll M;
map<pair<int,ll>,ll> mp;
ll prelcm[50];
ll gcd(ll a,ll b){
    for(;b;a%=b,swap(a,b));
    return a;
}
ll lcm(ll a,ll b){
    if(a>=M) return a;
    __int128 temp = (__int128)a / gcd(a, b) * b;
    if(temp>=M) return M;
    return (ll)temp;
}
ll dfs(int step,ll llcm){
    if(llcm>=M){
        return (1LL<<step);
    }
    if(mp.count({step,llcm})){
        return mp[{step,llcm}];
    }
    if(lcm(llcm,prelcm[step])<M){
        return 0;
    }
    if(step==0){
        return 0;
    }
    ll nlcm = lcm(llcm,step);
    ll res1 = dfs(step-1,nlcm);
    ll res2 = dfs(step-1,llcm);
    mp[{step,llcm}] = res1 + res2;
    return mp[{step,llcm}];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    prelcm[0]=1;
    for(int p=1;p<=T;p++){
        mp.clear();
        cin>>N>>M;
        if(M==1){
            cout<<"Case #"<<p<<": "<<(1LL<<N)<<'\n';
            continue;
        }
        for(int i=1;i<=N;i++){
            prelcm[i]=lcm(prelcm[i-1],i);
        }
        ll res = dfs(N,1);
        cout<<"Case #"<<p<<": "<<res<<'\n';
        for(int i=1;i<=N+1;i++) prelcm[i]=1;
    }
}