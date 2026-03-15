#include <bits/stdc++.h>
using namespace std;

int n, k;

void dfs(int pastpairs, int last, int& cnt) {
    if (pastpairs == k) {
        cnt++;
        return;
    }
    for (int i = last + 1; i <= n; i++) {
        dfs(pastpairs + 1, i, cnt);
    }
}

int main() {
    cin >> n >> k;
    int cnt = 0;
    dfs(0, 0, cnt);
    cout << cnt << '\n';
    return 0;
}