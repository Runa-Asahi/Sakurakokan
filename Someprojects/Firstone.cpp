#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
int a[N];
ll prefix[N];

int find(int x){
    if(x==0) return 2;
    int i=1;
    while(1){
        if(pow(2,i)>x && pow(2,i-1)<=x){
            return pow(2,i);
        }
        i++;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]+a[i];
        }

        long long ans = 0;
        for(int i=1;i<=n;i++){
            int ii = i;
            ll need_sum = find(a[i]);
            
            ll score = log2(need_sum); 

            while(ii <= n){

                ll val = need_sum + prefix[i-1];
                
                auto ptr = lower_bound(prefix+ii,prefix+n+1,val);
                
                int j = ptr - prefix - 1;
                
                ll count = j - ii + 1;
                
                if(count > 0){
                    ll sum_j = (ll)(ii + j) * count / 2;
                    ll total = (ll)i * count + sum_j;
                    
                    ans += total * score;
                }
                
                ii = j + 1;
                need_sum *= 2;
                score++; 
            }
        }
        cout<<ans<<"\n";
    }
}