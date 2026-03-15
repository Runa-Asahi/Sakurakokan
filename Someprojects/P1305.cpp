#include <bits/stdc++.h>
using namespace std;
char tr[100];
map<char,int> mp;
void dfs(int pos){
    if(tr[pos]=='*') return; 
    cout<<tr[pos];
    dfs(pos*2);
    dfs(pos*2+1);
}
int main(){
    int n;cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        char x,y,z;cin>>x>>y>>z;
        if(mp.count(x)){
            tr[mp[x]*2]=y;if(y!='*') mp[y]=mp[x]*2;
            tr[mp[x]*2+1]=z;if(z!='*') mp[z]=mp[x]*2+1;
        }else{
            tr[cnt] = x;if(x!='*') mp[x]=cnt;
            tr[cnt*2] = y;if(y!='*') mp[y]=cnt*2;
            tr[cnt*2+1] = z;if(z!='*') mp[z]=cnt*2+1;            
        }
    }
    dfs(1);
}