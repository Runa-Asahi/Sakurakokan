#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005]; // dp[i][j] represents 第i种花 将要一共种满j朵花的方案数
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    dp[0][0]=1; // base case
    for(int i=1;i<=n;i++){// 枚举花的种类
        int tmp;cin>>tmp;
        for(int j=0;j<=m;j++){// 枚举要种的花的总数
            for(int k=0;k<=tmp && k<=j;k++){// 枚举第i种花要种k朵
                dp[i][j]+=dp[i-1][j-k];
                dp[i][j]%=1000007;
            }
        }
    }
    cout<<dp[n][m]<<'\n';
    return 0;
}