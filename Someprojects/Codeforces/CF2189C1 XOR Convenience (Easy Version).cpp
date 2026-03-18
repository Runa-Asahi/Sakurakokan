#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n+5,0);
        vector<int> vis(n+5,0);
        a[n]=1;vis[1]=1;
        for(int i=n-1;i>1;i--){
            if(i&1) a[i] = i-1;
            else a[i] = i+1;
            vis[a[i]]=1;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            a[1]=i;break;
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
    }
}