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

int n, x, dp[1003][100003];

pii a[1003];

void sol() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i].fi;
	for (int i = 1; i <= n; i++) cin >> a[i].se;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i].fi) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].fi] + a[i].se);
			if (i == n) ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
