#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, a[3005], s[3005], dp[3005][3005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dp[i][j] = a[i];
			else dp[i][j] = -INF;
		}
	}
	for (int k = 2; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			dp[i][j] = (s[j] - s[i - 1]) - min(dp[i + 1][j], dp[i][j - 1]);
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	cout << dp[1][n] * 2 - s[n];
}
