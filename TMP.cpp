#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int getidx(vector<ll> &b,ll x){
    return lower_bound(b.begin(),b.end(),x)-b.begin();
}
int lowbit(int x){return x&-x;};
void update(int x,int k,vector<ll> &t){
    for(int i=x;i<t.size();i+=lowbit(i)){
        t[i]+=k;
    }
}
ll getsum(int x,vector<ll> &t){
    ll sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=t[i];
    }
    return sum;
} 
int main(){
    int n;ll k;
    while(cin>>n>>k){
        ll result=0;
        vector<ll> a(n+1),b(n+1),t(n+1);
        a[0]=-1;
        b[0]=-1;
        t[0]=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(int i=1;i<=n;i++){
           int idx = getidx(b,a[i]); 
           result += i-1 - getsum(idx,t);
           update(idx,1,t);
        }
        if(result>=k){
            cout<<result-k<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
}