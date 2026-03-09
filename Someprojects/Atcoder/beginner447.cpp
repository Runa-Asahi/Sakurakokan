#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+9;
int a[N],b[N];
int ans=0;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    string now = "ABC";
    int cntA=0,cntAB=0,cntABC=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')cntA++;
        else if(s[i]=='B'){
            if(cntAB+1<=cntA)cntAB++;
        }
        else if(s[i]=='C'){
            if(cntABC+1<=cntAB)cntABC++;
        }
    }
    cout<<cntABC<<endl;
}