//[UNFINISHED]
#include <bits/stdc++.h>

#define name "lyson"
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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LOG = 20;

ll n, q, b[NMAX + 3], a[NMAX + 3], f[NMAX + 3][2], g[NMAX + 3][2];

pii st[NMAX + 3][LOG + 3];

ll dp[NMAX + 3][LOG + 3];

ll get_dp(int l, int r) {
	int k = __lg(r - l + 1);
	return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

pii get(int l, int r) {
	int k = __lg(r - l + 1);
	pii val1 = st[l][k], val2 = st[r - (1 << k) + 1][k];
	return mp(max(val1.fi, val2.fi), min(val1.se, val2.se));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		st[i][0] = {b[i], b[i]};
	}
	for (int j = 1; j <= LOG; j++) 
	for (int i = 1; i + (1 << j) - 1 <= n; i++) {
		st[i][j].fi = max(st[i][j - 1].fi, st[i + (1 << (j - 1))][j - 1].fi);
		st[i][j].se = min(st[i][j - 1].se, st[i + (1 << (j - 1))][j - 1].se);
	}
	for (int i = 1; i < n; i++) a[i] = b[i] - b[i + 1];
	for (int i = 1; i < n; i++) {
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		f[i][1] = max(f[i][1], f[i - 1][0] + abs(a[i]));
		if (a[i] * a[i - 1] > 0) f[i][1] = max(f[i][1], f[i - 1][1] + abs(a[i]));
	}
	for (int i = 1; i <= n; i++) a[i] = b[i] - b[i - 1];
	for (int i = n; i > 1; i--) {
		g[i][0] = max(g[i + 1][0], g[i + 1][1]);
		g[i][1] = max(g[i][1], g[i + 1][0] + abs(a[i]));
		if (a[i] * a[i + 1] > 0) g[i][1] = max(g[i][1], g[i + 1][1] + abs(a[i]));
	}
	cout << max(f[n - 1][0], f[n - 1][1]) << " ";
	
	for (int i = 1; i <= n; i++) 
		dp[i][0] = f[i][0] + g[i + 1][0];
	for (int j = 1; j <= LOG; j++) 
	for (int i = 1; i + (1 << j) - 1 <= n; i++) 
		dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	while (q--) {
		char c; int l, r;
		cin >> c >> l >> r;
		if (l > r) swap(l, r);
		if (c == 'H') cout << get_dp(l, r - 1) << " ";
		else {
			pll temp = get(l, r);
			ll val1 = max(f[l - 1][0], ((l == 1 || b[l - 1] > temp.se) ? 0 : temp.se - b[l - 1] + max(f[l - 2][0], ((l > 2 && b[l - 2] < b[l - 1]) ? f[l - 2][1] : 0))));
			ll val2 = max(g[r + 1][0], ((r == n || b[r + 1] < temp.fi) ? 0 : b[r + 1] - temp.fi + max(g[r + 2][0], ((r < n - 1 && b[r + 1] < b[r + 2]) ? g[r + 2][1] : 0))));
			ll res = temp.fi - temp.se + val1 + val2;
			val1 = max(f[l - 1][0], ((l == 1 || b[l - 1] < temp.fi) ? 0 : b[l - 1] - temp.fi + max(f[l - 2][0], ((l > 2 && b[l - 2] > b[l - 1]) ? f[l - 2][1] : 0))));
			val2 = max(g[r + 1][0], ((r == n || b[r + 1] > temp.se) ? 0 : temp.se - b[r + 1] + max(g[r + 2][0], ((r < n - 1 && b[r + 1] > b[r + 2]) ? g[r + 2][1] : 0))));
			res = max(res, temp.fi - temp.se + val1 + val2);
			cout << res << " ";
		
		}
	}
} // djt