#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt1 = n/2;
        int cnt2 = n%2;
        if(cnt2==0){
            int i = cnt1-1,j = cnt1;
            while(j>0){
                cout<<n-i<<" ";
                cout<<j<<" ";
                i--;j--;
            }
        }else{
            int i = cnt1-1,j = cnt1+1;
            while(j>1){
                cout<<j<<" ";
                cout<<n-i<<" ";
                i--;j--;
            }
            cout<<1;
        }
    }
}