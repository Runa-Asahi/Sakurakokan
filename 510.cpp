#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll c(ll i){
    return (i*(i+1))/2;
}
int main(){
    int t;cin>>t;
    while(t--){
        ll w,b;cin>>w>>b;
        ll sum = w+b;ll ans=1;
        if(sum==0){
            cout<<0<<'\n';
            continue;
        }else if(sum==1){
            cout<<1<<'\n';
            continue;
        }
        ll l=1,r=min(sum,(ll)200005);
        while(l+1<r){
            ll mid = l+(r-l)/2;
            if(c(mid)<=sum) l = mid;
            else r = mid;
        }
        cout<<l<<'\n';
    }
}