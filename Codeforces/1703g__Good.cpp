
// Author: QuangBuiCP
// Editor: GVim
#include <bits/stdc++.h>
using namespace std;
 
 
signed main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i + 1];
		}
		int64_t ans = 0, sum = 0;
		for (int i = 0; i <= n; ++i) {
			int64_t s = 0, d = 2;
			for (int j = i + 1; j <= min(n, i + 32); ++j, d *= 2) {
				s += a[j] / d;
			}
			sum += a[i];
			ans = max(ans, sum + s - 1LL * i * k);
		}
		cout << ans << '\n';
	}
 
	return 0;
}