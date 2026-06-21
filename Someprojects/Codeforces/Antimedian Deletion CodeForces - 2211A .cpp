#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(105,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==1) cout<<1<<'\n';
        else{
            for(int i=0;i<n;i++){
                cout<<2<<" ";
            }
            cout<<'\n';
        }
    }
}