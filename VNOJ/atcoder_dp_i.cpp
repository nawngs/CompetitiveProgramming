#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >
#define ld long double

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

int n;
ld a[3005], dp[3005][3005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	cout << fixed;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	ld ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] += dp[i - 1][j - 1] * a[i];
			dp[i][j] += dp[i - 1][j] * (1 - a[i]);
			if (i == n && j >= (n + 1) / 2) ans += dp[i][j];
		}
	}
	cout << setprecision(10) << ans;
}
