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

ll n, m, dp[100003][102], a[100005];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (a[1] == 0) for (int i = 1; i <= m; i++) dp[1][i] = 1;
	else dp[1][a[1]] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] != 0) dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
		else 
			for (int j = 1; j <= m; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
		
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++) ans = (ans + dp[n][i]) % MOD;
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
