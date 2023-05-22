#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9 + 7;

int n, p, q, a[2002], dp[2002][2002][3];

bool check(int x) {
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= p; j ++) 
			for (int k = 0; k <= 2; k++) dp[i][j][k] = INF;

	dp[0][0][0] = 0;

	int pos1, pos2;
	pos1 = pos2 = 0;

	for (int i = 1; i <= n; i++) {
		while (pos1 < n && a[pos1 + 1] < a[i] - x + 1) pos1 ++;
		while (pos2 < n && a[pos2 + 1] < a[i] - 2 * x + 1) pos2 ++;
		for (int j = 0; j <= p; j++) {
			if (pos1 != n) dp[i][j][0] = min(dp[i][j][0], dp[pos1 + 1][j][1]);
			if (pos2 != n) dp[i][j][0] = min(dp[i][j][0], dp[pos2 + 1][j][2]);
			if (j > 0) dp[i][j][1] = min(dp[i - 1][j - 1][0], min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]));
			dp[i][j][2] = min(dp[i - 1][j][0], min(dp[i - 1][j][1], dp[i - 1][j][2])) + 1;
		}
	}
	for (int j = 0; j <= p; j++) {
		for (int k = 0; k <= 2; k++) {
			if (dp[n][j][k] <= q) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("watching.Inp", "r", stdin);
	freopen("watching.Out", "w", stdout);
	cin >> n >> p >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (p + q >= n) {
		cout << 1 << '\n';
		return 0;
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = 1e9, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}