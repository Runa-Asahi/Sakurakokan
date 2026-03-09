#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int len = s.size();
        int l = len/2;
        int cnt1=0;
        for(int i=0;i<l;i++){
            if(s[i]=='(') cnt1++;
            else break; 
        }
        if(cnt1==l || cnt1==l-1){
            cout<<-1<<'\n';
        }else cout<<len-2<<'\n';
    }
}