#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
ll s[N], b[N];
int n;
ll ans = LONG_LONG_MAX;

void dfs(int idx, ll alls, ll allb, bool used) {
    if (idx > n) {
        if (used) ans = min(ans, abs(alls - allb));
        return;
    }
    // 不选
    dfs(idx + 1, alls, allb, used);
    // 选
    dfs(idx + 1, alls * s[idx], allb + b[idx], true);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> b[i];
    }
    dfs(1, 1, 0, false); // 酸度乘积初始为1
    cout << ans << '\n';
    return 0;
}