#include <bits/stdc++.h>
using namespace std;
int ans[10];
int vis[20][20];
void dfs(int sum,int n,int cnt,int num){
    int remain = n-sum;
    if(num==n) return;
    if(sum==n){
        for(int i=0;i<cnt;i++){
            i==cnt-1?cout<<ans[i]:cout<<ans[i]<<'+';
        }
        cout<<'\n';
        return;
    }
    for(int i=num;i<=remain;i++){
        ans[cnt]=i;
        dfs(sum+i,n,cnt+1,i);
        ans[cnt]=0;
    }
}
int main(){
    int n;cin>>n;
    dfs(0,n,0,1);
}