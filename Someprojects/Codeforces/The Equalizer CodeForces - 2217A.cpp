#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        vector<int> a;
        int n,k;cin>>n>>k;
        int sum=0;int nsum=n*k;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            sum+=x;
        }
        if(sum%2!=0){
            cout<<"YES"<<'\n';
        }else{
            if(nsum%2!=0){
                cout<<"NO"<<'\n';
            }else{
                cout<<"YES"<<'\n';
            }
        }
    }
}