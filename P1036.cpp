#include <bits/stdc++.h>
using namespace std;

int arr[30];
int n, k;
int ans = 0;

bool isprime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}


void dfs(int start_index, int count, int current_sum) {
    // 1. 截止条件：如果已经选够了 k 个数
    if (count == k) {
        if (isprime(current_sum)) ans++;
        return;
    }

    // 2. 剪枝：如果剩下的数不够凑齐 k 个，可以直接返回（可选优化）
    // if (n - start_index + count < k) return;

    // 3. 遍历选择下一个数
    // 从 start_index 开始往后找，保证组合不重复（比如选了第1个，下一个只能选第2个及以后的）
    for (int i = start_index; i < n; i++) {
        dfs(i + 1, count + 1, current_sum + arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 从第 0 个位置开始找，当前选了 0 个，和为 0
    dfs(0, 0, 0);

    cout << ans << "\n";
    return 0;
}