#include <bits/stdc++.h>

#define name "slime"
#define int ll
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

int n, s, a[NMAX + 3], dp[2003][5003], dem = 0, cnt[13];

ll fac[NMAX + 3], inv[NMAX + 3];

vector < int > compress, pos;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (fac[n] * ((inv[k] * inv[n - k]) % MOD)) % MOD;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s;
	// bool th = 1;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		fac[i] = (fac[i - 1] * i) % MOD;
		// th &= (a[i] == a[1]);
	}
	for (int i = 0; i <= n; i++) inv[i] = mu(fac[i], MOD - 2);
	// if (th) {
		// int dem = 1, x = a[1];
		// while (x < s) {
			// x *= 2;
			// dem *= 2;
		// }
		// if (x != s) {
			// cout << 0 << '\n';
			// return 0;
		// }
		// fac[0] = 1;
		// for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
		// ll res = 0;
		// for (int i = dem; i <= n; i++) res = (res + C(i, n)) % MOD;
		// cout << res << '\n';
		// return 0;
	// }
	int x = s;
	compress.pb(x);
	while (x % 2 == 0) {
		x /= 2;
		compress.pb(x);
	}
	compress.pb(-1);
	reverse(compress.begin(), compress.end());
	ll val = 1;
	for (int i = 1; i <= n; i++) {
		auto it = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin();
		if (compress[it] != a[i]) val = (val * 2) % MOD;
		else cnt[it] ++;
	}
	dp[0][0] = 1;
	int m = compress.size() - 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= s; j++) if (dp[i][j] != 0) {
			int newj = j;
			ll rem = mu(2, cnt[i + 1]);
			for (int p = 0; p <= cnt[i + 1]; p++) {
				dp[i + 1][newj] = (dp[i + 1][newj] + C(p, cnt[i + 1]) * dp[i][j]) % MOD;
				rem = (rem - C(p, cnt[i + 1]) + MOD) % MOD;
				newj += compress[i + 1];
				if (newj > s) break;
			}
			dp[i + 1][s] = (dp[i + 1][s] + dp[i][j] * rem) % MOD;
		}
	}
	cout << (dp[m][s] * val) % MOD;
}
