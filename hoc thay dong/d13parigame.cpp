#include <bits/stdc++.h>

#define int long long

using namespace std;

int m, n, a[503][503], row[503][503], col[503][503], dp[503][503][2][2];

bool calc(int i, int j, bool type, bool val) {
	if (dp[i][j][type][val] != -1) return dp[i][j][type][val];
	if (i == 0 || j == 0) return 0;
	dp[i][j][type][val] = 0;
	bool nxtval = val;
	if (type) nxtval ^= (row[i][j] & 1);
	else nxtval ^= (col[j][i] & 1);
	int x = i, y = j;
	if (type) x --;
	else y --;
	if (!nxtval && !calc(x, y, 0, 0) && !calc(x, y, 1, 0)) {
		dp[i][j][type][val] = 1;
		return true;
	}
	dp[i][j][type][val] = calc(x, y, type, nxtval);
	return dp[i][j][type][val];
}

void solve() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			row[i][j] = row[i][j - 1] + a[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			col[i][j] = col[i][j - 1] + a[j][i];
	memset(dp, 255, sizeof(dp));
	if (calc(m, n, 1, 0) || calc(m, n, 0, 0)) cout << "TRUE" << '\n';
	else cout << "FALSE" << '\n';
}

signed main() {
	int t; cin >> t;
	while (t--) solve();
}