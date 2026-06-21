#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int t[N];          // 每艘船到达时间
int k[N];          // 每艘船乘客数
vector<int> p[N];  // 每艘船上的乘客国籍列表
int cnt[100005];   // 当前窗口内每个国籍的人数
int ans = 0;       // 当前窗口内不同国籍数量

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int front = 1;   // 当前窗口最旧船的编号
    
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> k[i];
        // 1. 添加第 i 艘船的乘客
        for (int j = 1; j <= k[i]; j++) {
            int x; cin >> x;
            p[i].push_back(x);
            if (cnt[x] == 0) ans++;   // 新国籍出现
            cnt[x]++;
        }
        
        // 2. 移出超时船只（窗口滑动）
        while (t[front] + 86400 <= t[i]) {
            // 删除第 front 艘船上的所有乘客
            for (int x : p[front]) {
                cnt[x]--;
                if (cnt[x] == 0) ans--;   // 该国籍在窗口内消失
            }
            front++;
        }
        
        // 3. 输出当前答案
        cout << ans << '\n';
    }
    return 0;
}