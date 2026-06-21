#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        vector<int> a;
        a.push_back(0);
        int n;cin>>n;
        int maxd=0;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            a.push_back(x);
            if(a[i]<a[i-1])maxd = max(maxd,a[i-1]-a[i]);
        }
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]) a[i]+=maxd;
            if(a[i]<a[i-1]) {
                cout<<"NO"<<'\n';
                goto l;
            }
        }
        cout<<"YES"<<'\n';
l:;
    }
}