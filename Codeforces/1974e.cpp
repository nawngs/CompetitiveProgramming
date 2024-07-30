#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 50;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const ll HMAX = 1E3;

ll m, x, dp[N + 3][N * HMAX + 3];

pll a[N + 3];

void sol() {
	cin >> m >> x;
	int s = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].fi >> a[i].se;
		s += a[i].se;
	}
	
	for (int i = 1; i <= m + 1; i++)
	for (int j = 0; j <= s; j++) dp[i][j] = -LINF;
	
	int res = 0;
	s = 0;
	dp[1][0] = 0;
	for (int i = 1; i <= m; i++) {
		s += a[i].se;
		for (int j = s; j >= 0; j--) {
			if (j >= a[i].se && dp[i][j - a[i].se] >= a[i].fi) 
				dp[i][j] = max(dp[i][j], dp[i][j - a[i].se] - a[i].fi);
			if (dp[i][j] >= 0) res = max(res, j);
			if (i < m) dp[i + 1][j] = dp[i][j] + x;
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}