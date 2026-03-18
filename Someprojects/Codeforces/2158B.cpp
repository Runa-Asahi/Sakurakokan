#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5+10;
int t, a[N], cnt[N];
signed main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= 2 * n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		int m = 0; // 出现奇数次的元素个数
		int s = 0; // 可贡献2的偶数次元素个数
		for (int i = 1; i <= 2 * n; i++) {
			if (cnt[i] == 0) continue;
			if (cnt[i] % 2 == 1) {
				m++;
			} else {
				// 当元素出现次数为2n且n为偶数时，无法双奇数分配
				if (cnt[i] == 2 * n && n % 2 == 0) {
					continue;
				}
				s++;
			}
		}
		long long ans;
		if (m > 0) {
			ans = m + 2 * s;
		} else {
			// 所有元素均为偶数次，需保证分配奇偶性与n一致
			if ((s % 2) == (n % 2)) {
				ans = 2 * s;
			} else {
				ans = 2 * (s - 1);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
