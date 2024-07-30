#include <bits/stdc++.h>

#define name "domine"
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
const ll LINF = 1E15;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, k, a[1004][4], dp[1004][(1 << 4)][2003];

void maximize(ll &x, const ll &y) {
	if (x < y) x = y;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) 
	for (int j = 0; j < m; j++) cin >> a[i][j];
	
	//int t; cin >> t; while (t --) sol();
	for (int i = 0; i <= n; i++) 
	for (int j = 0; j < (1 << m); j++)
	for (int p = 0; p <= k; p++) dp[i][j][p] = -LINF;
	dp[1][0][0] = 0;
	for (int i = 1; i <= n; i++) 
	for (int j = 0; j < (1 << m); j++) {
		ll cnt = 0, res = 0;
		for (int bit = 0; bit < m; bit++) if (!(j >> bit & 1)) cnt ++, res += a[i][bit] + a[i + 1][bit];
		for (int p = 0; p <= k; p++) if (dp[i][j][p] != -LINF) {
			for (int bit = 0; bit < m; bit++) if (!(j >> bit & 1)) 
				maximize(dp[i][j ^ (1 << bit)][p], dp[i][j][p]);
			for (int bit = 1; bit < m; bit++) if (!(j >> bit & 1) && !(j >> (bit - 1) & 1))
				maximize(dp[i][j ^ (1 << bit) ^ (1 << (bit - 1))][p + 1], dp[i][j][p] + a[i][bit] + a[i][bit - 1]);
			// if (i == 1 && j == 7) cout << cnt << " " << res << '\n';
			if (p + cnt <= k) maximize(dp[i + 1][((1 << m) - 1) ^ j][p + cnt], dp[i][j][p] + res);
		}
	}
	cout << dp[n][(1 << m) - 1][k];
}