#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+9;
ll a[N],b[N];
ll gcd(ll a,ll b){
    a = abs(a);
    b = abs(b);
    while(b!=0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
ll allgcd(ll a[],ll n){
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans = gcd(ans,a[i]);
        if(ans==1) break;
    } 
    return ans;
}
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        bool flag = true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=a[1]){
                flag = false;
            }
            b[i] = a[i]-a[1];
        }
        if(flag){
            cout<<"infinite"<<'\n';
            continue;
        }
        ll D = allgcd(b,n);
        ll a1 = a[1];
        ll k = D/gcd(a1,D);
        cout<<D<<" "<<k<<'\n';
    }
}