#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int start, vector<int>& path) {
    // 当n为0时，找到一个分解，输出结果
    if (n == 0) {
        cout << path[0];
        for (int i = 1; i < path.size(); i++) {
            cout << "+" << path[i];
        }
        cout << endl;
        return;
    }
    
    // 从start开始尝试所有可能的数（不大于当前n）
    for (int i = start; i >= 1; i--) {
        // 如果当前数大于剩余值，跳过
        if (i > n) continue;
        
        // 将当前数加入路径
        path.push_back(i);
        
        // 递归分解剩余部分，下一个数不能大于当前数（保证不增）
        dfs(n - i, i, path);
        
        // 回溯，移除当前数
        path.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> path;
    
    // 从n-1开始，因为至少要有两个数相加
    for (int i = n - 1; i >= 1; i--) {
        path.push_back(i);
        dfs(n - i, i, path);
        path.pop_back();
    }
    
    return 0;
}