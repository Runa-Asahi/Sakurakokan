#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,x,y;cin>>n>>x>>y;
        int stpos = x+1, edpos = y;
        
        vector<int> s;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            s.push_back(a);
        }
        
        vector<int> s1;
        for(int i=stpos-1;i<edpos;i++){
            s1.push_back(s[i]);
        }
        
        int ls = s1.size();int minpos = 0;
        
        for(int i=0;i<ls;i++){
            if(s1[i]<s1[minpos]){
                minpos = i;
            }
        }
        vector<int> s11(s1.begin()+minpos, s1.end());
        vector<int> s12(s1.begin(), s1.begin()+minpos);
        for(int i=0;i<(int)s12.size();i++){
            s11.push_back(s12[i]);
        }
        s.erase(s.begin()+stpos-1, s.begin()+edpos);
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]>s1[0]){
                s.insert(s.begin()+i, s11.begin(), s11.end());
                break;
            }
        }
        if(static_cast<int>(s.size())==(n-s1.size())) s.insert(s.end(), s1.begin(), s1.end());
        for(int i=0;i<n;i++){
            cout<<s[i]<<" ";
        }
        cout<<"\n";
    }
}
