#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long w, h, d;
    long long n;
    if (!(cin >> w >> h >> d)) return 0;
    cin >> n;

    auto get_divisors = [&](long long x) {
        vector<long long> v;
        for (long long i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                v.push_back(i);
                if (i * i != x) v.push_back(x / i);
            }
        }
        sort(v.begin(), v.end());
        return v;
    };

    vector<long long> vw = get_divisors(w);
    vector<long long> vh = get_divisors(h);
    vector<long long> vd = get_divisors(d);

    for (long long pw : vw) {
        if (n % pw != 0) continue;
        long long tmp = n / pw;
        for (long long ph : vh) {
            if (tmp % ph != 0) continue;
            long long pd = tmp / ph;
            if (binary_search(vd.begin(), vd.end(), pd)) {
                cout << (pw - 1) << " " << (ph - 1) << " " << (pd - 1) << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}