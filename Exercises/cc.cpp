#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, a[3005], b[3005], dp[3005][3005];

int main() {
	slow;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 0; i <= 3000; i++) dp[0][i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= b[i]; j++) dp[i][j] += dp[i - 1][j];	
		
		for (int j = 1; j <= 3000; j++) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
	}
	cout << dp[n][b[n]];
}
