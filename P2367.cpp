#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+9;
int a[N],diff[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,p;cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) diff[i] = a[i]-a[i-1];
    for(int i=1;i<=p;i++) {
        int x,y,z;cin>>x>>y>>z;
        diff[x] += z;
        if(y+1<=n) diff[y+1] -= z;
    }
    for(int i=1;i<=n;i++) a[i]=a[i-1]+diff[i];
    int res=INT_MAX;
    for(int i=1;i<=n;i++){
        res = min(res,a[i]);
    }
    cout<<res<<'\n';
}
