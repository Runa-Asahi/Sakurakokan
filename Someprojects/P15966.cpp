#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 998244353;

ll qpow(ll base, ll exp) {
    ll res = 1;
    base %= N;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % N;
        base = (base * base) % N;
        exp /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;

    while(T--){
        ll x, y;
        cin >> x >> y;
        if(x == y + 1) {
            cout << x % N << '\n';
        }
        else if(x<y+1){
            cout<<1<<'\n';
        } 
        else {
            ll n = (y + 1) % N;
            ll exp = x - y - 1;
            ll res = (n * qpow(2, exp)) % N;
            cout << res << '\n';
        }
    }
    return 0;
}