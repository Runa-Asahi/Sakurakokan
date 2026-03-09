#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--){
        ll n,x;cin>>n>>x;
        ll best=0;ll sumn=0;
        for(int i=0;i<n;i++){
            ll a,b,c;cin>>a>>b>>c;
            sumn += a*(b-1);
            best = max(best,a*b-c);
        }
        if(sumn>=x){
            cout<<0<<'\n';
        }else{
            ll cnt=0;
            x -= sumn;
            if(best==0) {
                cout<<-1<<'\n';
                continue;
            }
            cnt = (x+best-1)/best;//小心 除零错误
            cout<<cnt<<'\n';
        }
    }
}