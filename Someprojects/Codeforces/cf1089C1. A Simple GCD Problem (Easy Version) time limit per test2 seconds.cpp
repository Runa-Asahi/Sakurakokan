#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int a[N],b[N],g[N];

int main(){
    int t;cin>>t;
    a[0]=1;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i]=gcd(a[i],a[i-1]);
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        int cnt=0;
        if(g[2]<a[1]) cnt++;
        //cout<<"cnt: "<<cnt<<'\n';
        for(int i=2;i<n;i++){
            int A = g[i];
            int B = g[i+1];
            int tmp = lcm(A,B);
            if(tmp<a[i]) cnt++;
        }
        //cout<<"cnt: "<<cnt<<'\n';
        if(g[n]<a[n]) cnt++;
        cout<<cnt<<'\n';
    }
}