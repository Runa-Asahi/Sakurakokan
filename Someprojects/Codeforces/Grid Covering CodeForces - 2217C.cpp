#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){
    return b==0 ? a:gcd(b,a%b);
}
int main(){
    int t;cin>>t;
    while(t--){
        ll n,m,a,b;cin>>n>>m>>a>>b;
        ll gna = gcd(n,a);
        ll gmb = gcd(m,b);
        ll gmn = gcd(m,n);
        if(gna==1 && gmb==1 && gmn<=2) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
