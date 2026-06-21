#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int a[N],b[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=n-a[i]+1;
        }
        for(int i=1;i<=n;i++){
            cout<<b[i]<<" ";
        }
        cout<<'\n'; 
    }
}
