#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> a;
        for(int i=0;i<n;i++){
            ll x;cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n-1;i++){
            if(a[i]<=a[i+1]) continue;
            else{
                a[i]+=a[i+1];
                swap(a[i],a[i+1]);
            }
        }
        cout<<a[n-1]<<'\n';
    }
}