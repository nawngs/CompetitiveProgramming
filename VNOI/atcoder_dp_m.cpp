#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, k, a[105], dp[105][100005], s[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	s[0] = 1;
	for (int i = 1; i <= k; i++) s[i] += s[i - 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j <= a[i]) dp[i][j] = s[j];
			else dp[i][j] = s[j] - s[j - a[i] - 1];
			dp[i][j] = (dp[i][j] + MOD) % MOD;
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
		s[0] = dp[i][0];
		for (int j = 1; j <= k; j++) s[j] = (dp[i][j] + s[j - 1]) % MOD;
	}
	cout << dp[n][k];
}
