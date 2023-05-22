#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se seond
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, m, dp[1005][1005];

char a[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> a[i][j];

	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j && i == 1) continue;
			if (a[i][j] == '#') continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= MOD;
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	cout << dp[n][m] << '\n';
}
