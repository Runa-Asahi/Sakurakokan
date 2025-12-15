#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int res=1;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        int num;cin>>num;
        if(num<600) v.push_back(num);
    }
    for(int i=0;i<v.size()-1;i++){
        for(int j=i;j<v.size();j++){
            if(v[j]-v[i]<=k && v[j]-v[i]>=0){
                res = max(res,j - i + 1);
            }
        }
    }
    if(res==1) cout<<"NO";
    else {
        cout<<"YES\n";
        cout<<res;
    }
}