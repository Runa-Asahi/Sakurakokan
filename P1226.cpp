#include <bits/stdc++.h>
using namespace std;
int fast_pow(int a,int b,int p){
    int ans=1;
    while(b){
        if(b&1) ans = (long long)ans * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,b,p;
    cin>>a>>b>>p;
    cout<<a<<'^'<<b<<" "<<"mod"<<" "<<p<<'='<<fast_pow(a,b,p);
    return 0;
}