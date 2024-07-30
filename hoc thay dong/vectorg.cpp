// [+] dinhmanhhungwillwinioi2024
#include <bits/stdc++.h>
using namespace std;

int n, m, a[1003][22], pos[1003];

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
		sort(a[i] + 1, a[i] + m + 1);
	}
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	sort(p.begin(), p.end(), [&] (int x, int y) {
		for (int i = 1; i <= m; i++)
			if (a[x][i] != a[y][i])
				return a[x][i] < a[y][i];
		return false;
	});
	int ans = 1;
	for (int i = 0; i < n; i++) {
		pos[p[i]] = 1;
		for (int j = 0; j < i; j++)
			if (([&] (int x, int y) -> bool {
				for (int i = 1; i <= m; i++)
					if (a[x][i] > a[y][i])
						return false;
				return true;
			}(p[j], p[i]))) 
				pos[p[i]] = max(pos[p[i]], pos[p[j]] + 1);
		ans = max(ans, pos[p[i]]);
	}
	cout << ans << '\n';
	for (int t = 1; t <= ans; t++) {
		vector<int> res;
		for (int i = 1; i <= n; i++)
			if (pos[i] == t)
				res.emplace_back(i);
		cout << res.size() << ' ';
		for (int x: res) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}