#include <bits/stdc++.h>
using namespace std;

// 核心逻辑函数
vector<int> findCommandPositions(string log, vector<string>& codes) {
    int n = codes.size();// 单词数量
    int wordLen = codes[0].size();// 每个单词长度
    int totalLen = wordLen * n;// 总长度
    int logLen = log.size();// 日志长度

    if (logLen < totalLen) return {};// 日志长度不足以包含所有单词

    unordered_map<string, int> targetFreq;// 目标单词频率
    for (string& word : codes) targetFreq[word]++;// 统计每个单词出现次数

    vector<int> result;
    
    // 不同偏移起点
    for (int i = 0; i < wordLen; i++) {
        int left = i, right = i;
        unordered_map<string, int> windowFreq;
        int count = 0;

        while (right + wordLen <= logLen) {
            string word = log.substr(right, wordLen);
            right += wordLen;

            if (targetFreq.count(word)) {
                windowFreq[word]++;
                count++;

                // 若某个词出现次数超了，收缩窗口
                while (windowFreq[word] > targetFreq[word]) {
                    string leftWord = log.substr(left, wordLen);
                    windowFreq[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // 如果刚好匹配所有单词
                if (count == n) {
                    result.push_back(left);
                }
            } else {
                // 清空窗口
                windowFreq.clear();
                count = 0;
                left = right;
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string log;
    getline(cin, log);
    int n;
    cin >> n;
    vector<string> codes(n);
    for (int i = 0; i < n; i++) {
        cin >> codes[i];
    }

    vector<int> positions = findCommandPositions(log, codes);

    if (positions.empty()) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < positions.size(); i++) {
            if (i > 0) cout << " ";
            cout << positions[i];
        }
        cout << "\n";
    }

    return 0;
}
