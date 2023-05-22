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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, x, y;

pii dp[2003][10003], a[2003];

void minimize(pii &x, pii y) {
	if (x.fi < y.fi) x = y;
	else if (x.fi == y.fi) x.se = max(x.se, y.se);
}

int main() {
	fast;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= y; j++) dp[i][j] = {-1, -1};
	dp[0][y] = {0, x};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= y; j++) {
			if (dp[i][j] == make_pair(-1, -1)) continue;
			int sub = dp[i][j].fi;
			int size_x = dp[i][j].se;
			minimize(dp[i + 1][j], make_pair(sub, size_x));
			if (j >= a[i + 1].se) minimize(dp[i + 1][j - a[i + 1].se], make_pair(sub + 1, size_x));
			if (size_x >= a[i + 1].fi) minimize(dp[i + 1][j], make_pair(sub + 1, size_x - a[i + 1].fi)); 
		}
	}
	int ans = 0;
	for (int j = 0; j <= y; j++) ans = max(ans, dp[n][j].fi);
	cout << ans;
}
