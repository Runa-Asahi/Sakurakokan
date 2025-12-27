#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int dp[N];
int maxn=0;
pair <int,int> ans;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string str;
    cin>>str;
    dp[0]=0;
    for(int i=1;i<str.size();i++){
        if( i-dp[i-1]-1>=0 && str[i]==')' && str[i-dp[i-1]-1]=='('  )
        {
            dp[i]=dp[i-1]+2;  
            if(i-dp[i-1]-2>=0) dp[i]+=dp[i-dp[i-1]-2];
        }
        else if( i-dp[i-1]-1>=0 && str[i]==']' && str[i-dp[i-1]-1]=='[' ){
            dp[i]=dp[i-1]+2;
            if(i-dp[i-1]-2>=0) dp[i]+=dp[i-dp[i-1]-2];
        }
        else dp[i]=0;
        if(dp[i]>maxn){
            maxn = dp[i];
            ans = {i-maxn+1,i};
        }
    }
    if(maxn==0){
        cout << endl;
        return 0;
    }
    for(int i=ans.first;i<=ans.second;i++){
        cout << str[i];
    }
    return 0;
}