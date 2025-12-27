#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N],dp[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;int res = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        res = max(res,dp[i]);
    }
    cout<<res<<'\n';
    return 0;
}