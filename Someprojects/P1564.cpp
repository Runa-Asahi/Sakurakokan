#include <bits/stdc++.h>
using namespace std;

int v[20010], prefix1[20010], prefix2[20010];
int memo[20010]; // memo[idx] = 从 idx 开始到 n 的最少房间数，-1 表示未计算
int res = INT_MAX; // 全局上界，用于剪枝
int tmp = 0;       // 当前已开的房间数（回溯路径上的计数）

bool check(int a,int b,int m){
    int cnt1 = prefix1[b] - prefix1[a-1];
    int cnt2 = prefix2[b] - prefix2[a-1];
    return (abs(cnt1 - cnt2) <= m || cnt1 == 0 || cnt2 == 0);
}

// 保持 void 风格，但实现正确的记忆化：
// - memo[idx] 存子问题最优值
// - 如果 memo[idx] 已有值，则直接用它更新全局 res（tmp + memo[idx]）并返回
void dfs(int idx,int n,int m){
    if(idx > n){
        // 叶子：所有人已分完，用当前 tmp 更新全局 res
        res = min(res, tmp);
        memo[idx] = 0; // 从 idx(>n)开始需要0间
        return;
    }

    if(memo[idx] != -1){
        // 子问题已经算过：直接用已知最优值和当前 tmp 更新全局答案
        if(memo[idx] < 1e8) // 避免把 INF 加进去误更新
            res = min(res, tmp + memo[idx]);
        return;
    }

    const int INF = 1e9;
    int best = INF;

    for(int i = idx; i <= n; ++i){
        if(check(idx, i, m)){
            tmp++;                      // 选择当前区间 [idx,i]，开一个房间

            // 剪枝：如果当前 tmp 已不可能优于全局上界，则回溯
            if(tmp >= res){
                tmp--;                  // 恢复状态后继续尝试下一个 i
                continue;
            }

            // 递归去算子问题（会在子问题内部把 memo[i+1] 写好）
            dfs(i + 1, n, m);

            // 子问题返回后，利用 memo[i+1] 来更新 best
            if(memo[i+1] != -1 && memo[i+1] < INF){
                best = min(best, 1 + memo[i+1]);
            }
            tmp--; // 回溯
        }
    }

    memo[idx] = best; // 记录子问题的最优值（可能为 INF，但在本题通常会有解）
    // 用新发现的 best 更新全局上界：当前路径上的 tmp 是调用时的 tmp
    if(best < INF) res = min(res, tmp + best);
    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        v[i]=x;
    }
    prefix1[0]=prefix2[0]=0;
    for(int i=1;i<=n;i++){
        prefix1[i] = prefix1[i-1] + (v[i]==1);
        prefix2[i] = prefix2[i-1] + (v[i]==2);
    }

    // 初始化 memo 为 -1，memo[n+1] 将在 dfs(n+1) 时写为0
    for(int i=0;i<20010;i++) memo[i] = -1;

    // 初始化上界 res：最坏情况每个人单独一间
    res = n;

    dfs(1, n, m);

    // 输出最终答案：res 与 memo[1] 理论上等价（若 memo[1] != INF）
    cout << res << '\n';
    return 0;
}