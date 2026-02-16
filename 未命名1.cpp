#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			if(x==67) {
				cout<<"YES\n";
				goto end;
			}
			a.push_back(x);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]*a[j]==67) {
					cout<<"YES\n";
					goto end;
				}
			}
		}
		cout<<"NO\n";
		end:;
		a.clear();
	}
}