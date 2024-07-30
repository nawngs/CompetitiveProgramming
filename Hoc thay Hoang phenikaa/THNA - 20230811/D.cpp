//[FINISHED]
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

ll n, m, dp[103][103][10003], a[103], S;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> S;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	for (int k = 0; k <= n * n; k++) dp[i][j][k] = -LINF;
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][i][0] = dp[i - 1][i - 1][0] + a[i];
	}
	for (int i = 1; i <= m; i++) 
	for (int j = i; j <= n; j++) 
	for (int k = 0; k <= NMAX; k++) {
		dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
		if (k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
		if (k >= j - i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - (j - i)] + a[j]);
		//cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
	}
	for (int k = 0; k <= NMAX; k++) {
		for (int j = m; j <= n; j++) {
			if (dp[m][j][k] >= S) {
				cout << k << '\n';
				return 0;
			}
		}
	}
	cout << -1;
}