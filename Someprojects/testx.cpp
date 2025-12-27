#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> filtered;
    filtered.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= 150) {
            filtered.push_back(x);
        }
    }
    int m = filtered.size();
    if (m == 0) {
        cout << 0;
        return 0;
    }
    int result = 1;
    int lastSign = 0;  
    for (int i = 1; i < m; i++) {
        int diff = filtered[i] - filtered[i-1];
        if (diff > 0 && lastSign <= 0) {
            result++;
            lastSign = 1;
        } else if (diff < 0 && lastSign >= 0) {
            result++;
            lastSign = -1;
        }
    }
    cout << result;
    return 0;
}
