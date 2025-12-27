#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

void dfs(int n, int x, vector<string>& board) {
    if(x == n) {
        cnt++;
        return;
    }
    for(int y = 0; y < n; y++) {
        // 检查(x,y)是否可以放皇后
        bool valid = true;
        
        // 检查列
        for(int i = 0; i < x; i++) {
            if(board[i][y] == 'Q') valid = false;
        }
        // 检查左上对角线
        for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') valid = false;
        }
        // 检查右上对角线  
        for(int i = x-1, j = y+1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') valid = false;
        }
        
        if(valid) {
            board[x][y] = 'Q';  // 放置皇后
            dfs(n, x+1, board);
            board[x][y] = '.';  // 回溯
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));  // 创建n×n棋盘
    dfs(n, 0, board);
    cout << cnt;
    return 0;
}