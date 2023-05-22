#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, w, dp[105][100005];

pll a[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

	for (int i = 0; i <= n; i++) 
		for (int j = 1; j <= w; j++) dp[i][j] = -INF;

	dp[0][0] = 0;

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			//dp[i][j] = dp[i - 1][j];
			if (j < a[i].fi) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].fi] + a[i].se);
			}
			ans = max(ans, dp[i][j]);
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	cout << ans;
}
