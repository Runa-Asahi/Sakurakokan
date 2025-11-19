#include <bits/stdc++.h>
using namespace std;

// bits 1..9 used: bit (1<<d) means digit d is present
int rowMask[9], colMask[9], boxMask[9];
vector<pair<int,int>> empties;
int board[9][9];

inline int boxIndex(int x, int y){ return (x/3)*3 + (y/3); }

// 检查初始输入是否有冲突
bool validate_initial(){
    memset(rowMask,0,sizeof(rowMask));
    memset(colMask,0,sizeof(colMask));
    memset(boxMask,0,sizeof(boxMask));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int v = board[i][j];
            if(v==0) continue;
            int bit = 1<<v;
            int b = boxIndex(i,j);
            if((rowMask[i] & bit) || (colMask[j] & bit) || (boxMask[b] & bit)) return false;
            rowMask[i] |= bit;
            colMask[j] |= bit;
            boxMask[b] |= bit;
        }
    }
    return true;
}

// MRV + bitmasks backtracking
bool solve(){
    if(empties.empty()) return true;
    // choose empty cell with minimal candidates
    int bestIdx = -1, bestCount = 10, bestAvail = 0;
    for(int i=0;i<(int)empties.size();++i){
        int x = empties[i].first, y = empties[i].second;
        int used = rowMask[x] | colMask[y] | boxMask[boxIndex(x,y)];
        int avail = (~used) & 0x3FE; // bits 1..9
        if(avail == 0) return false; // dead end
        int cnt = __builtin_popcount(avail);
        if(cnt < bestCount){
            bestCount = cnt;
            bestIdx = i;
            bestAvail = avail;
            if(cnt == 1) break; // can't get better
        }
    }

    // take best cell out of empties (swap-pop)
    auto [x,y] = empties[bestIdx];
    swap(empties[bestIdx], empties.back());
    empties.pop_back();

    int b = boxIndex(x,y);
    // enumerate candidate digits using bit trick
    for(int bits = bestAvail; bits; bits &= bits-1){
        int bit = bits & -bits;
        int d = __builtin_ctz(bit); // digit d (1..9)
        // place d
        board[x][y] = d;
        rowMask[x] |= bit;
        colMask[y] |= bit;
        boxMask[b] |= bit;

        if(solve()) return true;

        // backtrack
        board[x][y] = 0;
        rowMask[x] &= ~bit;
        colMask[y] &= ~bit;
        boxMask[b] &= ~bit;
    }

    // restore empties
    empties.push_back({x,y});
    swap(empties[bestIdx], empties.back()); // restore original order (not strictly necessary)
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read 9x9, 0 for empty
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(!(cin>>board[i][j])) return 0;
        }
    }

    // collect empties
    empties.clear();
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) if(board[i][j]==0) empties.emplace_back(i,j);

    if(!validate_initial()){
        cout << "无解\n";
        return 0;
    }

    bool ok = solve();
    if(!ok){
        cout << "无解\n";
        return 0;
    }

    // output
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] << (j<8 ? ' ' : '\n');
        }
    }
    return 0;
}