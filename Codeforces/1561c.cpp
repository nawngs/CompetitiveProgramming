#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int t, n;

void sol() {
	cin >> n;
	vector < pair < int, int > > f;
	f.clear();
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int maxa = 0;
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			maxa = max(maxa, x - j + 2);
		}
		f.push_back({maxa, k});
	}
	sort(f.begin(), f.end());
	int sumk = 0, ans = 0;
	for (int i = 0; i < f.size(); i++) {
		ans = max(ans, f[i].fi - sumk);
		sumk += f[i].se;
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while(t --) {
		sol();
	}
}