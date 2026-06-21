#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        int n = x + y;
        
        // 可行性判断
        if (x > y || (x == 0 && n % 2 == 0)) {
            cout << "NO\n";
            continue;
        }
        
        cout << "YES\n";
        
        if (x == 0) {
            // 所有节点都是奇数，构造星形（根1连所有其他节点）
            for (int i = 2; i <= n; ++i) cout << 1 << ' ' << i << '\n';
        } else {
            int mm = 2 * x;  // 链长
            // 输出链 1-2-3-...-mm
            for (int i = 2; i <= mm; ++i) cout << i-1 << ' ' << i << '\n';
            // 剩余节点挂在 mm 上
            for (int i = mm + 1; i <= n; ++i) cout << mm << ' ' << i << '\n';
        }
    }
    return 0;
}