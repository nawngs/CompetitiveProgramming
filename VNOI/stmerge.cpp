#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll m, n, a[1005][1005], dp[1005][1005][4];

void minimize (ll &a, ll b) {
	if (a > b) a = b;
}

void sol() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];		}
	}

	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++) 
			for (int k = 1; k <= 2; k++) dp[i][j][k] = 1e18;

	dp[1][0][1] = 0;
	dp[0][1][2] = 0;

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 1; k <= 2; k++) {
				if (k == 1) {
					minimize(dp[i + 1][j][1], dp[i][j][k]);
					minimize(dp[i][j + 1][2], dp[i][j][k] + a[i][j + 1]);
				}
				else {
					minimize(dp[i][j + 1][2], dp[i][j][k]);
					minimize(dp[i + 1][j][1], dp[i][j][k] + a[i + 1][j]);
				}
				//cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
			}
		}
	}
	cout << min(dp[m][n][1], dp[m][n][2]) << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t --) sol();
}