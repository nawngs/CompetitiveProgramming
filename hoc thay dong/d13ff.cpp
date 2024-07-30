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
const int NMAX = 1e4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[NMAX + 3], dp[2][103][103], m;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= 1; i++) 
	for (int j = 0; j <= m; j++)
	for (int jj = 0; jj <= m; jj++) dp[i][j][jj] = LINF;
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		for (int jj = 0; jj <= j; jj++) dp[(i + 1) & 1][j][jj] = LINF;
		for (int j = 0; j < m; j++) 
		for (int jj = 0; jj <= j; jj++) if (dp[i & 1][j][jj] != LINF) {
			dp[(i + 1) & 1][j + 1][jj + 1] = min(dp[(i + 1) & 1][j + 1][jj + 1], dp[i & 1][j][jj]);
			dp[(i + 1) & 1][jj + 1][0] = min(dp[(i + 1) & 1][jj + 1][0], dp[i & 1][j][jj] + a[i + 1]);
		}
	}
	ll res = LINF;
	for (int j = 0; j < m; j++)
	for (int jj = 0; jj < j; jj++) res = min(res, dp[n & 1][j][jj]);
	cout << res;
}