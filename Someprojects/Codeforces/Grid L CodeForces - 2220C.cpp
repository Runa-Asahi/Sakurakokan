#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int p,q;cin>>p>>q;
        ll sum = (ll)p+(ll)2*q;
        ll num = (ll)sqrt(sum);
        bool flag = false;
        for(ll i=1;i<=num+1;i++){
            if(flag) break;
            if((sum-i)%(2*i+1)==0){
                ll j = (sum-i)/(2*i+1);
                if(p<abs(i-j)) continue;
                cout<<i<<" "<<j<<'\n';
                flag = true;
            }
        }
        if(!flag) cout<<-1<<'\n';
    }
}