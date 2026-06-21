#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, w;
        cin >> n >> w;

        if (w == 1) {
            cout << 0 << '\n';
        } else {
            cout << n - n / w << '\n';  // 核心公式
        }
    }
    return 0;
}