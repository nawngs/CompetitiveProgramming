// [UNFINISHED]
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k;

ll dp[503][503], sum[503];

pll a[503];

void maximize(ll &x, ll y) {
	if (x < y) x = y;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		sum[i] = sum[i - 1] + a[i].fi + a[i].se;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++) dp[i][j] = -LINF;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		ll s = a[i + 1].fi + a[i + 1].se;
		for (int b = 0; b < k; b++) {
			if (dp[i][b] == -LINF) continue;
			int r = (sum[i] - b) % k;
			//cout << i << " " << b << " " << r << " " << dp[i][b] << '\n';
			ll val = dp[i][b] + s / k;
			for (int addb = 0; addb <= min(s % k, a[i + 1].fi); addb++) {
				int addr = (s % k) - addb;
				if (addr > a[i + 1].se) continue;
				if (addr + addb )
				//cout << addb << " " << addr << " " << chg << '\n';
				maximize(dp[i + 1][(b + addb) % k], val + chg);
			} 
		}
	}
	ll res = 0;
	for (ll b = 0; b < k; b++) {
		ll r = (sum[n] - b) % k;
			res = max(res, dp[n][b]);
		}
	cout << res;
}