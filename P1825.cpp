#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
int N,M;int fx,fy;int ans=inf;int sx,sy;
char table[305][305];
bool vis[305][305];
int dist[305][305];
int ax[]={-1,0,1,0};
int ay[]={0,1,0,-1};
map<pair<int,int>,pair<int,int>> mp;
map<char,pair<int,int>> first_pos;
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>table[i][j];
            if(table[i][j]=='='){
                fx=i;fy=j;
            }else if(table[i][j]=='@'){
                sx=i;sy=j;
            }else if(table[i][j]=='#'){
            }else if(table[i][j]=='.'){
            }else{
                char c = table[i][j];
                if(first_pos.find(c)==first_pos.end()){
                    first_pos[c]={i,j}; // 第一次遇到这个字母，记录坐标
                }else{
                    auto [x,y] = first_pos[c];
                    mp[{i,j}]={x,y};
                    mp[{x,y}]={i,j}; // 成对出现，装入你的 mp 中
                }
            }
        }
    }
    queue<pair<int,int>>q;
    q.push({sx,sy});
    vis[sx][sy]=true;
    dist[sx][sy]=0;
    while(!q.empty()){
        auto [x,y] = q.front();q.pop();
        if(x==fx&&y==fy){
            ans=dist[x][y];
            break;
        }
                for(int i=0;i<4;i++){
            int nx=x+ax[i],ny=y+ay[i];
            
            // 1. 先判断基本的下一步是否越界、是否撞墙
            if(nx>=0 && nx<N && ny>=0 && ny<M && table[nx][ny]!='#'){
                
                // 2. 如果这步踩到了传送门，瞬间改变真正的落点
                if(mp.find({nx,ny}) != mp.end()){
                    auto [tx,ty] = mp[{nx,ny}];
                    nx = tx; 
                    ny = ty;
                }
                
                // 3. 此时的 nx, ny 已经是最终的落点了。
                // 我们判断这个最终落点有没有被走过，没走过就入队！
                if(!vis[nx][ny]){
                    q.push({nx,ny});
                    dist[nx][ny] = dist[x][y] + 1;
                    vis[nx][ny] = true;
                }
            }
        }
    }
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}