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
		for (int j = 0; j <= 1e5; j++) dp[i][j] = INF;
	dp[0][0] = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 1e5; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j < a[i].se) continue;
			else {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i].se] + a[i].fi);
			}
			if (dp[i][j] <= w) ans = max(ans, 1ll * j);
		}
	}
	cout << ans;
}
