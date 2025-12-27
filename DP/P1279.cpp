#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int main(){
    string A,B;
    cin >> A >> B;
    int k;
    cin >> k;
    int n=A.size(),m=B.size();
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0] + k;
    }
    for(int j=1;j<=m;j++){
        dp[0][j] = dp[0][j-1] + k;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min({dp[i-1][j]+k,dp[i][j-1]+k,dp[i-1][j-1]+abs(A[i-1]-B[j-1])});
        }
    }
    cout<<dp[n][m]<<"\n";
}