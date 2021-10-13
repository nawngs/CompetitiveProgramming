#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, k, a[5005], b[5005], s1 = 0, s2 = 0, dp[5005][5005][5];

int main() {
	fastflow;
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];

	FOR(i, 0, n)
		FOR(j, 1, k)
			FOR(p, 0, 2) dp[i][j][p] = -INF;
	
	dp[0][0][0] = 0;
	FOR(i, 1, n) {
		FOR(j, 1, k) {
			dp[i][j][0] = max(dp[i - 1][j][1], max(dp[i - 1][j][2], dp[i - 1][j][0]));
			dp[i][j][1] = max(dp[i - 1][j - 1][1] + a[i], dp[i - 1][j - 1][0] + a[i]);
			dp[i][j][2] = max(dp[i - 1][j - 1][2] + b[i], dp[i - 1][j - 1][0] + b[i]);
		}
	}
	cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2]));
}
