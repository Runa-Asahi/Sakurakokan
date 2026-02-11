#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> sig;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll L;int N,K;
	cin>>L>>N>>K;
	for(int i=0;i<N;i++){
		ll num;cin>>num;
		sig.push_back(num);
	}
	ll left=1,right=L;
	while(left<=right){
		ll mid = left+(right-left)/2;//两点最大距离
		//两点最大距离增大，放置路标的数量减小 
		int cnt=0;ll last=sig[0];
		for(int i=1;i<N;i++){
			ll last=sig[i-1];
			ll len = sig[i]-last;
			if(len>mid){
				cnt += (len-1)/mid;//放置路标数量 	
			}
		}
		if(cnt<=K) right = mid-1;
		else left = mid+1;
	}
	cout<<right+1<<'\n';
} 