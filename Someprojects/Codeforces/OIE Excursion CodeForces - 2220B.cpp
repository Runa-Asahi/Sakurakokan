#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int maxn = m-1;
        int cnt=1;int last=0;
        cin>>last;
        bool flag = false;
        for(int i=2;i<=n;i++){
            int x;cin>>x;
            if(flag) continue;
            if(x==last) cnt++;
            else{
                cnt=1;
                last = x;
            }
            
            if(cnt>maxn){
                cout<<"NO\n";
                flag = true;
            }
        }
        if(!flag) cout<<"YES\n";
    }
}