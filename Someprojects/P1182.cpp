#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll S = 1e9;
vector<ll> D;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int N,M;//N个数，分成M段
    cin >> N >> M;
    for(int i=0;i<N;i++){
        ll x;
        cin >> x;
        D.push_back(x);
    }
    //N个数，分成M段，求最大每段和的最小值
    ll left=1,right=S;
    while(left<=right){
        ll mid = left+(right-left)/2;
        //mid 指 每段和的最大值
        //mid 增加时，段数减少
        ll sum=0;
        int cnt=1;
        for(int i=0;i<N;i++){
            if(D[i]>mid){
                cnt=M+1;
                break;
            }
            if(sum+D[i]>mid){
                 cnt++;
                 sum=D[i];
            }else sum+=D[i];
        }
        //如果 cnt>M 即 段数过多，需要减少段数，故增加mid
        if(cnt>M) left=mid+1;
        else right=mid-1;
    }
    cout<<right+1<<'\n';
}