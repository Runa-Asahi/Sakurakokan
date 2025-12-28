#include <bits/stdc++.h>
using namespace std;

// 全局变量定义
int res = 0;
int sum = 0;
int n, m;

// 方向数组
int x[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
int y[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

// 声明全局 vector，但不设大小
vector<vector<int>> current;
vector<vector<int>> vis;

void dfs(int rows, int cols) {
    // 1. 换行
    if (cols > m) {
        cols = 1;
        rows++;
    }
    // 2. 终点：所有行都看完了
    if (rows > n) {
        res = max(res, sum);
        return;
    }

    // --- 分支 1：不选 ---
    dfs(rows, cols + 1);

    // --- 分支 2：选 ---
    // 只有没被封锁才能选
    if (!vis[rows][cols]) {
        // A. 标记自己和邻居
        vis[rows][cols]++; 
        for (int i = 1; i <= 8; i++) {
            int nx = rows + x[i];
            int ny = cols + y[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                vis[nx][ny]++;
            }
        }

        sum += current[rows][cols];

        // B. 递归下一层
        dfs(rows, cols + 1);

        // C. 回溯：清理现场（顺序无所谓，反着操作就行）
        sum -= current[rows][cols];
        
        for (int i = 1; i <= 8; i++) {
            int nx = rows + x[i];
            int ny = cols + y[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                vis[nx][ny]--;
            }
        }
        vis[rows][cols]--;
    }
}

void solve() {
    cin >> n >> m;
    
    // 【关键修改】使用 assign 初始化
    // 既调整了大小适配当前的 n, m，又把所有值清零了
    // 大小开 n+2 是为了防止越界，稍微大一点没坏处
    current.assign(n + 2, vector<int>(m + 2, 0));
    vis.assign(n + 2, vector<int>(m + 2, 0));
    
    // 读入数据
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> current[i][j];
        }
    }

    // 重置结果
    res = 0;
    sum = 0;
    
    // 开始 DFS
    dfs(1, 1);
    
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}