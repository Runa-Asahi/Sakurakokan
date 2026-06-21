#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        vector<int> cnt1,cnt2,cnt3,cnt6;
        vector<int> a;
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        for(auto x:a){
            if(x%6==0) cnt6.push_back(x);
            else if(x%3==0) cnt3.push_back(x);
            else if(x%2==0) cnt2.push_back(x);
            else cnt1.push_back(x);
        }
       
        for(auto x:cnt2) cout<<x<<" "; for(auto x:cnt1) cout<<x<<" ";
        for(auto x:cnt3) cout<<x<<" ";
        for(auto x:cnt6) cout<<x<<" ";
        cout<<'\n';
    }
}