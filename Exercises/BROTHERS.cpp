#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "brothers";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, dp[203][203][203], a[203][203];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= n; k++) dp[i][j][k] = -INF;
	dp[1][1][1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= n; k++) {
				int p = i + j - k;
				if (p <= j) continue;
				if (p > m) continue;
				dp[i][j][k] = max(dp[i][j - 1][k], max(dp[i][j - 1][k - 1], max(dp[i - 1][j][k - 1], dp[i - 1][j][k]))) + a[i][j] + a[k][p];
				//cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
			}
		}
	}
	cout << dp[n][m - 1][n - 1];
		
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
