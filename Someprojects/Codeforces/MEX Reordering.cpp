#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int a0=0,a1=0;
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(x==0)a0++;
            if(x==1)a1++;
        }
        if(a0==0){
            cout<<"NO"<<'\n';
        }else if(a0==1){
            cout<<"YES"<<'\n';
        }else if(a0>=2){
            if(a1!=0){
                cout<<"YES"<<'\n';
            }else{
                cout<<"NO"<<'\n';
            }
        }
    }
}