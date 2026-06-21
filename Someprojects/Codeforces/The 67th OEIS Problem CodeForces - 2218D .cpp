#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
bitset<N> is_prime;
vector<int> a(N, 0);

void sieve(int x) {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    int cnt = 1; // primes stored in a[1..cnt-1]
    for (int i = 2; i <= x; i++) {
        if (is_prime[i]) {
            a[cnt++] = i;
        }
        for (int j = 1; j < cnt; j++) {
            if (1LL * i * a[j] > x) break;
            is_prime[i * a[j]] = false;
            if (i % a[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; 
    cin >> t;
    sieve(120000);

    while (t--) {
        int n; 
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << 1LL * a[i] * a[i + 1] << " ";
        }
        cout << '\n';
    }
    return 0;
}