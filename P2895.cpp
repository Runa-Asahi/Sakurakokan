#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+9;
const int M = 1e5+9;
unordered_map<int,pair<int,int>> mp;
unordered_map<int,int> vis;
int t[305][305];
int table[305][305];
int ax[4]={-1,0,1,0};
int ay[4]={0,1,0,-1};
int ans=INT_MAX;
void bomb(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+ax[i];
        int ny=y+ay[i];
        if(nx>=0 && nx<305 && ny>=0 && ny<305){
            table[nx][ny]=1;
        }
    }
}
void bombt(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+ax[i];
        int ny=y+ay[i];
        if(nx>=0 && nx<305 && ny>=0 && ny<305){
            t[nx][ny]=1;
        }
    }
}
int bugcnt=1000;
void dfs(int time,int x,int y){
    if(x<0 || x>=305 || y<0 || y>=305 || table[x][y] || time>ans || time>1000 || bugcnt<=0){ 
        cout<<"Debug: "<<time<<" "<<x<<" "<<y<<endl;
        bugcnt--;
        return;
    }
    if(vis.count(x) && vis[x]==y){
        ans=min(ans,time);
        return;
    }
    if(mp.count(time)){
        bomb(mp[time].first,mp[time].second);
    }

    dfs(time+1,x-1,y);
    dfs(time+1,x,y+1);
    dfs(time+1,x+1,y);
    dfs(time+1,x,y-1);
}
int main(){
    int M;cin>>M;
    for(int i=0;i<M;i++){
        int x,y,t;
        cin>>x>>y>>t;
        bombt(x,y);
        mp[t]=make_pair(x,y);
    }
    for(int i=0;i<305;i++){
        for(int j=0;j<305;j++){
            if(!t[i][j]) vis[i]=j;
        }
    }
    dfs(0,0,0);
    cout<<"Debug: "<<endl;
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}