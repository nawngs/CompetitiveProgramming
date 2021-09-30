#include <bits/stdc++.h>

#define fi first
#define se second
#define pii pair < int, int >

using namespace std;

int n, dp[305][605][605], x, y;

pii a[305];

int main() {
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= 600; j++)
			for (int k = 0; k <= 600; k++) dp[i][j][k] = 1e9;

	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 600; j++) {
			for (int k = 0; k <= 600; k++) {
				dp[i][j][k] = dp[i - 1][j][k];
				if (j >= a[i].fi && k >= a[i].se) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a[i].fi][k - a[i].se] + 1);
				//cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
			}
		}
	}
	int ans = 1e9;
	for (int i = x; i <= 600; i++) {
		for (int j = y; j <= 600; j++) {
			ans = min(ans, dp[n][i][j]);
		}
	}
	cout << (ans == 1e9 ? -1 : ans);
}

