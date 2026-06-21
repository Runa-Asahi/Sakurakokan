#include <bits/stdc++.h>
using namespace std;
const int N = 3200;
int a[N];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans = max(ans,a[i]^a[j]);
            }
        }
        cout<<ans<<'\n';
    }
}