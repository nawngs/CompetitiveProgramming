#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, a[23][23], dp[23][(1 << 21)];

bool getbit(ll pos, ll x) {
	return (x & 1 << pos);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < n; j++) cin >> a[i][j];

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			if (dp[i][j] == 0) continue;
			//cout << i << " " << j << " " << dp[i][j] << '\n';
			for (int bit = 0; bit < n; bit ++) {
				if (a[i + 1][bit] && !getbit(bit, j)) {
					dp[i + 1][j + (1 << bit)] += dp[i][j];
					dp[i + 1][j + (1 << bit)] %= MOD;
				}
			}
		}
	}
	cout << dp[n][(1 << n) - 1];
}
