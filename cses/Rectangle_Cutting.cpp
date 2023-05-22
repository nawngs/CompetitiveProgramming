#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, dp[503][503];

void sol() {
	cin >> n >> m;
	if (n > m) swap(n, m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) dp[i][j] = MOD;
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k < i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
			for (int k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
		}
	}
	cout << dp[n][m] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
