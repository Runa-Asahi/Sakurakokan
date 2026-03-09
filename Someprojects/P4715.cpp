#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义结构体，同时保存能力值和原始编号
struct Country {
    int id;     // 国家编号 (1 ~ 2^n)
    int power;  // 能力值
};

int main() {
    // 加速输入输出
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    int total_count = 1 << n; // 计算总人数 2^n
    
    vector<Country> players(total_count);

    // 读取 2^n 个能力值，并赋予对应的编号
    for (int i = 0; i < total_count; ++i) {
        players[i].id = i + 1;      // 编号从 1 开始
        cin >> players[i].power;    // 读入能力值
    }

    // 模拟淘汰赛，直到只剩 1 人（冠军）
    while (players.size() > 1) {
        vector<Country> next_round;
        
        // 两两比赛
        for (size_t i = 0; i < players.size(); i += 2) {
            Country &p1 = players[i];
            Country &p2 = players[i+1];
            
            // 如果是最后一场（决赛），直接判断亚军
            if (players.size() == 2) {
                if (p1.power > p2.power) {
                    // p1 胜，p2 是亚军
                    cout << p2.id << endl;
                } else {
                    // p2 胜，p1 是亚军
                    cout << p1.id << endl;
                }
                return 0; // 找到答案后直接结束程序
            }
            
            // 普通轮次，胜者晋级
            if (p1.power > p2.power) {
                next_round.push_back(p1);
            } else {
                next_round.push_back(p2);
            }
        }
        
        // 更新列表为下一轮的选手
        players = next_round;
    }

    return 0;
}