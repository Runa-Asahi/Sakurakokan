#include <bits/stdc++.h>
using namespace std;
const int N = 805;
struct Node{
    int x,y;
};
int n,m;
char mp[N][N];
int boyvis[N][N];
int girlvis[N][N];
vector<Node> ghost;

int ax[]={1,0,-1,0};
int ay[]={0,1,0,-1};

bool check_safe(int x,int y,int t){
    // 必须判空，虽然题目保证有2个鬼，但为了安全
    if(ghost.empty()) return true; 
    
    // 遍历所有鬼（题目固定2个，写循环通用点）
    for(auto &g : ghost){
        if(abs(g.x - x) + abs(g.y - y) <= 2*t) return false;
    }
    return true;
}

// bfs 不需要返回 true/false 了，我们在内部处理完一层就行
// 返回值改成 boolean 仅仅表示是否相遇
bool bfs(queue<Node> &q, int myvis[N][N], int othervis[N][N], int time){
    int size = q.size();
    while(size--){
        Node cur = q.front(); q.pop();
        
        // 这里的检查是为了防止上一秒还在队列里的点，这一秒被鬼吃了
        if(!check_safe(cur.x, cur.y, time)) continue;

        for(int dir=0; dir<4; dir++){
            int nx = cur.x + ax[dir];
            int ny = cur.y + ay[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(mp[nx][ny]=='X') continue;
            
            // <<< 修改2：新走到的点必须安全，否则不能走进去
            if(!check_safe(nx, ny, time)) continue;
            
            if(myvis[nx][ny]) continue;
            
            // 只有当对方访问过，且该点当前是安全的（上面check_safe通过了），才算相遇
            if(othervis[nx][ny]) return true;

            myvis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        ghost.clear();
        memset(boyvis, 0, sizeof(boyvis));
        memset(girlvis, 0, sizeof(girlvis));
        cin >> n >> m;
        
        queue<Node> boyq;
        queue<Node> girlq;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> mp[i][j];
                if(mp[i][j]=='M'){
                    boyq.push({i,j});
                    boyvis[i][j]=1;
                }
                else if(mp[i][j]=='G'){
                    girlq.push({i,j});
                    girlvis[i][j]=1;
                }
                else if(mp[i][j]=='Z'){
                    ghost.push_back({i,j});
                }
            }
        }

        int time = 0;
        bool meet = false;
        
        // <<< 修改3：改成 ||，只要有人活着就能跑
        while(!boyq.empty() || !girlq.empty()){
            time++;
            
            // <<< 修改1：男孩每秒走 3 步
            for(int k=0; k<3; k++) {
                if(boyq.empty()) break; // 没路就别硬跑了
                if(bfs(boyq, boyvis, girlvis, time)) {
                    meet = true;
                    goto end_game; // 遇到就直接跳出所有循环
                }
            }
            
            // 女孩每秒走 1 步
            if(!girlq.empty()){
                if(bfs(girlq, girlvis, boyvis, time)){
                    meet = true;
                    goto end_game;
                }
            }
        }
        
        end_game:;
        if(meet){
            cout << time << "\n";
        } else {
            cout << "-1\n";
        }
    }
}