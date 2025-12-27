#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10; // 注意 N 要开大一点，因为每个区间有两个端点，最多 2n 个点

// 存储原始的区间输入，方便离散化后重新调用
pair<ll, ll> lines[N]; 
vector<ll> point;
int diff[N]; // 差分数组，用来记录覆盖次数

// 二分查找，返回 0-based 下标
int get_id(ll x) {
    return lower_bound(point.begin(), point.end(), x) - point.begin();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
        point.push_back(lines[i].first);
        point.push_back(lines[i].second);
    }

    // 1. 排序去重 (得到所有关键点)
    sort(point.begin(), point.end());
    point.erase(unique(point.begin(), point.end()), point.end());

    // 2. 差分标记
    for (int i = 0; i < n; i++) {
        int L = get_id(lines[i].first);
        int R = get_id(lines[i].second);
        
        // 这里的含义是：覆盖了从第 L 个基础区间开始，一直到第 R-1 个基础区间
        diff[L]++;
        diff[R]--; 
    }

    ll ans = 0;
    int current_coverage = 0; // 当前覆盖层数

    // 3. 遍历所有“基础区间”
    // point.size() 个点，构成了 point.size() - 1 个段
    for (int i = 0; i < point.size() - 1; i++) {
        current_coverage += diff[i]; // 前缀和思想，计算当前段被覆盖了几次
        
        if (current_coverage > 0) {
            // 重点在这里：利用 point 里的“大数”计算真实长度
            ans += (point[i+1] - point[i]);
        }
    }

    cout << ans << endl;
    return 0;
}