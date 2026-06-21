#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,s,x;cin>>n>>s>>x;
        int sum=0;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            sum+=x;
        }
        if(s-sum<0) {
            cout<<"NO"<<'\n';
            continue;
        }
        if((s-sum)%x==0){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
}