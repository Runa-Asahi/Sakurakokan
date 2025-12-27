#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int dic[N];int res[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string S,T;cin>>S>>T;int idx=0;
    int n=S.size(),m=T.size();
    for(int i=0;i<n;i++){
        dic[S[i]]++;
    }
    for(int i=0;i<m;i++){
        if(dic[T[i]]!=0){
            dic[T[i]]--;
            res[idx++]=i+1;
        }
    }
    for(int i=0;i<idx;i++){
        cout << res[i] << " ";
    }
}