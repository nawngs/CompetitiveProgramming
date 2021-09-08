#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, c, k, f[100005];

pair < int, int > a[100005];

int main() {
	//cout << 2 / 0 << '\n';
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> c >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		if (a[i].se == 0) {
			if (a[i].fi >= k) f[i] = 0;
			else f[i] = 1e9 + 7;
			continue;
		}
		f[i] = (k - a[i].fi + a[i].se - 1) / a[i].se;
		f[i] = max(0, f[i]);
	}
	sort(f + 1, f + n + 1);
	f[n + 1] = 1e9 + 7;
	int s = 0;
	for (int i = 1; i <= n + 1; i++) {
		s += f[i];
		if (s > c) {
			cout << i - 1;
			return 0;
		}
	}
}