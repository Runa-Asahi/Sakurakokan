 #include <bits/stdc++.h>
 using namespace std;
 vector<string> str;
 int n;int cnt=0;
 int dfs(int pos,vector<int> &vis){
    if(vis[pos]!=-1) return vis[pos];
    int ans=1;
    for(int i=pos+1;i<=n;i++){
        if(str[i].find(str[pos])==0){
            ans = max(ans, 1 + dfs(i, vis));
            vis[i] = ans;
        }else{
            break;
        }
    }
    return ans;
 }
 int main(){
   cin>>n;
    str.push_back("NULL");
   vector<int> vis(n+1,-1);
   for(int i=1;i<=n;i++){
         string x;cin>>x;
         str.push_back(x);
   }
   for(int i=1;i<=n;i++){
        cnt = max(cnt,dfs(i,vis));
   }
   cout<<cnt<<'\n';
 }