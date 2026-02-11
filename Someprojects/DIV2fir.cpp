#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> arr;
void solve(){
     ll N,M;cin>>N>>M;
    for(ll i=1;i<=N;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    int maxi = *max_element(arr.begin(),arr.end());
    int left = 0,right = maxi;
    while(left<=right){
        int mid = left + (right-left)/2;
        ll sum = 0;
        for(int i=0;i<N;i++){
            if(arr[i]>mid) sum+=arr[i]-mid;
        }
        if(sum>=M){
            left = mid+1;
        }else right = mid-1;
    }
    cout<<left-1<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    solve();
}