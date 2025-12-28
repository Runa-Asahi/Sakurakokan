#include <bits/stdc++.h>
using namespace std;
int table[105][105];
int dp[105][105];//代表以i,j为右下角的最大符合题意的正方形的边长
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>table[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(table[i][j]==0){
                dp[0][0]=0;
            }
            else{
                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                ans = max(dp[i][j],ans);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}