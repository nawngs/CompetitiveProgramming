#include <bits/stdc++.h>

#define name "putnik"
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, d[1503][1503], dp[1503][1503];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
			dp[i][j] = INF;
		}
	dp[1][1] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d[i][i + 1]);
			dp[i][i + 1] = min(dp[i][i + 1], dp[i][j] + d[j][i + 1]);
			dp[j][i + 1] = min(dp[j][i + 1], dp[j][i] + d[i][i + 1]);
			dp[i + 1][i] = min(dp[i + 1][i], dp[j][i] + d[j][i + 1]);	
		}
	int res = INF;
	for (int i = 1; i <= n; i++) res = min({res, dp[i][n], dp[n][i]});
	cout << res;
}