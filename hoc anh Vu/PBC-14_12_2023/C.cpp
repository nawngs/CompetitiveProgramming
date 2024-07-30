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
const int NMAX = 2e6;
const ll BASE = 2309;
const int LG = 20;

int n, m, MOD, dp[NMAX + 3], f[NMAX + 3], a[NMAX + 3], nnode = 0;

int nxt[10 * NMAX + 3][2], g[10 * NMAX + 3];
 
void add(int x, int val) {
	int cur = 0;
	for (int i = LG; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if (nxt[cur][bit] == -1) nxt[cur][bit] = ++nnode;
		cur = nxt[cur][bit];
		g[cur] = (g[cur] + val) % MOD;
	}
}

ll get(int x, int mx) {
	int cur = 0, res = 0;
	for (int i = LG; i >= 0; i--) {
		int bitx = (x >> i) & 1;
		int bitmx = (mx >> i) & 1;
		if (!bitmx && nxt[cur][bitx ^ 1] != -1) res = (res + g[nxt[cur][bitx ^ 1]]) % MOD;
		if (nxt[cur][bitx ^ bitmx] == -1) return res;
		cur = nxt[cur][bitx ^ bitmx];
	}
	return (res + g[cur]) % MOD;
}

int mul(int a, int b) {
	return 1ll * a * b % MOD;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> MOD;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	memset(nxt, 255, sizeof(nxt));
	for (int i = 0; i <= 2 * m; i++) {
		for (int j = 0; j <= nnode; j++) nxt[j][0] = nxt[j][1] = -1, g[j] = 0;
		nnode = 0;
		add(a[1], 1);
		for (int j = 2; j <= n; j++) {
			int temp = get(a[j], i);
			f[i] = (f[i] + temp) % MOD;
			add(a[j], (temp + 1) % MOD);
		}
	}
	ll res = 0;
	for (ll i = 1; i <= 2 * m; i++) res = (res + mul(i, (f[i] - f[i + 1] + MOD) % MOD)) % MOD;
	cout << res;
}