#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        vector<int> a;
        int m;cin>>m;
        for(int i=1;i<=m;i++){
            int x; cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        int n = a.size();
        int maxcnt=1;int cnt = 1;
        for(int i=0;i<=n-2;i++){
            if(a[i+1]-a[i]==1) cnt++;
            else{
                maxcnt = max(maxcnt,cnt);
                cnt=1;
            }
        }
        maxcnt = max(maxcnt,cnt);
        cout<<maxcnt<<"\n";
    }
}