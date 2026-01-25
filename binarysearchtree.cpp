#include <bits/stdc++.h>
using namespace std;
int N;int M;
vector<int> len,used(60,0);
void getfactor(int x,vector<int> &factor,int max){
	factor.push_back(1);
	factor.push_back(x);
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			int x1 = i, x2 = x/i;
			if(x1>=max){
				factor.push_back(x1);
				factor.push_back(x2);
			}
			else if(x2>=max){
				factor.push_back(x2);
			} 
		}
	}
	sort(factor.begin(),factor.end());
}
bool dfs(int fin_len, int cur_idx, int cur_len,int ever_cnt){
	if(ever_cnt == M){
		return true;
	}
	if(cur_len >= fin_len){
		return dfs(fin_len,0,0,ever_cnt+1);
	} 
	for(int i=cur_idx;i<N;i++){
		if (i > 0 && len[i] == len[i-1] && !used[i-1]) continue;
		if(!used[i] && cur_len+len[i]<=fin_len){
			used[i]=1;
			if(dfs(fin_len, i+1, cur_len+len[i], ever_cnt))return true;
			used[i]=0;
			if (cur_len == 0) return false;
		 	if (cur_len + len[i] == fin_len) return false;
		} 
	}
	return false;
};
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N;
	int maxlength=0;int sum=0;
	for(int i=0;i<N;i++){
		int x;cin>>x;
		maxlength = max(maxlength,x);
		sum += x;
		len.push_back(x);
	}
	sort(len.begin(),len.end(),greater<int>());
	vector<int> fac;
	getfactor(sum,fac,maxlength);
	for(auto l:fac){
		M = sum/l;
		fill(used.begin(), used.end(), 0);
		bool flag = dfs(l,0,0,0);
		if(flag){
			cout<<l;
			break;
		}
	}
} 
