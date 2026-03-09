#include <bits/stdc++.h>
using  namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        vector<int> v;
        int cnt0=0;int cnt1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') cnt0++;
            else cnt1++;
        }
        for(int i=0;i<cnt0;i++){
            if(s[i]=='1'){
                v.push_back(i);
            }
        }
        for(int i=cnt0;i<n;i++){
            if(s[i]=='0'){
                v.push_back(i);
            }
        }
        if(v.size()==0){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
            cout<<v.size()<<'\n';
            for(auto x:v)cout<<x+1<<" ";
            cout<<'\n';
        }
    }
}