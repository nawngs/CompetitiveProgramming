#include <bits/stdc++.h>

#define name "pieaters"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

template < class X, class Y >
	bool maximize(X &x, const Y &y) {
		if (x < y) {
			x = y;
			return true;
		}
		return false;
	}

ll n, m, w[NMAX], l[NMAX], r[NMAX], mx[303][303][303], dp[303][303];

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> w[i] >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; j++) 
			maximize(mx[j][l[i]][r[i]], w[i]);
	}
	for (int i = 1; i <= n; i++) 
		for (int li = i; li >= 1; li--) 
			for (int ri = i; ri <= n; ri++) {
				if (li < i) maximize(mx[i][li][ri], mx[i][li + 1][ri]);
				if (ri > i) maximize(mx[i][li][ri], mx[i][li][ri - 1]);
			}
	for (int len = 1; len <= n; len++) 
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				if (k < j) maximize(dp[i][j], dp[i][k] + dp[k + 1][j]);
				maximize(dp[i][j], (k > i ? dp[i][k - 1] : 0) + mx[k][i][j] + (k < j ? dp[k + 1][j] : 0));
			}
		}
	cout << dp[1][n];
}