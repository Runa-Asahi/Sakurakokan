#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
bool st[20]; //用于记录数字 i 是否已经被放进去了 (state)

void dfs(int index, int n){
    // 边界条件：已经选够了 n 个数
    if(index == n + 1){
        for(size_t i = 0; i < arr.size(); i++){
            // setw(5) 设置场宽为 5，默认右对齐
            cout << setw(5) << arr[i];
        }
        cout << '\n'; // 输出完一整行后再换行
        return;
    }

    for(int i = 1; i <= n; i++){
        // 如果数字 i 还没有被使用
        if(!st[i]){
            arr.push_back(i); // 放入
            st[i] = true;     // 标记为已使用
            
            dfs(index + 1, n); // 递归
            
            // 回溯（恢复现场）
            st[i] = false;    // 取消标记
            arr.pop_back();   // 弹出
        }
    }
}

int main(){
    int n;
    cin >> n;
    dfs(1, n);
    return 0;
}