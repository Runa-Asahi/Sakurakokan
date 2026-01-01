# 题目：重排 t 使得 s 为子序列且字典序最小

## 题目描述（简要）
A. Needle in a Haystack

time limit per test: 2 seconds

memory limit per test: 256 megabytes

input: standard input

output: standard output
You got lucky to know the answer to all important questions in the world. This time, the answer is the string $s$, consisting of lowercase English letters only. You want to hide this string.

You have another string $t$ also consisting of lowercase English letters only. You need to shuffle the letters in $t$ so that the string $s$ appears at least once in $t$ as a subsequence$^{\text{∗}}$. Among all possible reorderings of $t$ containing $s$ as a subsequence, find the lexicographically smallest$^{\text{†}}$ one.

$^{\text{∗}}$A sequence $a$ is a subsequence of a sequence $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) element from arbitrary positions.

$^{\text{†}}$A string $a$ is lexicographically smaller than string $b$ if and only if one of the following holds:

-   $a$ is a prefix of $b$, but $a \ne b$; or
-   in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
-   **Input**

Each test contains multiple test cases. The first line contains the number of test cases $T$ ($1 \le T \le 10^4$). The description of the test cases follows.

The first line of each test case contains the string $s$ ($1 \le |s| \le 10^5$), where $|s|$ is the length of the string $s$.

The second line of each test case contains the string $t$ ($|s| \le |t| \le 10^5$).

Both strings consist of lowercase English letters only.

The sum of $|t|$ over all test cases does not exceed $10^5$.
**Output**

For each test case, print a single string: the lexicographically smallest reordering of letters in the string $t$ that contains $s$ as a subsequence. If no such string exists, print "Impossible" instead.

## 我的一开始的想法 / 初版代码
```
#include <bits/stdc++.h>
using namespace std;
string s,t,irr;
unordered_map<char,int> mp;
int main(){
    int T; cin >> T;//number of test cases
    while(T--){
        cin >> s >> t;
        mp.clear();
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        for(int i=0;i<t.size();i++){
            if(mp[t[i]]!=0){
                mp[t[i]]--;
            }else{
                irr+=t[i];
            }
        }
        if(irr.size()==0){
            cout << s << "\n";
            continue;
        }
        sort(irr.begin(),irr.end());
        for(int i=0;i<s.size();i++){
            int left = 0, right = irr.size()-1;
            while(left+1<right){
                int mid = left+(right-left)/2;
                if(irr[mid]>=s[i]){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            if(irr[left]<s[i] && irr[right]<s[i]){
                irr.insert(irr.begin()+right,s[i]);
                continue;
            }else if(irr[left]<s[i] && irr[right]>=s[i]){
                irr.insert(irr.begin()+left,s[i]);
                continue;
            }else if(irr[left]>=s[i]){
                irr.insert(irr.begin(),s[i]);
                continue;
            }
        }
        cout<<irr<<'\n';
        irr.clear();
    }
}
```
## 出错情况（WA）与反例
- 我在某些测试点得到 WA（例如：Flight 1 WA1）。
- 一个最小反例：
  - s = `ac`
  - t = `aac`
- 期望输出（正确）： `aac`
- 我的程序输出： `aca`

### 手工跟踪说明
- 我在最后的二分插入的时候打乱了原有s的数据
于是我想改成将irr插入s，这样就可以保持原有的顺序不变
然而这样因为s是无序的所以就没办法使用二分插入了，整个架构需要重写

## 错误根源分析
- 将问题视为“在排序后的剩余字符中逐个插入 s 的字符以局部贪心”会漏掉全局决策，尤其是与 s 中字符相等的剩余字符放在 s 前/后的选择。
- 局部插入会产生互相影响（后插入的 s 的字符可能插到先插入字符之前），破坏 s 的原序或导致非最优字典序。

## 正确解法（两种常见方法）
1. 方法 A（简单，两候选比较）——思路与代码
```cpp
#include <bits/stdc++.h>
using namespace std;

// 方法 A：构造两个候选并比较
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int cnts[26] = {0}, cntt[26] = {0};
        for (char c : s) cnts[c - 'a']++;
        for (char c : t) cntt[c - 'a']++;
        // 可行性检查
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (cnts[i] > cntt[i]) { ok = false; break; }
        }
        if (!ok) {
            cout << "Impossible\n";
            continue;
        }
        // 扣除 s 使用的字母，得到剩余字母的频次
        for (int i = 0; i < 26; ++i) cntt[i] -= cnts[i];

        // 构造小于 s[0]，等于 s[0]，大于 s[0] 的三个部分（按字母顺序）
        string lessPart, equalPart, greaterPart;
        char first = s[0];
        for (int i = 0; i < 26; ++i) {
            string add(cntt[i], char('a' + i));
            if (i < first - 'a') lessPart += add;
            else if (i == first - 'a') equalPart += add;
            else greaterPart += add;
        }

        // 两种放置等号部分的方案，取较小的字典序
        string cand1 = lessPart + s + equalPart + greaterPart; // s 放在 equal 之前
        string cand2 = lessPart + equalPart + s + greaterPart; // s 放在 equal 之后
        cout << min(cand1, cand2) << '\n';
    }
    return 0;
}
```
时间复杂度：O(|t| + 26)

2. 方法 B（可行性检查的逐位贪心）——思路概述
- 逐位尝试放最小字母，放前检查放掉该字母后剩余字符是否仍然能够满足 s 的剩余需求（可用后缀计数 sum 来验证）。

## 我的最终代码（可运行）
//方法 B：逐位贪心 + 可行性检查（用 s 的后缀需求 sum）
``` cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        int cnts[26] = {0}, cntt[26] = {0};
        for (char c : s) cnts[c - 'a']++;
        for (char c : t) cntt[c - 'a']++;
        // 可行性检查：t 必须至少覆盖 s
        bool ok = true;
        for (int i = 0; i < 26; ++i) if (cnts[i] > cntt[i]) { ok = false; break; }
        if (!ok) {
            cout << "Impossible\n";
            continue;
        }

        // 计算 s 的后缀需求 sum[pos][c]:
        // sum[pos][c] = s 中从位置 pos 到末尾包含 c 的个数
        vector<array<int,26>> sum(n+1);
        for (int c = 0; c < 26; ++c) sum[n][c] = 0;
        for (int pos = n - 1; pos >= 0; --pos) {
            for (int c = 0; c < 26; ++c) sum[pos][c] = sum[pos + 1][c];
            sum[pos][s[pos] - 'a']++;
        }

        string ans;
        int pos = 0; // s 中已经匹配的前缀长度（即下一个要匹配的是 s[pos]）
        // 逐步填满 ans，共填 m 个字符
        for (int step = 0; step < m; ++step) {
            // 尝试从 'a' 到 'z' 找第一个可行字母
            for (int c = 0; c < 26; ++c) {
                if (cntt[c] == 0) continue; // 没有这种字母可放
                int npos = pos;
                if (pos < n && c == (s[pos] - 'a')) npos = pos + 1;
                // 验证：放掉一个 c 之后，对所有字母 i，剩余 cntt[i] - (i==c?1:0) 要 >= sum[npos][i]
                bool feasible = true;
                for (int i = 0; i < 26; ++i) {
                    int left_after = cntt[i] - (i == c ? 1 : 0);
                    int need = (npos <= n ? sum[npos][i] : 0);
                    if (left_after < need) { feasible = false; break; }
                }
                if (feasible) {
                    // 可以放 c
                    ans.push_back(char('a' + c));
                    cntt[c]--;
                    pos = npos;
                    break; // step 完成，进行下一个位置
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
```
## 总结与心得
- 用固定大小的数组（26）统计字符频次，复杂度低、常用且高效
- 从左到右逐位构造答案，每次选择当前看起来“最优”的选项（这里是字典序最小的字符）,
但“贪心”必须带上可行性验证（见下一点），否则局部最优不保证全局最优
- 每次做贪心选择前，验证该选择放弃后是否还能完成全局目标（left_after >= need）。
这是一个非常通用的模板：在可撤销代价高的选择问题里，优先选但先判可行性。
类似场景：安排任务、资源分配、拼接子序列、构造合法括号序列等。
- 后缀需求数组 / 预处理 
  把“未来的需要”预先计算出来（后缀频次），能在 O(1) 或 O(26) 时间内判断某一步是否可行。
通用技巧：想知道“从这里到结尾还需要什么”，就做后缀统计或后缀 DP。
- 把问题转成“状态 + 转移 + 验证”