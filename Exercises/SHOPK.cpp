#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18;

long long n, k, dp[10005][5005], ans = -INF, a[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SHOPK.inp", "r", stdin);
	freopen("SHOPK.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= min(1ll * i / 2, k); j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
			if (j <= i / 2 && j <= k) ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}