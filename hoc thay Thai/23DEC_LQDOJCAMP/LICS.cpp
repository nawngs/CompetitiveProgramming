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
const int N = 100;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[N + 3], b[N + 3], dp[N + 3][N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	a[0] = b[0] = -INF;
	int res = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (a[i] != b[j]) {
			dp[i][j] = -INF;
			continue;
		}
		for (int ii = 0; ii < i; ii++)
		for (int jj = 0; jj < j; jj++) if (a[i] > a[ii]) dp[i][j] = max(dp[i][j], dp[ii][jj] + 1);
		// cout << i << " " << j << " " << dp[i][j] << '\n';
		res = max(res, dp[i][j]);
	}
	cout << res;
}