#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+9;
unordered_map <int,pair<int,int>> mp;
int visited[N][270];		
string sar[N];
int main(){
	int T;cin>>T;
	for(int i=0;i<T;i++){
		mp.clear();
		memset(visited,0,sizeof(visited));
		fill(sar,sar+N,"");
		int r=0;
		int n;cin>>n;
		for(int j=1;j<=n;j++){
			cin>>sar[j];
			if(sar[j] == "add"){
				int v;cin>>v;
				mp[j].first = v;
				mp[j].second = 0;
			}else if(sar[j] == "beq"){
				int v,k;cin>>v>>k;
				mp[j].first = v;
				mp[j].second = k;
			}else if(sar[j] == "bne"){
				int v,k;cin>>v>>k;
				mp[j].first = v;
				mp[j].second = k;
			}else if(sar[j] == "blt"){
				int v,k;cin>>v>>k;
				mp[j].first = v;
				mp[j].second = k;
			}else if(sar[j] == "bgt"){
				int v,k;cin>>v>>k;
				mp[j].first = v;
				mp[j].second = k;
			}
		}
		bool flag = true;
		for(int j=1;j<=n;j++){
			if(sar[j] == "add"){
				int v;
				v = mp[j].first;
				r += v;
				r = r%256;
				visited[j][r]++;
				if(visited[j][r]==2){
					cout<<"No"<<'\n';
					flag = false;
					break;
				}
			}else if(sar[j] == "beq"){
				int v,k;
				v = mp[j].first;
				k = mp[j].second;
				visited[j][r]++;
				if(visited[j][r]==2){
					cout<<"No"<<'\n';
					flag = false;
					break;
				}
				if(r == v) {
					j = k-1;
					continue;
				}
			}else if(sar[j] == "bne"){
				int v,k;
				v = mp[j].first;
				k = mp[j].second;
				visited[j][r]++;
				if(visited[j][r]==2){
					cout<<"No"<<'\n';					
					flag = false;
					break;
				}
				if(r != v) {
					j = k-1;
					continue;
				}
			}else if(sar[j] == "blt"){
				int v,k;
				v = mp[j].first;
				k = mp[j].second;
				visited[j][r]++;				
				if(visited[j][r]==2){
					cout<<"No"<<'\n';
					flag = false;					
					break;
				}
				if(r < v) {
					j = k-1;
					continue;
				}
			}else if(sar[j] == "bgt"){
				int v,k;
				v = mp[j].first;
				k = mp[j].second;
				visited[j][r]++;
				if(visited[j][r]==2){
					cout<<"No"<<'\n';
					flag = false;
					break;
				}
				if(r > v) {
					j = k-1;
					continue;
				}
			}
			// full complete all the conditions;
		}
		if(flag) cout<<"Yes"<<'\n';
	}
}