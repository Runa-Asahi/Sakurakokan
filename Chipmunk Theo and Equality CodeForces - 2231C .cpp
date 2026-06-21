#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> a;
        unordered_map<int, int> cnt;
        unordered_set<int> path;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            unordered_set<int> seen;
            if (i == 1)
            {
                int num;
                cin >> num;
                int step = 0;
                while (!seen.count(num))
                {
                    path.insert(num);
                    seen.insert(num);
                    cnt[num]++;
                    if (a.find(num) != a.end() && a[num] < step + a[num])
                    {
                        a[num] = step + a[num];
                    }
                    else if (a.find(num) == a.end())
                    {
                        a[num] = step + a[num];
                        // cout<<"num: "<<num<<'\n';
                        // cout<<"step: "<<step<<'\n';
                    }
                    step++;
                    if (num & 1 == 1)
                        num++;
                    else
                        num /= 2;
                }
                continue;
            }
            int num;
            cin >> num;
            int step = 0;
            while (!seen.count(num))
            {
                if(path.find(num)==path.end()) {
                    step++;
                if (num & 1 == 1)
                    num++;
                else
                    num /= 2;
                    continue;
                }
                seen.insert(num);
                cnt[num]++;
                if (a.find(num) != a.end() && a[num] < step + a[num])
                {
                    a[num] = step + a[num];
                }
                else if (a.find(num) == a.end())
                {
                    a[num] = step + a[num];
                    // cout<<"num: "<<num<<'\n';
                    // cout<<"step: "<<step<<'\n';
                }
                step++;
                if (num & 1 == 1)
                    num++;
                else
                    num /= 2;
            }
        }
        int moptmin = INT_MAX;
        for (const auto &x : a)
        {
            if (cnt[x.first] == n)
            {
                // cout<<"x"<<" "<<x.first<<'\n';
                if (moptmin > x.second)
                {
                    moptmin = x.second;
                }
            }
        }
        cout << moptmin << '\n';
    }
}