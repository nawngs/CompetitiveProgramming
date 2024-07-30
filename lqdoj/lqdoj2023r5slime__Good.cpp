// dinhmanhhungwillwinioi2024
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	if (fopen("slime.inp", "r"))
		freopen("slime.inp", "r", stdin),
		freopen("slime.out", "w", stdout);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	int ans = 0;
	for (int msk = 1; msk < (1 << n); msk++) {
		map<int, int> cnt;
		for (int i = 0; i < n; i++)
			if (msk >> i & 1)
				++cnt[a[i]];
		int pre = 0;
		while (true) {
			auto it = cnt.upper_bound(pre);
			if (it == cnt.end()) break;
			if (it->first == s) {
				++ans;
				break;
			}
			if (it->second / 2 > 0)
				cnt[it->first * 2] += it->second / 2;
			pre = it->first;
		}
	}
	cout << ans;
	return 0;
}