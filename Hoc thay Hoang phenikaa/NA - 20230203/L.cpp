#include <bits/stdc++.h>

#define name ""
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
const ll LINF = 1e12;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k, p, nn, g[400003], nxt[400003][18];

ll dis[200003], a[400003];

bool Disallow[200003], f[200003];

bool check(ll x) {
	int i2 = 1, i3 = 1;
	memset(nxt, 60, sizeof(nxt));
	for (int i = 1; i <= n; i++) {
		while (i2 < n && a[i2 + 1] - a[i] <= x) i2 ++;
		while (i3 < n && a[i3 + 1] - a[i2] <= x) i3 ++;
		nxt[i][0] = g[i3 + 1];
		if (g[i3 + 1] > n) break;
	}
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i <= n; i++) { 
			if (nxt[i][j - 1] > n) nxt[i][j] = nxt[i][j - 1];
			else nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
			if (nxt[i][j] > n) break;
		}
	for (int i = 1; i <= n / 2; i++) {
		int pos = i;
		for (int j = 17; j >= 0; j--) {
			if (p >> j & 1) pos = nxt[pos][j];
			if (pos >= i + n / 2) return true;
		}
	}
	return false;
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> nn >> m >> k >> p;
	for (int i = 1; i <= nn; i++)
		dis[i] = a[i] = 1;
	memset(g, 60, sizeof(g));
	for (int i = 1; i <= m; i++) {
		int c, t; cin >> c >> t;
		Disallow[c] = 1; dis[c] += t;
	}
	for (int i = 1; i <= k; i++) {
		int d; cin >> d;
		f[d] = 1;
	}
	ll cur = 0; n = 0;
	for (int i = 1; i <= nn; i++) {
		if (Disallow[i]) cur += dis[i];
		else {
			a[++ n] += cur; cur = 0;
			if (f[i]) g[n] = n;
		}
	}
	a[n + 1] = cur + a[1];
	g[n + 1] = g[1] + n;
	for (int i = n + 2; i <= 2 * n; i++) {
		a[i] = a[i - n];
		g[i] = g[i - n] + n;
	}
	a[1] = 0;
	n *= 2;
	for (int i = n; i >= 1; i--)
		g[i] = min(g[i], g[i + 1]);
	// for (int i = 1; i <= n; i++)
	// 	cout << i << " " << a[i] << " " << g[i] << '\n';
	for (int i = 2; i <= n; i++)
		a[i] += a[i - 1];
	ll l = 0, r = LINF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}