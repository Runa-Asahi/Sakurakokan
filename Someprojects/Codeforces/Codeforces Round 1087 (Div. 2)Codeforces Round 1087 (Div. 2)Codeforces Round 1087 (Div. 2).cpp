#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        vector <int> a;
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n;i++){
            int ans1=0,ans2=0;
            for(int j=i+1;j<n;j++){
                if(a[j]<a[i]){
                    ans1++;
                }
                if(a[j]>a[i]){
                    ans2++;
                }
            }
            cout<<max(ans1,ans2)<<" ";
        }
        cout<<'\n';
    }
}