#include <bits/stdc++.h>
using namespace std;

int n, m;
int mp[22][22];
int vis[22];
int maxroad = 0;

// u: 当前所在的点
// len:以此路径走到当前积攒的长度
void dfs(int u, int len) {
    // 每次走到一个新点，都尝试更新最大值
    if (len > maxroad) {
        maxroad = len;
    }

    // 尝试走向下一个点 v
    for (int v = 1; v <= n; v++) {
        // 如果 u 和 v 之间有路，且 v 没有走过
        if(mp[u][v]!=0 && vis[v]==0) {
            vis[v] = 1; // 标记 v 为已访问
            dfs(v, len + mp[u][v]); // 继续从 v 出发，累加路径长度
            vis[v] = 0; // 回溯，标记 v 为未访问
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, len;
        cin >> x >> y >> len;
        mp[x][y] = len;
        mp[y][x] = len; // 无向图，双向都要存
    }

    // 题目说可以在“任意一个观景点出发”
    // 所以我们需要枚举每一个点作为起点
    for (int i = 1; i <= n; i++) {
        vis[i] = 1; // 把起点标记为已访问
        dfs(i, 0);  // 从 i 出发，初始长度为 0
        vis[i] = 0; // 回溯（虽然对于起点来说，这一步其实不影响结果，但为了严谨）
    }

    cout << maxroad << endl;
    return 0;
}