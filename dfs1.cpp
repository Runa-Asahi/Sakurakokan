#include <bits/stdc++.h>
using namespace std;
vector<int> arr;int n,k;
void dfs(int pastpairs,int pastsum,int cnt){
	if(pastpairs==k){
		cnt++;
		return;
	}
	for(int i=pastsum+1;i<=n;i++){
		dfs(pastpairs+1,pastsum+i,cnt);
	}
}
int main(){
	cin>>n>>k;int cnt=0;
	dfs(0,0,cnt);
	cout<<cnt<<'\n';
} 
