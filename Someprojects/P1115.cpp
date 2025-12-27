#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int dp[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;int maxn=-1e9;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1]+a[i],a[i]);
        maxn = max(maxn, dp[i]);
    }
    cout<<maxn<<'\n';
    return 0;
}